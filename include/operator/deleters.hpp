#ifndef OPERATOR_DELETERS_HPP
#define OPERATOR_DELETERS_HPP
#include <operator/operation.hpp>

// STL
#include <functional>
#include <type_traits>

namespace Operator
{
  namespace tags
  {
    OPERATOR_CREATE_TAG(DeleteScalar)
    OPERATOR_CREATE_TAG(DeleteArray)
    OPERATOR_CREATE_TAG(CustomDeleter)
  } // namespace tags

  namespace policies
  {
    template <> struct Operator<tags::DeleteScalar>
    {
      template <typename T>
      static void
      operation(T* ptr)
      {
        delete ptr;
      }
    };

    template <> struct Operator<tags::DeleteArray>
    {
      template <typename T>
      static void
      operation(T* ptr)
      {
        delete[] ptr;
      }
    };

    template <> struct Operator<tags::CustomDeleter>
    {
      template <
          typename T,
          typename Deleter,
          typename = std::enable_if_t<std::is_invocable<Deleter, T*>::value>>
      static decltype(auto)
      operation(T* ptr, Deleter&& deleter)
      {
        return std::invoke(deleter, ptr);
      }
    };
  } // namespace policies

  namespace deleters
  {
    template <typename Type>
    static decltype(auto)
    scalar(Type* type)
    {
      return policies::Operator<tags::DeleteScalar>::operation(type);
    }

    template <typename T>
    static decltype(auto)
    array(T* type)
    {
      return policies::Operator<tags::DeleteArray>::operation(type);
    }

    template <typename T, typename Deleter>
    static decltype(auto)
    custom(T* type, Deleter&& deleter)
    {
      return operation<tags::CustomDeleter>(type,
                                            std::forward<Deleter>(deleter));
    }
  } // namespace deleters
} // namespace Operator
#endif // OPERATOR_DELETERS_HPP


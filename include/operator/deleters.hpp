#ifndef OPERATOR_DELETERS_HPP
#define OPERATOR_DELETERS_HPP
#include <operator/operation.hpp>

// STL
#include <functional>

namespace Operator::deleters
{
  template <typename Type, typename... Args>
  static decltype(auto)
  scalar(Type& type, Args&&... args)
  {
    return operation<tags::DeleteScalar>(type, std::forward<Args>(args)...);
  }

  template <typename Type, typename... Args>
  static decltype(auto)
  array(Type& type, Args&&... args)
  {
    return operation<tags::DeleteArray>(type, std::forward<Args>(args)...);
  }

  template <typename Type, typename... Args>
  static decltype(auto)
  custom(Type& type, Args&&... args)
  {
    return operation<tags::CustomDeleter>(type, std::forward<Args>(args)...);
  }
} // namespace Operator::deleters

namespace Operator::policies
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

  template <typename T>
  void
  delete_set_nullptr(T*& ptr)
  {
    delete ptr;
    ptr = nullptr;
  }

  template <> struct Operator<tags::CustomDeleter>
  {
    template <typename T, typename Deleter>
    static decltype(auto)
    operation(T&& ptr, Deleter&& deleter)
    {
      return std::invoke(deleter, ptr);
    }
  };
} // namespace Operator::policies
#endif // OPERATOR_DELETERS_HPP


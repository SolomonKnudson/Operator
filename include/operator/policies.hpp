#ifndef OPERATOR_POLICIES_HPP
#define OPERATOR_POLICIES_HPP
#include <operator/tags.hpp>
#include <operator/util.hpp>

//STL
#include <functional>

namespace Operator::policies
{
  template <typename Tag> struct Operator
  {
  };

  // BEGIN Misc
  template <> struct Operator<tags::NoOp>
  {
    template <typename... Args>
    static void
    operation(Args&&...)
    {
    }
  };
  //END Misc

  // BEGIN Insertions
  // BEGIN Front Insertions
  template <> struct Operator<tags::push_front>
  {
    template <typename Container, typename Value>
    OPERATOR_CREATE_REQUIRES(concepts::HasPushFront<Container, Value>)
    static auto operation(Container&& container, Value&& value)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(util::deref(std::forward<Container>(container))
                         .push_front(std::forward<Value>(value))))
    {
      return util::deref(std::forward<Container>(container))
          .push_front(std::forward<Value>(value));
    }
  };

  template <> struct Operator<tags::emplace_front>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(concepts::HasEmplaceFront<Container, Args...>)
    static auto operation(Container&& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(util::deref(std::forward<Container>(container))
                         .emplace_front(std::forward<Args>(args)...)))
    {
      if constexpr (sizeof...(Args) == 0)
      {
        return util::deref(std::forward<Container>(container)).emplace_front();
      }
      else
      {
        return (util::deref(std::forward<Container>(container))
                    .emplace_front(std::forward<Args>(args)),
                ...);
      }
    }
  };
  //END Front Insertions

  // BEGIN Back Insertions
  template <> struct Operator<tags::push_back>
  {
    template <typename Container, typename Value>
    OPERATOR_CREATE_REQUIRES(concepts::HasPushBack<Container, Value>)
    static auto operation(Container&& container, Value&& value)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(util::deref(std::forward<Container>(container))
                         .push_back(std::forward<Value>(value))))
    {
      return util::deref(std::forward<Container>(container))
          .push_back(std::forward<Value>(value));
    }
  };

  template <> struct Operator<tags::emplace_back>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(concepts::HasEmplaceBack<Container, Args...>)
    static auto operation(Container&& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(util::deref(std::forward<Container>(container))
                         .emplace_back(std::forward<Args>(args)...)))
    {
      if constexpr (sizeof...(Args) == 0)
      {
        return util::deref(std::forward<Container>(container)).emplace_back();
      }
      else
      {
        return (util::deref(std::forward<Container>(container))
                    .emplace_back(std::forward<Args>(args)),
                ...);
      }
    }
  };
  //END Back Insertions
  //END Inserters

  // BEGIN Deleters
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
  //END Deleters
} // namespace Operator::policies
#endif // OPERATOR_POLICIES_HPP

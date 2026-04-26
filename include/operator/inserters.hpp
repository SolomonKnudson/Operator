#ifndef OPERATOR_INSERTERS_HPP
#define OPERATOR_INSERTERS_HPP
#include <operator/operation.hpp>
#include <utility>

namespace Operator::inserters
{
  template <typename Container, typename Value>
  static decltype(auto)
  push_front(Container& container, Value&& value)
  {
    return operation<tags::push_front>(container, std::forward<Value>(value));
  }

  template <typename Container, typename... Args>
  static decltype(auto)
  emplace_front(Container& container, Args&&... args)
  {
    return operation<tags::emplace_front>(container,
                                          std::forward<Args>(args)...);
  }

  template <typename Container, typename Value>
  static decltype(auto)
  push_back(Container& container, Value&& value)
  {
    return operation<tags::push_back>(container, std::forward<Value>(value));
  }

  template <typename Container, typename... Args>
  static decltype(auto)
  emplace_back(Container& container, Args&&... args)
  {
    return operation<tags::emplace_back>(container,
                                         std::forward<Args>(args)...);
  }
} // namespace Operator::inserters

namespace Operator::policies
{
  template <typename Tag> struct Operator;

  // Front insertions
  template <> struct Operator<tags::push_front>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(concepts::HasPushFront<Container, Args...>)
    static auto operation(Container& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(container.push_front(std::forward<Args>(args)...), void()))
    {
      container.push_front(std::forward<Args>(args)...);
    }
  };

  template <> struct Operator<tags::emplace_front>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(concepts::HasEmplaceFront<Container, Args...>)
    static auto operation(Container& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(container.emplace_front(std::forward<Args>(args)...),
                     void()))
    {
      if constexpr (sizeof...(Args) == 0)
      {
        container.emplace_front();
      }
      else
      {
        (container.emplace_front(std::forward<Args>(args)), ...);
      }
    }
  };

  // Back insertions
  template <> struct Operator<tags::push_back>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(concepts::HasPushBack<Container, Args...>)
    static auto operation(Container& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(container.push_back(std::forward<Args>(args)...), void()))
    {
      container.push_back(std::forward<Args>(args)...);
    }
  };

  template <> struct Operator<tags::emplace_back>
  {
    template <typename Container, typename... Args>
    OPERATOR_CREATE_REQUIRES(concepts::HasEmplaceBack<Container, Args...>)
    static auto operation(Container& container, Args&&... args)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(container.emplace_back(std::forward<Args>(args)...),
                     void()))
    {
      if constexpr (sizeof...(Args) == 0)
      {
        container.emplace_back();
      }
      else
      {
        (container.emplace_back(std::forward<Args>(args)), ...);
      }
    }
  };
} // namespace Operator::policies
#endif // OPERATOR_INSERTERS_HPP


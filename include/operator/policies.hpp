#ifndef OPERATOR_POLICIES_HPP
#define OPERATOR_POLICIES_HPP
#include <operator/concepts.hpp>
#include <operator/macros.hpp>
#include <operator/tags.hpp>

// STL
#include <utility>

namespace Operator::policies
{
  template <typename Tag> struct Operator;

  // Front insertions
  template <> struct Operator<tags::push_front>
  {
    template <typename Container, typename... Args>
    OPERATOR_CONCEPT(concepts::HasPushFront<Container, Args...>)
    static auto operation(Container& container, Args&&... args)
        OPERATOR_TRAILING_RETURN(
            decltype(container.push_front(std::forward<Args>(args)...), void()))
    {
      container.push_front(std::forward<Args>(args)...);
    }
  };

  template <> struct Operator<tags::emplace_front>
  {
    template <typename Container, typename... Args>
    OPERATOR_CONCEPT(concepts::HasEmplaceFront<Container, Args...>)
    static auto operation(Container& container, Args&&... args)
        OPERATOR_TRAILING_RETURN(
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
    OPERATOR_CONCEPT(concepts::HasPushBack<Container, Args...>)
    static auto operation(Container& container, Args&&... args)
        OPERATOR_TRAILING_RETURN(
            decltype(container.push_back(std::forward<Args>(args)...), void()))
    {
      container.push_back(std::forward<Args>(args)...);
    }
  };

  template <> struct Operator<tags::emplace_back>
  {
    template <typename Container, typename... Args>
    OPERATOR_CONCEPT(concepts::HasEmplaceBack<Container, Args...>)
    static auto operation(Container& container, Args&&... args)
        OPERATOR_TRAILING_RETURN(
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
#endif // OPERATOR_POLICIES_HPP

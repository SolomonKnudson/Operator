#ifndef OPERATOR_INSERTERS_HPP
#define OPERATOR_INSERTERS_HPP
#include <operator/concepts.hpp>
#include <operator/policies.hpp>
#include <operator/util.hpp>
#include <utility>

namespace Operator
{
  namespace tags
  {
    OPERATOR_CREATE_TAG(push_front);
    OPERATOR_CREATE_TAG(emplace_front);

    OPERATOR_CREATE_TAG(push_back);
    OPERATOR_CREATE_TAG(emplace_back);
  } // namespace tags

  namespace policies
  {
    // Front insertions
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
          return util::deref(std::forward<Container>(container))
              .emplace_front();
        }
        else
        {
          return (util::deref(std::forward<Container>(container))
                      .emplace_front(std::forward<Args>(args)),
                  ...);
        }
      }
    };

    // Back insertions
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
  } // namespace policies

  namespace inserters
  {
    template <typename Container, typename Value>
    static decltype(auto)
    push_front(Container&& container, Value&& value)
    {
      return policies::Operator<tags::push_front>::operation(
          std::forward<Container>(container), std::forward<Value>(value));
    }

    template <typename Container, typename... Args>
    static decltype(auto)
    emplace_front(Container&& container, Args&&... args)
    {
      return policies::Operator<tags::emplace_front>::operation(
          std::forward<Container>(container), std::forward<Args>(args)...);
    }

    template <typename Container, typename Value>
    static decltype(auto)
    push_back(Container&& container, Value&& value)
    {
      return policies::Operator<tags::push_back>::operation(
          std::forward<Container>(container), std::forward<Value>(value));
    }

    template <typename Container, typename... Args>
    static decltype(auto)
    emplace_back(Container&& container, Args&&... args)
    {
      return policies::Operator<tags::emplace_back>::operation(
          std::forward<Container>(container), std::forward<Args>(args)...);
    }
  } // namespace inserters
} // namespace Operator
#endif // OPERATOR_INSERTERS_HPP


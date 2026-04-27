#ifndef OPERATOR_INSERTERS_HPP
#define OPERATOR_INSERTERS_HPP
#include <operator/policies.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

//STL
#include <utility>

namespace Operator::inserters
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
} // namespace Operator::inserters
#endif // OPERATOR_INSERTERS_HPP


#ifndef OPERATOR_HPP
#define OPERATOR_HPP
#include <operator/concepts.hpp>
#include <operator/policies.hpp>
#include <operator/tags.hpp>
#include <operator/util.hpp>

namespace Operator
{
  template <typename Tag, typename Container, typename... Args>
  static auto
  operation(Container& container, Args&&... args)
  {
    return policies::Operator<Tag>::operation(container,
                                              std::forward<Args>(args)...);
  }

  template <typename Tag, typename Container, typename... Args>
  static auto
  insert(Container& container, Args&&... args)
  {
    return operation<Tag>(container, std::forward<Args>(args)...);
  }
} // namespace Operator
#endif // OPERATOR_HPP

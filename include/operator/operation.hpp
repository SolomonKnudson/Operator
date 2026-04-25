#ifndef OPERATOR_OPERATIONS_HPP
#define OPERATOR_OPERATIONS_HPP
#include <operator/policies.hpp>
#include <operator/tags.hpp>

namespace Operator::operations
{
  template <typename Tag, typename Container, typename... Args>
  static auto
  operation(Container& container, Args&&... args)
  {
    return policies::Operator<Tag>::operation(container,
                                              std::forward<Args>(args)...);
  }
} // namespace Operator::operations
#endif // OPERATOR_OPERATIONS_HPP


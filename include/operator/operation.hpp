#ifndef OPERATOR_OPERATION_HPP
#define OPERATOR_OPERATION_HPP
#include <operator/policies.hpp>
#include <operator/tags.hpp>

namespace Operator
{
  template <typename Tag, typename Container, typename... Args>
  static decltype(auto)
  operation(Container& container, Args&&... args)
  {
    return policies::Operator<Tag>::operation(container,
                                              std::forward<Args>(args)...);
  }
} // namespace Operator
#endif // OPERATOR_OPERATION_HPP


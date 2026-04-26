#ifndef OPERATOR_OPERATION_HPP
#define OPERATOR_OPERATION_HPP
#include <operator/policies.hpp>

#include <utility>
namespace Operator
{
  template <typename Tag, typename... Args>
  static decltype(auto)
  operation(Args&&... args)
  {
    return policies::Operator<Tag>::operation(std::forward<Args>(args)...);
  }
} // namespace Operator
#endif // OPERATOR_OPERATION_HPP


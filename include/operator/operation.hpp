#ifndef OPERATOR_OPERATION_HPP
#define OPERATOR_OPERATION_HPP
#include <operator/policies.hpp>
#include <operator/tags.hpp>

#include <utility>
namespace Operator
{
  template <typename Tag, typename Type, typename... Args>
  static decltype(auto)
  operation(Type&& type, Args&&... args)
  {
    return policies::Operator<Tag>::operation(std::forward<Type>(type),
                                              std::forward<Args>(args)...);
  }
} // namespace Operator
#endif // OPERATOR_OPERATION_HPP


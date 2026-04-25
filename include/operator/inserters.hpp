#ifndef OPERATOR_INSERTERS_HPP
#define OPERATOR_INSERTERS_HPP
#include <operator/operation.hpp>

namespace Operator::operations::inserters
{
  template <typename Container, typename... Args>
  static auto
  push_front(Container& container, Args&&... args)
  {
    return operation<tags::push_front>(container, std::forward<Args>(args)...);
  }

  template <typename Container, typename... Args>
  static auto
  emplace_front(Container& container, Args&&... args)
  {
    return operation<tags::emplace_front>(container,
                                          std::forward<Args>(args)...);
  }

  template <typename Container, typename... Args>
  static auto
  push_back(Container& container, Args&&... args)
  {
    return operation<tags::push_back>(container, std::forward<Args>(args)...);
  }

  template <typename Container, typename... Args>
  static auto
  emplace_back(Container& container, Args&&... args)
  {
    return operation<tags::emplace_back>(container,
                                         std::forward<Args>(args)...);
  }
} // namespace Operator::operations::inserters
#endif // OPERATOR_INSERTER_HPP


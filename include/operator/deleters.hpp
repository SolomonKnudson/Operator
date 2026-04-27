#ifndef OPERATOR_DELETERS_HPP
#define OPERATOR_DELETERS_HPP
#include <operator/policies.hpp>

// STL
#include <utility>

namespace Operator::deleters
{
  template <typename Type>
  static decltype(auto)
  scalar(Type* type)
  {
    return policies::Operator<tags::DeleteScalar>::operation(type);
  }

  template <typename T>
  static decltype(auto)
  array(T* type)
  {
    return policies::Operator<tags::DeleteArray>::operation(type);
  }

  template <typename T, typename Deleter>
  static decltype(auto)
  custom(T* type, Deleter&& deleter)
  {
    return policies::Operator<tags::CustomDeleter>::operation(
        type, std::forward<Deleter>(deleter));
  }
} // namespace Operator::deleters
#endif // OPERATOR_DELETERS_HPP


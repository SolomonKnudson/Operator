#ifndef OPERATOR_POLICIES_HPP
#define OPERATOR_POLICIES_HPP
#include <operator/tags.hpp>

namespace Operator::policies
{
  template <typename Tag> struct Operator
  {
  };

  template <> struct Operator<tags::NoOp>
  {
    template <typename... Args>
    static void
    operation(Args&&...)
    {
    }
  };
} // namespace Operator::policies
#endif // OPERATOR_POLICIES_HPP

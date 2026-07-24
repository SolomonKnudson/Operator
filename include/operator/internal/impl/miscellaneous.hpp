#ifndef OPERATOR_INTERNAL_MISCELLANEOUS_IMPLS_HPP
#define OPERATOR_INTERNAL_MISCELLANEOUS_IMPLS_HPP
#include <operator/builtin.hpp>
#include <operator/impl.hpp>
#include <operator/util.hpp>

namespace Operator
{
  template <> struct Impl<builtin::NoOp>
  {
    template <typename... Args>
    static void
    invoke(Args&&...)
    {
    }
  };
} // namespace Operator
#endif // OPERATOR_INTERNAL_MISCELLANEOUS_IMPLS_HPP

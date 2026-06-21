#ifndef OPERATOR_BUILTIN_TAGS_HPP
#define OPERATOR_BUILTIN_TAGS_HPP
#include <operator/macros.hpp>

namespace Operator::builtin
{
  // Insertions
  OPERATOR_CREATE_IMPL_TAG(push_front);
  OPERATOR_CREATE_IMPL_TAG(emplace_front);

  // Back Insertions
  OPERATOR_CREATE_IMPL_TAG(push_back);
  OPERATOR_CREATE_IMPL_TAG(emplace_back);

  // Invoke
  OPERATOR_CREATE_IMPL_TAG(Invoke);
  OPERATOR_CREATE_IMPL_TAG(FoldInvoke);

  // Misc
  OPERATOR_CREATE_IMPL_TAG(DisplayContainer);
  OPERATOR_CREATE_IMPL_TAG(NoOp);
} // namespace Operator::builtin
#endif // OPERATOR_BUILTIN_TAGS_HPP

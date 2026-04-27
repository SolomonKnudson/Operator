#ifndef OPERATOR_TAGS_HPP
#define OPERATOR_TAGS_HPP
#include <operator/macros.hpp>

namespace Operator::tags
{
  /*  Tags
   *  struct name
   *  {
   *  };
   *  OPERATOR_CREATE_TAG(name) example output
   */
  // Insertions
  // Front Insertions
  OPERATOR_CREATE_TAG(push_front);
  OPERATOR_CREATE_TAG(emplace_front);
  //END Front insertions

  // Back Insertions
  OPERATOR_CREATE_TAG(push_back);
  OPERATOR_CREATE_TAG(emplace_back);
  //END Back Insertions
  //END Insertions

  // Deleters
  OPERATOR_CREATE_TAG(DeleteScalar)
  OPERATOR_CREATE_TAG(DeleteArray)
  OPERATOR_CREATE_TAG(CustomDeleter)

  // Misc
  OPERATOR_CREATE_TAG(NoOp)
  //END Misc
} // namespace Operator::tags
#endif // OPERATOR_TAGS_HPP

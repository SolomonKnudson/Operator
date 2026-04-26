#ifndef OPERATOR_TAGS_HPP
#define OPERATOR_TAGS_HPP
#include <operator/macros.hpp>

namespace Operator::tags
{
  /*  Tags
    *  struct name
    *  {
    *  };
    *  CREATE_TAG example output
    */
  // Insertions
  OPERATOR_CREATE_TAG(push_front);
  OPERATOR_CREATE_TAG(emplace_front);

  OPERATOR_CREATE_TAG(push_back);
  OPERATOR_CREATE_TAG(emplace_back);

  // Deleters
  OPERATOR_CREATE_TAG(DeleteScalar)
  OPERATOR_CREATE_TAG(DeleteArray)
  OPERATOR_CREATE_TAG(CustomDeleter)
} // namespace Operator::tags
#endif // OPERATOR_TAGS_HPP

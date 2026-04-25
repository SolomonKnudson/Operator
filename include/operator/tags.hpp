#ifndef OPERATOR_TAGS_HPP
#define OPERATOR_TAGS_HPP
#include <operator/macros.hpp>

namespace Operator
{
  namespace tags
  {
    template <typename Tag> inline constexpr Tag tag{};

    /*  Tags
    *  struct name
    *  {
    *  };
    *  CREATE_TAG example output
    */
    OPERATOR_CREATE_TAG(push_front);
    OPERATOR_CREATE_TAG(emplace_front);

    OPERATOR_CREATE_TAG(push_back);
    OPERATOR_CREATE_TAG(emplace_back);
  } // namespace tags
} // namespace Operator
#endif // OPERATOR_TAGS_HPP

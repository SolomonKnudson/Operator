#ifndef INSERTER_TAGS
#define INSERTER_TAGS
#include <inserter/macros.hpp>

namespace inserter
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
    INSERTER_CREATE_TAG(push_front);
    INSERTER_CREATE_TAG(emplace_front);

    INSERTER_CREATE_TAG(push_back);
    INSERTER_CREATE_TAG(emplace_back);
  } // namespace tags
} // namespace inserter
#endif

#ifndef INSERTER_CONCEPTS
#define INSERTER_CONCEPTS
#if defined(__cpp_concepts)
#include <inserter/macros.hpp>

namespace inserter
{
  namespace concepts
  {
    /*  HasInsertionOp Concepts
       *  template <typename Container, typename... Args>
       *  concept HasPushFront = requires(Container container, Args... args)
       *  {
       *    container.push_front(args...);
       *  };
       *  CREATE_HAS_INSERTION_OP_CONCEPT example output
       */
    //Front insertions
    INSERTER_CREATE_HAS_INSERTION_OP_CONCEPT(PushFront, push_front);
    INSERTER_CREATE_HAS_INSERTION_OP_CONCEPT(EmplaceFront, emplace_front);

    //Back insertions
    INSERTER_CREATE_HAS_INSERTION_OP_CONCEPT(EmplaceBack, emplace_back);
    INSERTER_CREATE_HAS_INSERTION_OP_CONCEPT(PushBack, push_back);
  } // namespace concepts
} // namespace inserter
#endif
#endif // INSERTER_CONCEPTS

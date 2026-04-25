#ifndef OPERATOR_CONCEPTS_HPP
#define OPERATOR_CONCEPTS_HPP
#if defined(__cpp_concepts)
#include <operator/macros.hpp>

namespace Operator::concepts
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
  OPERATOR_CREATE_HAS_INSERTION_OP_CONCEPT(PushFront, push_front);
  OPERATOR_CREATE_HAS_INSERTION_OP_CONCEPT(EmplaceFront, emplace_front);

  //Back insertions
  OPERATOR_CREATE_HAS_INSERTION_OP_CONCEPT(EmplaceBack, emplace_back);
  OPERATOR_CREATE_HAS_INSERTION_OP_CONCEPT(PushBack, push_back);
} // namespace concepts
} // namespace Operator
#endif // __cpp_concepts
#endif // OPERATOR_CONCEPTS_HPP

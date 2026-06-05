#ifndef OPERATOR_CONCEPTS_HPP
#define OPERATOR_CONCEPTS_HPP
#if defined(__cpp_concepts)
#include <operator/internal/macros.hpp>
#include <operator/util.hpp>

namespace Operator::internal::concepts
{
  /*  HasMethod Concepts
   *  template <typename Type, typename... Args>
   *  concept Has##operation =
   *  OPERATOR_CREATE_REQUIRES((Type&& type, Args&&... args) {
   *    (util::deref(std::forward<Type>(type)).method(std::forward<Args>(args)),
   *     ...);
   *  }); 
   *  OPERATOR_CREATE_HAS_FOLD_METHOD_CONCEPT(operation, method) example output
   */

  //Front insertions
  OPERATOR_CREATE_HAS_FOLD_METHOD_CONCEPT(PushFront, push_front);
  OPERATOR_CREATE_HAS_FOLD_METHOD_CONCEPT(EmplaceFront, emplace_front);

  //Back insertions
  OPERATOR_CREATE_HAS_FOLD_METHOD_CONCEPT(PushBack, push_back);
  OPERATOR_CREATE_HAS_FOLD_METHOD_CONCEPT(EmplaceBack, emplace_back);

  //IOStream
  template <typename Stream, typename LHS>
  concept HasStdStreamInsertion =
      OPERATOR_CREATE_REQUIRES((Stream& stream, LHS&& lhs) {
        stream >> util::deref(std::forward<LHS>(lhs));
      });

  template <typename Stream, typename... Args>
  concept HasStdStreamOutsertion =
      OPERATOR_CREATE_REQUIRES((Stream& stream, Args&&... args) {
        ((stream << std::forward<Args>(args)), ...);
      });
} // namespace Operator::internal::concepts
#endif // __cpp_concepts
#endif // OPERATOR_CONCEPTS_HPP

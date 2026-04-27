#ifndef OPERATOR_TYPE_TRAITS_HPP
#define OPERATOR_TYPE_TRAITS_HPP
#include <type_traits>

namespace Operator::type_traits
{
  template <typename T> using remove_reference = std::remove_reference_t<T>;

  template <typename, typename = void> struct can_deref : std::false_type
  {
  };

  template <typename T>
  struct can_deref<T, std::void_t<decltype(*std::declval<T&>())>>
    : std::true_type
  {
  };

  template <typename T> constexpr bool can_deref_v{can_deref<T>::value};
} // namespace Operator::type_traits
#endif

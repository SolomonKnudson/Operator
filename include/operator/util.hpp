#ifndef OPERATOR_UTIL_HPP
#define OPERATOR_UTIL_HPP
#include <operator/macros.hpp>

// 3rd Party
// STL
#include <utility>
// Me :)
#include <STLConvenience/type_traits.hpp>

namespace Operator
{
  namespace util
  {
    template <typename T>
    constexpr decltype(auto)
    deref(T&& type)
    {
      if constexpr (STLC::type_traits::can_deref_v<T>)
      {
        return *type;
      }
      else
      {
        return std::forward<T>(type);
      }
    }
  } // namespace util
} // namespace Operator
#endif // OPERATOR_UTIL_HPP

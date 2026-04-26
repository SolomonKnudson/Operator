#ifndef OPERATOR_UTIL_HPP
#define OPERATOR_UTIL_HPP
#include <operator/macros.hpp>

// STL
#include <type_traits>
#include <utility>

namespace Operator
{
  namespace util
  {
    template <typename T> using remove_reference = std::remove_reference_t<T>;
    template <typename T>
    using remove_pointer = std::remove_pointer_t<remove_reference<T>>;

    template <typename T>
    using is_pointer = std::is_pointer<remove_reference<T>>;
    template <typename T> constexpr bool is_pointer_v{is_pointer<T>::value};

    template <typename T>
    constexpr decltype(auto)
    deref(T&& type)
    {
      if constexpr (is_pointer_v<T>)
      {
        return *type;
      }
      else
      {
        return std::forward<T>(type);
      }
    }

    template <typename Container, typename Printer>
    OPERATOR_CREATE_REQUIRES(requires(Container&& container) {
      deref(container).cbegin();
      deref(container).cend();
    })
    static auto display(const Container& container, Printer&& print)
        OPERATOR_CREATE_TRAILING_RETURN(decltype(deref(container).cbegin(),
                                                 deref(container).cend(),
                                                 void()))
    {
      for (auto it{deref(container).cbegin()}, end{deref(container).cend()};
           it != end;
           ++it)
      {
        print(std::forward<decltype(*it)>(*it));
      }
    }
  } // namespace util
} // namespace Operator
#endif // OPERATOR_UTIL_HPP

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
    template <typename T> using remove_pointer = std::remove_pointer_t<T>;

    template <typename Container, typename Printer>
    OPERATOR_CREATE_REQUIRES(requires(Container& container) {
      container.cbegin();
      container.cend();
    })
    static auto display(const Container& container, Printer&& print)
        OPERATOR_CREATE_TRAILING_RETURN(decltype(container.cbegin(),
                                                 container.cend(),
                                                 void()))
    {
      for (auto it{container.cbegin()}, end{container.cend()}; it != end; ++it)
      {
        print(std::forward<decltype(*it)>(*it));
      }
    }
  } // namespace util
} // namespace Operator
#endif // OPERATOR_UTIL_HPP

#ifndef OPERATOR_UTIL_HPP
#define OPERATOR_UTIL_HPP
#include <functional>
#include <operator/macros.hpp>

// 3rd party
#include <iostream>

namespace Operator
{
  namespace util
  {
    template <typename Container,
              typename Printer =
                  std::function<void(typename Container::value_type&& value)>>
    OPERATOR_CONCEPT(requires(Container& container) {
      container.cbegin();
      container.cend();
    })
    static auto display(
        const Container& container,
        const Printer& print = [](typename Container::value_type&& value)
        { std::cout << value << " "; })
        OPERATOR_TRAILING_RETURN(decltype(container.cbegin(),
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

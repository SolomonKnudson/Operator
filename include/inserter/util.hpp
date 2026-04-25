#ifndef INSERTER_UTIL_HPP
#define INSERTER_UTIL_HPP
#include <functional>
#include <inserter/macros.hpp>

// 3rd party
#include <iostream>

namespace inserter
{
  namespace util
  {
    template <typename Container,
              typename Printer = std::function<
                  void(const typename Container::value_type& value)>>
    INSERTER_CONCEPT(requires(Container& container) {
      container.cbegin();
      container.cend();
    })
    static auto display(
        const Container& container,
        const Printer& print = [](const typename Container::value_type& value)
        { std::cout << value << " "; })
        INSERTER_TRAILING_RETURN(decltype(container.cbegin(),
                                          container.cend(),
                                          void()))
    {
      for (auto it{container.cbegin()}, end{container.cend()}; it != end; ++it)
      {
        print(*it);
      }
    }
  } // namespace util
} // namespace inserter
#endif

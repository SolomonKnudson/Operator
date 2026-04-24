#ifndef INSERTER_UTIL_HPP
#define INSERTER_UTIL_HPP
#include <inserter/macros.hpp>

// 3rd party
#include <iostream>

namespace inserter
{
  namespace util
  {
    template <typename Container>
    INSERTER_CONCEPT(
        requires(Container& container) {
          container.begin();
          container.end();
        } &&
        requires(std::ostream& out, typename Container::value_type value) {
          { out << value } -> std::same_as<std::ostream&>;
        })
    static auto display(const Container& container,
                        const std::string& separator = "\n")
        INSERTER_TRAILING_RETURN(container.cbegin(),
                                 container.cend(),
                                 std::declval<std::ostream&>()
                                     << *std::begin(container),
                                 void())
    {
      auto it{container.begin()};
      auto end{container.end()};

      if (it == end)
      {
        return;
      }

      std::cout << *it;
      ++it;

      for (; it != end; ++it)
      {
        std::cout << separator << *it;
      }

      if (separator != "\n")
      {
        std::cout << '\n';
      }
    }
  } // namespace util
} // namespace inserter
#endif

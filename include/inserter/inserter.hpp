#ifndef INSERTER_HPP
#define INSERTER_HPP
#include <inserter/concepts.hpp>
#include <inserter/policies.hpp>
#include <inserter/tags.hpp>
#include <inserter/util.hpp>

namespace inserter
{
  template <typename Container, typename Tag, typename... Args>
  static void
  insert(Container& container, const Tag&, Args&&... args)
  {
    policies::Inserter<Tag>::insert(container, std::forward<Args>(args)...);
  }
} // namespace inserter
#endif // INSERTER_HPP

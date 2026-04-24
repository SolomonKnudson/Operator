#ifndef INSERTER_POLICIES
#define INSERTER_POLICIES
#include <inserter/concepts.hpp>
#include <inserter/macros.hpp>
#include <inserter/tags.hpp>

// STL
#include <utility>

namespace inserter
{
  namespace policies
  {
    template <typename Tag> struct Inserter
    {
    };

    // Front insertions
    template <> struct Inserter<tags::push_front>
    {
      template <typename Container, typename... Args>
      INSERTER_CONCEPT(concepts::HasPushFront<Container, Args...>)
      static auto insert(Container& container, Args&&... args)
          INSERTER_TRAILING_RETURN(
              container.push_front(std::forward<Args>(args)...), void())
      {
        container.push_front(std::forward<Args>(args)...);
      }
    };

    template <> struct Inserter<tags::emplace_front>
    {
      template <typename Container, typename... Args>
      INSERTER_CONCEPT(concepts::HasEmplaceFront<Container, Args...>)
      static auto insert(Container& container, Args&&... args)
          INSERTER_TRAILING_RETURN(
              container.emplace_front(std::forward<Args>(args)...), void())
      {
        (container.emplace_front(std::forward<Args>(args)), ...);
      }
    };

    // Back insertions
    template <> struct Inserter<tags::push_back>
    {
      template <typename Container, typename... Args>
      INSERTER_CONCEPT(concepts::HasPushBack<Container, Args...>)
      static auto insert(Container& container, Args&&... args)
          INSERTER_TRAILING_RETURN(
              container.push_back(std::forward<Args>(args)...), void())
      {
        container.push_back(std::forward<Args>(args)...);
      }
    };

    template <> struct Inserter<tags::emplace_back>
    {
      template <typename Container, typename... Args>
      INSERTER_CONCEPT(concepts::HasEmplaceBack<Container, Args...>)
      static auto insert(Container& container, Args&&... args)
          INSERTER_TRAILING_RETURN(
              container.emplace_back(std::forward<Args>(args)...), void())
      {
        (container.emplace_back(std::forward<Args>(args)), ...);
      }
    };
  } // namespace policies
} // namespace inserter
#endif

#include <inserter/inserter.hpp>

// STL
#include <list>
#include <string>
#include <vector>

INSERTER_CREATE_TAG(NoOp);

template <> struct inserter::policies::Inserter<NoOp>
{
  template <typename... Args>
  static void
  insert(Args&&... args)
  {
  }
};

int
main(int argc, char* argv[])
{
  using namespace inserter;
  using namespace inserter::tags;
  using namespace inserter::policies;

  std::list<int> test{};
  // std::vector<int> test{};
  // std::vector<std::pair<int, int>> test{};

  insert(test, tag<emplace_back>, 17, 43, 50, 23, 99);

  std::string separator{", "};
  inserter::util::display(test, [](int x) { std::cout << x << " "; });
  return 0;
}


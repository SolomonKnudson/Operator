#include <operator/operator.hpp>

// STL
#include <list>
#include <string>
#include <vector>

OPERATOR_CREATE_TAG(NoOp);

template <> struct Operator::policies::Operator<NoOp>
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
  using namespace Operator;
  using namespace Operator::operations;
  using namespace Operator::tags;
  using namespace Operator::policies;

  std::list<int> test{};
  // std::vector<int> test{};
  // std::vector<std::pair<int, int>> test{};

  operation<emplace_back>(test, 17, 43, 50, 23, 99);
  // inserters::emplace_back(test, 17, 43, 50, 23, 99);

  std::string separator{", "};
  util::display(test, [](int x) { std::cout << x << " "; });
  return 0;
}


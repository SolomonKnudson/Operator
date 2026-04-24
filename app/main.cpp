#include <inserter/inserter.hpp>
#include <list>
#include <vector>

int
main(int argc, char* argv[])
{
  // std::list<int> test{};
  std::vector<int> test{};

  inserter::insert(test, inserter::tags::tag<inserter::tags::emplace_back>);

  inserter::util::display(test, ", ");
  return 0;
}


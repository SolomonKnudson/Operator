#include <inserter/inserter.hpp>
#include <vector>

int
main(int argc, char* argv[])
{
  std::vector<int> test{};

  inserter::insert(
      test, inserter::tags::tag<inserter::tags::emplace_back>, 17, 20);

  inserter::util::display(test, ", ");
  return 0;
}


#include <operator/operator.hpp>

// STL
#include <iostream>
#include <list>
#include <string>

OPERATOR_CREATE_TAG(Test);
template <> struct Operator::policies::Operator<Test>
{
  template <typename... Args>
  static void
  operation(Args&&...)
  {
  }
};

int
main(int argc, char* argv[])
{
  using namespace Operator;
  using namespace Operator::tags;
  using namespace Operator::policies;

  std::list<int> test{};
  // std::vector<int> test{};
  // std::vector<std::pair<int, int>> test{};

  // leaks atm
  auto delete_single_test{new int{100}};
  auto delete_array_test{new int[10]{}};
  // auto well{inserters::emplace_front(test, 20, 54, 50)};
  auto ref{operation<emplace_back>(&test, 17)};
  // std::cout << "list<int>::emplace_front(): " << well << '\n';
  std::cout << "list<int>::emplace_front(): " << ref << '\n';
  // operation<DeleteSingle>(delete_single_test);
  // operation<DeleteArray>(delete_array_test);

  std::cout << "Before deleter: " << *delete_single_test << '\n';
  // operation<CustomDeleter>(
  //     delete_single_test,
  //     delete_set_nullptr<util::remove_pointer<decltype(delete_single_test)>>);

  if (delete_single_test)
  {
    std::cout << "After deleter: " << *delete_single_test << '\n';
  }
  operation<tags::emplace_front>(std::list<int>{}, 17, 43, 50, 23, 99);
  operation<Test>(test, 17, 43, 50, 23, 99);
  // inserters::emplace_back(test, 17, 43, 50, 23, 99);

  std::string separator{", "};
  util::display(test, [](int x) { std::cout << x << ' '; });
  return 0;
}


#include <operator/operator.hpp>

// STL
#include <iostream>
#include <list>

OPERATOR_CREATE_IMPL_TAG(Test);
template <> struct Operator::Impl<Test>
{
  template <typename... Args>
  static void
  invoke(Args&&... args)
  {
  }
};

// namespace Inserter
// {
//   template <typename Container, typename... Args>
//   decltype(auto)
//   push_front(Container&& container, Args&&... args)
//   {
//     Operator::operation<Operator::builtin::push_front>(
//         std::forward<Container>(container), std::forward<Args>(args)...);
//   };
//
//   template <typename Container, typename... Args>
//   decltype(auto)
//   emplace_front(Container&& container, Args&&... args)
//   {
//     Operator::operation<Operator::builtin::emplace_front>(
//         std::forward<Container>(container), std::forward<Args>(args)...);
//   };
//
//   template <typename Container, typename... Args>
//   decltype(auto)
//   push_back(Container&& container, Args&&... args)
//   {
//     Operator::operation<Operator::builtin::push_back>(
//         std::forward<Container>(container), std::forward<Args>(args)...);
//   };
//
//   template <typename Container, typename... Args>
//   decltype(auto)
//   emplace_back(Container&& container, Args&&... args)
//   {
//     Operator::operation<Operator::builtin::emplace_back>(
//         std::forward<Container>(container), std::forward<Args>(args)...);
//   };
// }; // namespace Inserter

int
main(int argc, char* argv[])
{
  using namespace Operator;
  using namespace Operator::builtin;

  std::list<int> test{};
  //std::vector<int> test{};
  // std::vector<std::pair<int, int>> test{};

  auto well{operation<emplace_front>(&test, 20, 16)};
  auto ref{operation<emplace_back>(&test, 17, 90)};

  std::string test_string{};
  int test_int{};

  const std::string const_string{"test"};

  // Assert check
  // operation<cin>();
  // operation<cout>();

  // operation<push_back>(test);
  // operation<push_front>(&test);

  operation<push_back>(test, 999, 444);
  operation<push_front>(&test, 0, 4);

  operation<NoOp>(&test, 17, 43, 50, 23, 99);
  operation<Test>(17, 43, 50, 23, 99);

  operation<Invoke>(
      // NOTE: Impl:Invoke will not handle arg pack
      [](const auto... elem) {},
      90,
      200,
      40,
      50);

  operation<FoldInvoke>(
      // NOTE: Impl:FoldInvoke will handle arg pack
      [](const auto& elem) {},
      90,
      200,
      40,
      50);

  operation<Invoke>(
      // NOTE: Impl:Invoke/FoldInvoke must have
      // template functions passed as forwarding lambdas
      [](auto&& container)
      {
        return util::display_container(
            std::forward<decltype(container)>(container),
            [](const auto& elem) {},
            "operation<Invoke>(util::display, container): ");
      },
      &test);

  operation<DisplayContainer>(
      test,
      [](const auto& elem) {},
      "operation<DisplayContainer>(container, printer): ");

  util::display_container(
      &test,
      [](const auto& elem) {},
      "util::display_container(container, printer): ");

  return 0;
}

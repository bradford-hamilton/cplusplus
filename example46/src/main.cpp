#include <iostream>
#include <vector>

/*

Lambdas:
- Prior to lambdas we only had function objects and function pointers
- Compiler generates unnamed function objects behind the scenes from your lambdas

Structure:
capture list    parameter list                              body
[]              ()              -> return_type specifiers   {};

*/

void print_if(std::vector<int> nums, bool (*predicate) (int));

int main() {
  // ------------------------------- Stateless lambda ---------------------------------

  // Create and execute a lambda
  []() { std::cout << "Heyo" << std::endl; }();

  // Store a lambda in a variable that takes a parameter
  auto l = [](std::string msg){ std::cout << msg << std::endl; };
  l("neato burrito");
  l("lambdas are ok");

  // Store a lambda in a variable that takes a parameter and returns something
  auto l2 = [](int x, int y) -> int { return x + y; };
  std::cout << l2(1, 2) << std::endl;
  std::cout << l2(11, 34) << std::endl;

  // You can also use reference parameters as well as pointers for these
  // parameters so that the lambda can mutate them, for example instead
  // of a return value.

  // Using auto for the parameter type
  int num1 {10};
  double num2 {20.654};

  auto l3 = [](auto x){ std::cout << x << std::endl; };
  l3(num1);
  l3(num2);

  // Example of a lambda using predicates
  std::vector<int> nums {1, 2, 3, 4, 5};
  print_if(nums, [] (auto x) { return x%2 == 0; });

  std::cout << "------------------------------------------------------" << std::endl;
  // ------------------------------- Stateful lambdas -------------------------------
  // Capture (const unless stated "mutable") information from environment.
  // When the compiler generates it's unnamed class/function, it will add constructor
  // initializers with the name and value of the captured vars.
  int y {100};
  [y](int x) { std::cout << x + y << std::endl; }(10);

  // Default captures:
  // [=]
  // [&]
  // [this]

  // If you need to be able to make a change to x within the lambda,
  // you can do the following. Remeber that x was COPIED here, and only once
  // so you can use this like a closure counter.
  std::cout << "------------------------------------------------------" << std::endl;
  int x {100};
  auto l4 = [x]() mutable {
    x += 100;
    std::cout << "x inside lambda closure: " << x << std::endl;
  };

  l4();
  std::cout << "outer x: " << x << std::endl;
  l4();
  std::cout << "outer x: " << x << std::endl;
  l4();
  std::cout << "outer x: " << x << std::endl;

  /*

    x inside lambda closure: 200
    outer x: 100
    x inside lambda closure: 300
    outer x: 100
    x inside lambda closure: 400
    outer x: 100

  */

  // Similar example to above but capturing by reference
  std::cout << "------------------------------------------------------" << std::endl;
  int x1 {100};
  auto l5 = [&x1]() mutable {
    x1 += 100;
    std::cout << "x1 inside lambda closure: " << x1 << std::endl;
  };

  l5();
  std::cout << "outer x1: " << x1 << std::endl;
  l5();
  std::cout << "outer x1: " << x1 << std::endl;
  l5();
  std::cout << "outer x1: " << x1 << std::endl;

  /*

    x1 inside lambda closure: 200
    outer x1: 200
    x1 inside lambda closure: 300
    outer x1: 300
    x1 inside lambda closure: 400
    outer x1: 400

  */

  // Similar example using default capture with [&]
  std::cout << "------------------------------------------------------" << std::endl;
  int x2 {100};
  int y2 {100};
  int z2 {100};

  auto l6 = [&]() mutable {
    x2 += 100;
    y2 += 100;
    z2 += 100;
    std::cout << "x2 inside lambda closure: " << x2 << std::endl;
    std::cout << "y2 inside lambda closure: " << y2 << std::endl;
    std::cout << "z2 inside lambda closure: " << z2 << std::endl;
  };

  l6();
  std::cout << "outer x2: " << x2 << std::endl;
  std::cout << "outer y2: " << y2 << std::endl;
  std::cout << "outer z2: " << z2 << std::endl;
  l6();
  std::cout << "outer x2: " << x2 << std::endl;
  std::cout << "outer y2: " << y2 << std::endl;
  std::cout << "outer z2: " << z2 << std::endl;
  l6();
  std::cout << "outer x2: " << x2 << std::endl;
  std::cout << "outer y2: " << y2 << std::endl;
  std::cout << "outer z2: " << z2 << std::endl;

  return 0;
}

void print_if(std::vector<int> nums, bool (*predicate) (int)) {
  for (int i: nums) {
    if (predicate(i)) {
      std::cout << i << std::endl;
    }
  }
}

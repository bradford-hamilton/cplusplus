#include <iostream>
#include <exception>

/*

Exception Handling general best practice:
- User-defined exceptions
- We can create exception classes and throw instnaces of those classes
- Throw an object not a primitive type
- Throw an object by value
- Catch an object by reference (or const reference)
--------------------------------------------------------------------------------------
- You can throw class level exceptions - member methods work the same as we've learned
- We can also throw in a constructor but remember constructors do not return anything.
- Do NOT throw an exception in destructors! They are marked noexcept.
--------------------------------------------------------------------------------------
- In C++ standard library, std::exception is the base class in which we can extend.
  All subclasses must implement the what() virtual function.

virtual const char *what() const noexcept;

*/

class DivideByZeroException {};
class NegativeValueException {};

double calculate_mpg_with_2_diff_exceptions(int miles, int gallons) {
  if (gallons == 0) {
    throw DivideByZeroException();
  }
  if (miles < 0 || gallons < 0) {
    throw NegativeValueException();
  }
  return static_cast<double>(miles) / gallons;
}

// User defined exception inheriting from std lib's std::exception
class IllegalBalanceException: public std::exception {
public:
  IllegalBalanceException() noexcept = default;
  ~IllegalBalanceException() = default;
  virtual const char *what() const noexcept {
    return "Illegal balance exception";
  }
};

int main() {
  int miles {0};
  int gallons {0};
  double mpg;
  
  // Divide by zero exception
  try {
    mpg = calculate_mpg_with_2_diff_exceptions(miles, gallons);
    std::cout << "Average: " << mpg << std::endl;
  } catch(const DivideByZeroException &ex) {
    std::cout << "Divide by zero exception" << std::endl;
  } catch(const NegativeValueException &ex) {
    std::cout << "Negative value exception" << std::endl;
  } catch(...) { // Catch all (no access to &ex)
    std::cout << "Any other exception" << std::endl;
  }

  // Negative value exception
  try {
    miles = -1;
    gallons = 5;
    mpg = calculate_mpg_with_2_diff_exceptions(miles, gallons);
    std::cout << "Average: " << mpg << std::endl;
  } catch(const DivideByZeroException &ex) {
    std::cout << "Divide by zero exception" << std::endl;
  } catch(const NegativeValueException &ex) {
    std::cout << "Negative value exception" << std::endl;
  } catch(...) { // Catch all (no access to &ex)
    std::cout << "Any other exception" << std::endl;
  }

  return 0;
}

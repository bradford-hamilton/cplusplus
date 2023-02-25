#include <iostream>

/*

Exception Handling general best practice:
- User-defined exceptions
- We can create exception classes and throw instnaces of those classes
- Throw an object not a primitive type
- Throw an object by value
- Catch an object by reference (or const reference)

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

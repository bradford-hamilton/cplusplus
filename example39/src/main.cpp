#include <iostream>
#include <string>

/*

Exception Handling:
- Dealing with extraordinary situations

What causes exceptions?
- Insufficient resources
- Missing resources
- Invalid operations
- Range violations
- Underflows/overflows
- Illegal data and many more

Terminology:
- Exception - An object or primitive type that signals an error has occured.
- Throwing an exception (raising) - Code can throw an exception describing
  the error to another part of the program in which knows how to handle it.
- Catching an exception (handle the exception)

Styntax:
- throw
- try {}
- catch(Exception ex)

Stack Unwinding:
- If an exception is thrown but not caught in the current scope, C++ tries
  to find a handler for the exception by unwinding the stack.
- Function in which the exception was not caught terminates and is removed
  from the call stack.
- If a try block was used, then catch blocks are checked for a match.
- If no try block was used or the catch handler doesn't match, stack unwinding
  occurs again.
- If the stack is unwound back to main and no catch handler handles the
  exception, the program terminates.

*/

double calculate_mpg(int miles, int gallons) {
  if (gallons == 0) {
    throw 0;
  }
  return static_cast<double>(miles) / gallons;
}

double calculate_mpg_with_2_diff_exceptions(int miles, int gallons) {
  if (gallons == 0) {
    throw 0;
  }
  if (miles < 0 || gallons < 0) {
    throw std::string{"Negative value error"};
  }
  return static_cast<double>(miles) / gallons;
}

int main() {
  // --------------------- Inline example ----------------------
  int miles {30};
  int gallons {0};
  double miles_per_gallon {0};

  try {
    if (gallons == 0) {
      throw 0;
    }
    miles_per_gallon = static_cast<double>(miles) / gallons;
  } catch(int &ex) {
    std::cout << "Sorry, can't divide by 0 - inline" << std::endl;
  }

  // --------------------- Function example ---------------------
  double average;
  try {
    average = calculate_mpg(miles, gallons);
    std::cout << "Average: " << average << std::endl;
  } catch(int &ex) {
    std::cout << "Sorry, can't divide by 0 - func" << std::endl;
  }

  // ------ Function example with multiple exception types ------
  double average2;
  try {
    miles = -1;
    gallons = 1;
    average2 = calculate_mpg_with_2_diff_exceptions(miles, gallons);
    std::cout << "Average: " << average << std::endl;
  } catch(int &ex) {
    std::cout << "Sorry, can't divide by 0 - func - multiexception" << std::endl;
  } catch(std::string &ex) {
    std::cout << ex << std::endl; // Negative value error
  } catch(...) { // Catch all (no access to &ex)
    std::cout << "Any other exception" << std::endl;
  }
  
  return 0;  
}

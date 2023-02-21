#include <iostream>

/*

Passing args to base class constructors
- The base part of a Derived class must be initialized first.
- How can we control exactly which base class constructor is
  used during initialization?
- We can invoke whichever base class constructor we wish in
  the initialization list of the derived class.

*/

class Base {
private:
  int value;
public:
  Base()
    : value{0} {
    std::cout << "Base no-args constructor called" << std::endl;
  }
  Base(int x)
    : value{x} {
    std::cout << "Base int constructor called" << std::endl;
  }
};

class Derived: public Base {
private:
  int doubled_value;
public:
  Derived()
    : Base{}, doubled_value{0} {
    std::cout << "Derived no-args constructor called" << std::endl;
  }
  Derived(int x)
    : Base{x}, doubled_value{x*2} {
    std::cout << "Derived int constructor called" << std::endl;
  }
};

int main() {
  // Base no-args constructor called
  Base base1;

  // Base int constructor called
  Base base2 {100};

  // Base no-args constructor called
  // Derived no-args constructor called
  Derived deriv1;

  // Base int constructor called
  // Derived int constructor called
  Derived deriv2 {200};

  return 0;
}

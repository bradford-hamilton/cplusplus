#include <iostream>

/*

Constructors and class initialization with inheritance:
- The base part of the derived class MUST be initialized BEFORE the derived
  class is initialized.
- When a derived object is created, the base class constructor executes THEN
  derived class constructor executes.

*/

class Base {
public:
  Base() { std::cout << "Base constructor called" << std::endl; }
};

class Derived: public Base {
public:
  Derived() { std::cout << "Derived constructor called" << std::endl; }
};

int main() {
  Base b;
  // Base constructor called

  Derived d;
  // Base constructor called
  // Derived constructor called

  return 0;
}

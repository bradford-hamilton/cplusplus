#include <iostream>

/*

Constructors and class initialization with inheritance:
- The base part of the derived class MUST be initialized BEFORE the derived
  class is initialized.
- When a derived object is created, the base class constructor executes THEN
  derived class constructor executes.

Destructors with inheritance:
- Class destructors are invoked in the reverse order as constructors.
- The derived part of the derived class MUST be destroyed BEFORE the
  base class destructor is invoked.
- When a derived object is destroyed:
  - Derived class destructor executes, THEN base class destructor executes.
  - Each destructor should free resources allocated in its own constructors.

*/

class Base {
public:
  Base() { std::cout << "Base constructor called" << std::endl; }
  ~Base() { std::cout << "Base destructor called" << std::endl; }
};

class Derived: public Base {
public:
  Derived() { std::cout << "Derived constructor called" << std::endl; }
  ~Derived() { std::cout << "Derived destructor called" << std::endl; }
};

int main() {
  // Constructor order
  {
    Base b;
    // Base constructor called

    Derived d;
    // Base constructor called
    // Derived constructor called
  }
  
  // Destructor order
  {
    Derived d;
  }
  // Derived destructor called
  // Base destructor called

  return 0;
}

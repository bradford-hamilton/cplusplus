#include <iostream>
#include <memory>

/*

Polymorphism: Override specifier
- We can override Base class virtual functions
- The function signature and return must be EXACTLY the same
- If they are different, then we have redefinition, NOT overriding
- Redefinition is statically bound
- Overriding is dynamically bound
- C++11 provides an override specifier to have the compiler ensure overriding

*/

class Base {
  virtual void say_hello() const {
    std::cout << "Hello from Base class" << std::endl;
  }
  virtual ~Base();
};

// When specifically intending to override a parent-class' function,
// use the "override" keyword. This is explicit and also will throw
// compiler errors if you are to mismatch the signature or do anything
// to cause the method to be redefined vs. overridden.
class Derived: public Base {
  virtual void say_hello() const override {
    std::cout << "Hello from Derived class" << std::endl;
  }
  virtual ~Derived();
};

int main() {
  return 0;
}

#include <iostream>
#include <memory>

/*

Polymorphism
- Fundamental to OOP
- Polymorphism
  - Compile-time/early binding/static binding   (before program runs)
  - Run-time/late binding/dynamic binding       (run-time)
- Allows us to program more abstractly
  - Think general vs. specific
  - Let C++ figure out which function to call at run-time
- Not the default in C++, run-time polymorphism is acheived via:
  - Inheritance
  - Base class pointers or references
  - Virtual functions

// As you would expect:

Account a;
a.withdraw(1000);             // Account::withdraw()

Savings b;
b.withdraw(1000);             // Savings::withdraw()

Checking c;
c.withdraw(1000);             // Checking::withdraw()

Trust d;
d.withdraw(1000);             // Trust::withdraw()

// Here is where things are different:

Account *ptr = new Trust();
ptr.withdraw(1000);           // Account::withdraw(), but should be Trust::withdraw()

We can use virtual functions here so that they don't bind statically at compile time
and rather call the correct object's method based on the pointer type at run-time.

*/

// EXAMPLE WITHOUT POLYMORPHISM TO SHOW BEHAVIOR
// EXAMPLE OF POLYMORPHISM IS IN NEXT FOLDER (example31)

class Base {
public:
  void say_hello() const {
    std::cout << "hello from base class object" << std::endl;
  }
};

class Derived: public Base {
public:
  void say_hello() const {
    std::cout << "hello from derived class object" << std::endl;
  }
};

void greetings(const Base &obj) {
  std::cout << "Greetings, ";
  obj.say_hello();
}

int main() {
  Base b;
  b.say_hello(); // hello from base class object

  Derived d;
  d.say_hello(); // hello from derived class object

  // As far as the compiler is concerned at compile time,
  // the &obj passed in here is a reference to a Base.

  greetings(b); // Greetings, hello from base class object
  greetings(d); // Greetings, hello from base class object

  Base *b_ptr = new Derived();
  b_ptr->say_hello(); // hello from base class object

  // Using a smart pointer, same results
  std::unique_ptr<Base> smrt_ptr = std::make_unique<Derived>();
  smrt_ptr->say_hello(); // hello from base class object

  return 0;
}

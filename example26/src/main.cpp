#include <iostream>

/*

-----------------------------------------------------------------------------

Inheritance
- Provides a method for creating new classes from existing classes
- The new class contains the data and behaviors of the existing class
- Allow for reuse of existing classes
- Allows us to focus on the common attributes among a set of classes
- Allows new classes to modify behaviors of existing classes to make
  it unique (without actually modifying the original class)

Examples of some related classes
- Player, Enemy, Level Boss, Hero, Super Player, etc
- Account, Savings Account, Checking Account, Trust Account, etc
- Shape, Line, Oval, Circle, Square, etc
- Person, Employee, Student, Faculty, Staff, Administrator, etc

-----------------------------------------------------------------------------

- Base Class (parent class, super class) - The class being extended or inherited from
- Derived Class (child class, sub class) - The class being created from the base class

-----------------------------------------------------------------------------

Public Inheritance
  - "is-a" relationship
    - Employee "is-a" Person
    - Checking Account "is-a" Account
    - Circle "is-a" Shape

Composition
  - "has-a" relationship
    - Person "has-a" Account
    - Player "has-a" Special Attack
    - Circle "has-a" Location

-----------------------------------------------------------------------------

protected:
- Accesible from the Base Class itself
- Accesible from class Derived from Base
- Not accessible by objects of Base or Derived

-----------------------------------------------------------------------------

What does a Derived Class NOT inherit?
- Base class constructors
- Base class destructor
- Base class overloaded assignment operators
- Base class friend functions

However, the derived class constructors, destructors, and overloaded assignment
operators can invoke the base class versions.

Note: C++11 allows explicit inheritance of base "non-special" constructors with
- using Base::Base; anywhere in the derived class declaration
- Lots of rules involved, often better to define constructors yourself.

-----------------------------------------------------------------------------

*/

class Base {
public:
  int a {0};
protected:
  int b {0};
private:
  int c {0};
};

class Derived: public Base {
  // Note friends of derived have access to only what Derived has access to.
  // a will be public
  // b will be protected
  // c will be private
public:
  void access_base_members() {
    this->a = 100;
    this->b = 200;
    // this->c = 300; // Compiler error: Base::c is inaccessible
  }
};

int main() {
  // As far as the compiler is concerned the private and protected access
  // modifiers are essentially the same when dealing with objects.

  /*
  
  Base base;
  base.a = 100; // Okay
  base.b = 200; // Compiler error
  base.c = 300; // Compiler error
  
  Derived driv;
  driv.a = 100; // Okay
  driv.b = 200; // Compiler error
  driv.c = 300; // Compiler error

  */

  return 0;
}

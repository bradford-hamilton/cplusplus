#include <iostream>
#include <memory>

/*

Polymorphism: final specifier
- When used at the class level, it prevents a class from
  being derived from.
- When used at the method level, it prevents virtual method
  from being overridden in derived classes.
*/

// Final class example
class MyClass final {};

// Final method example
class A {
public:
  virtual void do_something();
};

class B: public A {
public:
  virtual void do_something() final; // Prevent further overriding
};

class C: public B {
public:
  // virtual void do_something(); - Compiler error cannot override 'final' function "B::do_something"
};

int main() {
  return 0;
}

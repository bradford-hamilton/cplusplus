#include <iostream>
#include <memory>

/*

Polymorphism: Virtual Functions
- Redefined functions are bound statically
- Overridden functions are bound dynamically
- Virtual functions are overridden
- Allow us to treat all objects generally as objects of the base class

In base class:
- Declare the function you want to override as virtual in the base class.
- Virtual functions are virtual all the way down the hierarchy from this point.
- Dynamic polymorphism only via Account class pointer or reference.

In derived class:
- Override the function in the derived class
- Function signature and return type must match exactly
- Virtual keyword not required, but it is best practice
- If you don't provide an overridden version, it's inherited from its base class

-------------------------------------------------------------------------------------

Virutal destructors:
- Problems can happen when we destroy polymorphic objects
- If a derived class is destroyed by deleting its storage via the base
  class pointer and the class doesn't have a virtual destructor, then
  the behavior is undefined in the C++ standard.

Rule:
- If a class has virtual functions, ALWAYS provide a public virtual destructor
- If base class destructor is virtual then all derived class destructors are also virtual

*/

class Account {
public:
  // Making this base class' withdraw func virtual is the key here.
  // It seems for clarity's sake, its good to mark the derived
  // classes as well.
  virtual void withdraw(double amount) {
    std::cout << "Account::withdraw" << std::endl;
  }
  virtual ~Account() {
    std::cout << "Account destructor" << std::endl;
  }
};

class Checking: public Account {
public:
  virtual void withdraw(double amount) {
    std::cout << "Checking::withdraw" << std::endl;
  }
  virtual ~Checking() {
    std::cout << "Checking destructor" << std::endl;
  }
};

class Savings: public Account {
public:
  virtual void withdraw(double amount) {
    std::cout << "Savings::withdraw" << std::endl;
  }
  virtual ~Savings() {
    std::cout << "Savings destructor" << std::endl;
  }
};

class Trust: public Account {
public:
  virtual void withdraw(double amount) {
    std::cout << "Trust::withdraw" << std::endl;
  }
  virtual ~Trust() {
    std::cout << "Trust destructor" << std::endl;
  }
};

int main() {
  std::cout << "------Pointers------" << std::endl;

  // Without inheritance/polymorphism/virutal functions, every variable below
  // will print "Account::withdraw" - this is because without polymorphism, the
  // compiler is statically binding before run time the Account type here, as apposed
  // to checking and calling the right method at runtime based on the type of Account.
  Account *p1 = new Account();
  Account *p2 = new Checking();
  Account *p3 = new Savings();
  Account *p4 = new Trust();

  /*
    With our dynamic binding at run-time through virtual funcs, the pointers
    resolve to the right sub class' withdraw method.

    Account::withdraw
    Checking::withdraw
    Savings::withdraw
    Trust::withdraw
  */

  p1->withdraw(1000);
  p2->withdraw(1000);
  p3->withdraw(1000);
  p4->withdraw(1000);


  std::cout << "------Cleanup------" << std::endl;
  /*
    Never forget to free memory you allocated. With your virtual destructors,
    this is what prints when destroying the below memory.

    Account destructor
    Checking destructor
    Account destructor
    Savings destructor
    Account destructor
    Trust destructor
    Account destructor
    delete p1;
  */
  delete p1;
  delete p2;
  delete p3;
  delete p4;

  return 0;
}


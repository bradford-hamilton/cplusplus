#include <iostream>

/*

Example showing a base abstract class Printable which any objects created from it must
implement its interface. Account is an I_Printable and Checking is an Account. This means
the virtual "print" function must be implemented in both (all the way up the chain). This
is powerful and allows any kind of Account to be printable on an ostream.

*/

class I_Printable {
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
  virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
  obj.print(os);
  return os;
}

class Account: public I_Printable {
public:
  virtual void print(std::ostream &os) const override {
    os << "Account print";
  }
  // Default to compiler given destructor
  virtual ~Account() = default;
};

class Checking: public Account {
public:
  virtual void print(std::ostream &os) const override {
    os << "Checking print";
  }
  // Default to compiler given destructor
  virtual ~Checking() = default;
};

// Example of regular C++ non-member func that works with the I_Printable class (interface)
void regular_print(const I_Printable &obj) {
  std::cout << obj << std::endl;
}

int main() {
  Account a;
  Checking b;

  std::cout << a << std::endl; // Account print
  std::cout << b << std::endl; // Checking print

  std::cout << "----------Pointers----------" << std::endl;

  // Using a base class pointer
  Account *ptr1 = new Account();
  Account *ptr2 = new Checking();

  std::cout << *ptr1 << std::endl; // Account print
  std::cout << *ptr2 << std::endl; // Checking print

  std::cout << "----------Regular Print----------" << std::endl;

  regular_print(a); // Account print
  regular_print(b); // Checking print
  regular_print(*ptr1); // Account print
  regular_print(*ptr2); // Checking print

  return 0;
}

#include <iostream>

// "this" pointer
// Reserved keyword and contains the address of the object (so raw ptr to the object).
// Can only be used within class scope.
// All member access is done via the 'this' pointer.
// Can be used by the programmer to access data members and methods, to determine
// if two objects are the same (more in next section), and can be dereferenced (*this)
// to yield the current object.

// ----------------------------------------------------------------

class Account {
private:
  std::string name;
  double balance;
public:
  Account(std::string name, double initial_balance);
  void set_balance(double bal);
  void set_balance_with_this(double balance);
  std::string get_name() const;
};

Account::Account(std::string name, double initial_balance)
  : name{name}, balance{initial_balance} {
  std::cout << "Constructor called: " << name << std::endl;
}

void Account::set_balance(double bal) {
  balance = bal; // "this->balance" is implied
}

void Account::set_balance_with_this(double balance) {
  // With same parameter name as the member, Which balance?
  // The following is then ambiguous:
  // balance = balance;
  // So we will use:
  this->balance = balance;
}

// Telling the compiler that specific methods will not modify the
// object. This will now allow this method to be called on const
// versions of objects created. Without the const qualifier here
// we get the error: error: 'this' argument to member function
// 'get_name' has type 'const Account', but function is not
// marked const
std::string Account::get_name() const {
  return name;
}

// ----------------------------------------------------------------

int main() {
  const Account barbara_account{"Barbara", 0};
  std::cout << barbara_account.get_name() << std::endl;
  return 0;
}

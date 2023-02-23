#include <iostream>
#include <memory>

class Account {
public:
  virtual void withdraw(double amount) {
    std::cout << "Account::withdraw" << std::endl;
  }
  virtual ~Account() {}
};

class Trust: public Account {
public:
  virtual void withdraw(double amount) override {
    std::cout << "Trust::withdraw" << std::endl;
  }
  virtual ~Trust() {}
};

class Checking: public Account {
public:
  virtual void withdraw(double amount) override {
    std::cout << "Checking::withdraw" << std::endl;
  }
  virtual ~Checking() {}
};

class Savings: public Account {
public:
  virtual void withdraw(double amount) override {
    std::cout << "Savings::withdraw" << std::endl;
  }
  virtual ~Savings() {}
};

void do_withdraw(Account &account, double amount) {
  account.withdraw(amount);
}

// Using Base class references, for example a non-member func
// that takes a reference to an Account with virtual overridden
// funcs will dynamically call the correct withdraw method.
int main() {
  Account a1;
  Trust b1;
  Checking c1;
  Savings d1;

  do_withdraw(a1, 100); // Account::withdraw
  do_withdraw(b1, 100); // Trust::withdraw
  do_withdraw(c1, 100); // Checking::withdraw
  do_withdraw(d1, 100); // Savings::withdraw

  return 0;
}

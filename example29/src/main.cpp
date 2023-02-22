#include <iostream>

// Using and redefining a base class' methods from a derived classs.

/*

Static binding of method calls:
- Default binding for C++ is static
- Derived class objects will use Derived::deposit
- But, we can explicitly invoke Base::deposit from Derived::deposit
- OK, but limited - much more powerful approach is dynamic binding - see in next example

*/

class Account {
private:
  double balance;
public:
  Account()
    : balance{0} {}

  void deposit(double amount) { this->balance += amount; }
};

class SavingsAccount: public Account {
private:
  double balance;
  double int_rate;
public:
  SavingsAccount()
    : int_rate{1.75} {}

  // Redefine base class method
  void deposit(double amount) {
    // Add interest to the amount, then deposit.
    amount = amount + (amount*this->int_rate);

    // Call/invoke base class deposit method.
    Account::deposit(amount);
  }
};

int main() {
  Account a;
  a.deposit(100); // Account::deposit

  SavingsAccount b;
  b.deposit(100); // SavingsAccount::deposit

  Account *ptr = new SavingsAccount();
  ptr->deposit(100); // Account::deposit

  return 0;
}

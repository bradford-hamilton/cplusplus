// Implementing member methods outside class declaration like we've
// done in the past, but instead of declaring in the same file we
// will start to use header (.h) files. The header file will
// prototype/describe the class and the .cpp file will implement it.

#include <iostream>
#include "Account.h"

int main() {
  Account frank_account;
  frank_account.set_balance(120.50);
  double franks_bal = frank_account.get_balance();

  std::cout << franks_bal << std::endl;

  return 0;
}

#include <iostream>
#include "Account.h"
#include "AccountUtils.h"
#include "Checking.h"

// Example 36 with proper header files, etc
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

  regular_print(a);     // Account print
  regular_print(b);     // Checking print
  regular_print(*ptr1); // Account print
  regular_print(*ptr2); // Checking print

  return 0;
}

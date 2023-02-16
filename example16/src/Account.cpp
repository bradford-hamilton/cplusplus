// Includes with double quotes tells the compiler to include header
// files local to this project vs system files with angle brackets
// like we've seen thus far (<iostream> for example)

#include "Account.h"

void Account::set_balance(double bal) {
  balance = bal;
}

double Account::get_balance() {
  return balance;
}

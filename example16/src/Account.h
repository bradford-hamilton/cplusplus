// If multiple files include this header file, you can get a
// compiler error around multiple declarations so we will use
// "Include Guards" to ensure the declaration only happens once.
// Some compilers will support "#pragma once" at the top instead
// the ifndef/define/endif statements.

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {
private:
  double balance;
public:
  void set_balance(double bal);  
  double get_balance();  
};

#endif

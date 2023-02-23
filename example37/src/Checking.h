#ifndef _CHECKING_H_
#define _CHECKING_H_

#include "Account.h"

class Checking: public Account {
public:
  virtual void print(std::ostream &os) const override;
  virtual ~Checking() = default;
};

#endif // _CHECKING_H_

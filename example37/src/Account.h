#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "IPrintable.h"

class Account: public IPrintable {
public:
  virtual void print(std::ostream &os) const override;
  virtual ~Account() = default;
};

#endif // _ACCOUNT_H_

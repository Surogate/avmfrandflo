#ifndef AOBJ_H
#define AOBJ_H

#include <string>
#include "ioperand.h"

class	AObj : public IOperand
{
public:
  virtual ~AObj() {}
  virtual void	setObj(std::string) = 0;
  virtual int   getprio() const = 0;
  virtual AObj *newClone() const = 0;
};


#endif // AOBJ_H

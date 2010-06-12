#ifndef __AVM_DOUBLE_H__
#define __AVM_DOUBLE_H__

#include "AObj.h"

class avm_double :
  public AObj
{
  double	  _value;
  std::string _valuestr;
  std::string _type;

public:
  avm_double(void);
  ~avm_double(void);
  
  IObject*  Add(const IOperand &object);
  IObject*  Subtract(const IOperand &object);
  IObject*  Multiply(const IOperand &object);
  IObject*  Divide(const IOperand &object);
  
  void	setObj(std::string const &);
  AObj* newClone() const;
  
  const std::string& ToString() const;
  const std::string& GetType() const;
  bool Equals(const IObject &value) const;
  IObject* Clone() const;
};

#endif /* __AVM_DOUBLE_H__ */
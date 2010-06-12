#include "avm_double.h"

avm_double::avm_double(void): _type("double"),
		                      _value(),
							  _valuestr()
{
}

avm_double::~avm_double(void)
{}

IObject*  avm_double::Add(const IOperand &object)
{
return (0);
}

IObject*  avm_double::Subtract(const IOperand &object)
{
return (0);
}

IObject*  avm_double::Multiply(const IOperand &object)
{
return (0);
}

IObject*  avm_double::Divide(const IOperand &object)
{
return (0);
}

void avm_double::setObj(std::string const &val)
{
  this->_valuestr = val;
  this->_value = std::atof(val.c_str());
}

AObj* avm_double::newClone() const
{
  AObj * res = new avm_double;
  res->setObj(this->_valuestr);
  return res;
}

const std::string& avm_double::ToString() const
{
  return (this->_valuestr);
}

const std::string& avm_double::GetType() const
{
  return (this->_type);
}

bool avm_double::Equals(const IObject &value) const
{
  return(this->ToString() == value.ToString());
}

IObject* avm_double::Clone() const
{
  IObject* res = new avm_double;
  return res;
}
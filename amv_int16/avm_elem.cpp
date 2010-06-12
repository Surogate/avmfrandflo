#include <sstream>
#include "avm_elem.h"

avm_elem::avm_elem(void): _type("int16"),
		                      _value(),
							  _valuestr()
{}

avm_elem::~avm_elem(void)
{}

IObject*  avm_elem::Add(const IOperand &object)
{
return (0);
}

IObject*  avm_elem::Subtract(const IOperand &object)
{
return (0);
}

IObject*  avm_elem::Multiply(const IOperand &object)
{
return (0);
}

IObject*  avm_elem::Divide(const IOperand &object)
{
return (0);
}

void avm_elem::setObj(std::string const &val)
{
  this->_valuestr = val;
  std::istringstream iss( val );
  iss >> this->_value;
}

AObj* avm_elem::newClone() const
{
  AObj * res = new avm_elem;
  res->setObj(this->_valuestr);
  return res;
}

const std::string& avm_elem::ToString() const
{
  return (this->_valuestr);
}

const std::string& avm_elem::GetType() const
{
  return (this->_type);
}

bool avm_elem::Equals(const IObject &value) const
{
  return(this->ToString() == value.ToString());
}

IObject* avm_elem::Clone() const
{
  IObject* res = new avm_elem;
  return res;
}
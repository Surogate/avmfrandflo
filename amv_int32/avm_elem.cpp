#include <sstream>
#include "avm_elem.h"

avm_elem::avm_elem(void): _value(),
						  _valuestr(),
						  _type("int32")
{}

avm_elem::~avm_elem(void)
{}

IObject*  avm_elem::Add(const IOperand &object)
{
  AObj* res;
  std::stringstream sortie;
  long double temp2;
  const AObj & tmp = static_cast<const AObj&>(object);
  if (this->_prio > tmp.getprio())
    res = this->newClone();
  else
    res = tmp.newClone();
  
  std::istringstream iss( tmp.ToString() );
  iss >> temp2;
  sortie << this->_value + temp2;
  res->setObj(sortie.str());
  return (res);
}

IObject*  avm_elem::Subtract(const IOperand &object)
{
  AObj* res;
  std::stringstream sortie;
  long double temp2;
  const AObj & tmp = static_cast<const AObj&>(object);
  if (this->_prio > tmp.getprio())
    res = this->newClone();
  else
    res = tmp.newClone();
  
  std::istringstream iss( tmp.ToString() );
  iss >> temp2;
  sortie << this->_value - temp2;
  res->setObj(sortie.str());
  return (res);
}

IObject*  avm_elem::Multiply(const IOperand &object)
{
  AObj* res;
  std::stringstream sortie;
  long double temp2;
  const AObj & tmp = static_cast<const AObj&>(object);
  if (this->_prio > tmp.getprio())
    res = this->newClone();
  else
    res = tmp.newClone();
  
  std::istringstream iss( tmp.ToString() );
  iss >> temp2;
  sortie << this->_value * temp2;
  res->setObj(sortie.str());
  return (res);
}

IObject*  avm_elem::Divide(const IOperand &object)
{
  AObj* res;
  std::stringstream sortie;
  long double temp2;
  const AObj & tmp = static_cast<const AObj&>(object);

  std::istringstream iss( tmp.ToString() );
  iss >> temp2;
  if (temp2 != 0)
  {
    if (this->_prio > tmp.getprio())
      res = this->newClone();
    else
      res = tmp.newClone();
    sortie << this->_value / temp2;
    res->setObj(sortie.str());
    return (res);
  }
  return 0;
}

void avm_elem::setObj(std::string const &val)
{
  this->_valuestr = val;
  std::istringstream iss( val );
  iss >> this->_value;
}

int   avm_elem::getprio() const
{
  return this->_prio;
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

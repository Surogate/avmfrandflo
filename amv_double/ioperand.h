#ifndef IOPERAND_H_INCLUDED
#define IOPERAND_H_INCLUDED

#include "iobject.h"

class IOperand : public IObject
{
public:
    virtual IObject*  Add(const IOperand &object) = 0;
    virtual IObject*  Subtract(const IOperand &object) = 0;
    virtual IObject*  Multiply(const IOperand &object) = 0;
    virtual IObject*  Divide(const IOperand &object) = 0;
};

#endif // IOPERAND_H_INCLUDED

#ifndef AOBJ_H
#define AOBJ_H

#include "ioperand.h"

class AObj : public IOperand
{
public:
    virtual ~AObj() {}
    virtual void setObj(std::string const&) = 0;
    virtual AObj* newClone() = 0;
};

#endif // AOBJ_H

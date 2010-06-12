#ifndef IOBJECT_H_INCLUDED
#define IOBJECT_H_INCLUDED

#include <string>

class IObject
{
public:
    virtual const std::string& ToString() const = 0;
    virtual const std::string& GetType() const = 0;
    virtual bool Equals(const IObject &value) const = 0;
    virtual IObject* Clone() const = 0;
};


#endif // IOBJECT_H_INCLUDED

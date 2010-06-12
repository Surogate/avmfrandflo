#ifndef OBJFACTORY_H
#define OBJFACTORY_H

#include <string>
#include <map>
#include "iobject.h"

class ObjFactory
{
    public:
        ObjFactory(std::string sharedDir);
        ~ObjFactory();
        IObject* creat(std::string&);
    private:
        std::map< std::string, IObject* /* sera un pointeur sur fonction */ > factory_;
};

#endif // OBJFACTORY_H

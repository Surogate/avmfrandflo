#ifndef OBJFACTORY_H
#define OBJFACTORY_H

#include <string>
#include <map>
#include "iobject.h"
#include "ASharedLib.h"
#include "aobj.h"

class ObjFactory
{
public:
    ObjFactory(ASharedLib& shared, std::string sharedDir);
    ~ObjFactory();
    AObj* creat(std::string& type, std::string value = "0");

private:
    std::vector<ASharedLib::lib_handler> tab_;
    ASharedLib& shared_;
    std::map< std::string, AObj* > factory_;
};

#endif // OBJFACTORY_H

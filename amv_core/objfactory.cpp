#include "objfactory.h"

ObjFactory::ObjFactory(std::string sharedDir)
{}

ObjFactory::~ObjFactory()
{}

IObject* ObjFactory::creat(std::string&)
{
    return 0;
}

#include "objfactory.h"

typedef AObj* (*func_ptr)();

ObjFactory::ObjFactory(ASharedLib& shared, std::string libDir)
    : shared_(shared)
{
    shared_.openLibFrom(libDir, tab_);
    for (unsigned int i = 0; i < tab_.size(); ++i)
    {
        func_ptr ptr = reinterpret_cast<func_ptr>(shared_.getFunc(tab_[i], "getInstance"));
        if (ptr)
        {
            AObj* obj = ptr();
            factory_[obj->GetType()] = obj;
        }
    }
}

ObjFactory::~ObjFactory()
{
    std::map< std::string, AObj* >::iterator it = factory_.begin();
    std::map< std::string, AObj* >::iterator eit = factory_.end();

    while (it != eit)
    {
        delete it->second;
        ++it;
    }
    factory_.clear();
}

AObj* ObjFactory::creat(std::string& type, std::string value)
{
    std::map< std::string, AObj* >::const_iterator cit(factory_.find(type));

    if (cit != factory_.end())
    {
        AObj* new_Obj = cit->second->newClone();
        new_Obj->setObj(value);
        return new_Obj;
    }
    return 0;
}

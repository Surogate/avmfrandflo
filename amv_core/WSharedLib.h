
#ifndef WSHAREDLIB_H_
# define WSHAREDLIB_H_

#include "ASharedLib.h"

class WSharedLib : public ASharedLib
{
public:
    virtual ~WSharedLib();
    ASharedLib::lib_handler	LoadLib(std::string);
    void* getFunc(ASharedLib::lib_handler&, std::string);
    bool closeLib(ASharedLib::lib_handler&);
    void openLibFrom(std::string dir, std::vector<ASharedLib::lib_handler>& tab);
};

#endif

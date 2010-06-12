
#ifndef LSHAREDLIB_H_
# define LSHAREDLIB_H_

#include "ASharedLib.h"

class LSharedLib : public ASharedLib
{
public:
    virtual ~LSharedLib();
    ASharedLib::lib_handler	LoadLib(std::string);
    void* getFunc(ASharedLib::lib_handler&, std::string);
    bool closeLib(ASharedLib::lib_handler&);
    void openLibFrom(std::string dir, std::vector<ASharedLib::lib_handler>& tab);
};

#endif

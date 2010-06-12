
#ifdef WIN32
# include <direct.h>
# include <windows.h>
#else
# include <sys/types.h>
# include <dlfcn.h>
# include <dirent.h>
#endif

#include <iostream>
#include <string>
#include <vector>

#ifndef ASHAREDLIB_H_
# define ASHAREDLIB_H_

class ASharedLib
{
public:

# ifdef WIN32
    typedef HMODULE lib_handler;
#  else
    typedef void* lib_handler;
# endif
    virtual ~ASharedLib() {}
    virtual lib_handler	LoadLib(std::string) = 0;
    virtual void* getFunc(lib_handler&, std::string) = 0;
    virtual	bool closeLib(lib_handler&) = 0;
    virtual void openLibFrom(std::string dir, std::vector<ASharedLib::lib_handler>& tab) = 0;
};

#endif

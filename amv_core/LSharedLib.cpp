
#include <iostream>
#include "LSharedLib.h"
#ifndef WIN32

LSharedLib::~LSharedLib()
{}

ASharedLib::lib_handler	LSharedLib::LoadLib(std::string name)
{
    return dlopen(name.data(), RTLD_LAZY);
}

void* LSharedLib::getFunc(ASharedLib::lib_handler& hdl, std::string funcName)
{
    return dlsym(hdl, funcName.data());
}

bool LSharedLib::closeLib(ASharedLib::lib_handler& hdl)
{
    return dlclose(hdl);
}

void LSharedLib::openLibFrom(std::string dir, std::vector<ASharedLib::lib_handler>& tab)
{
	if (dir == "")
		dir = ".";
    DIR* handler = opendir(dir.data());
    struct dirent *dirent_;
    std::string name;

    int pos;

    if (handler)
    {
        while ((dirent_ = readdir(handler)))
		{
        	name = dir;
        	name += "/";
        	name += dirent_->d_name;
			if ((pos = name.find(".so")) > 0)
				{
					tab.push_back(LoadLib(name));
				}
		}
    }
}

#endif

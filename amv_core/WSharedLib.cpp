
#include "WSharedLib.h"

WSharedLib::~WSharedLib()
{}

ASharedLib::lib_handler WSharedLib::LoadLib(std::string name)
{
    HMODULE dllHdl = LoadLibrary(TEXT(name.data()));
    return dllHdl;
}

void* WSharedLib::getFunc(ASharedLib::lib_handler& hdl, std::string funcName)
{
    return reinterpret_cast<void*>(GetProcAddress(hdl, funcName.data()));
}

bool WSharedLib::closeLib(lib_handler& hdl)
{
    if (FreeLibrary(hdl))
        return true;
    return false;
}

void WSharedLib::openLibFrom(std::string dir, std::vector<ASharedLib::lib_handler>& tab)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    const char match[] = "*.dll";

    if (dir != "")
        dir += "\\";
    dir += match;

    hFind = FindFirstFileEx(dir.data(), FindExInfoStandard, &FindFileData,
                            FindExSearchNameMatch, NULL, 0 );

    if (hFind != INVALID_HANDLE_VALUE)
    {
        tab.push_back(LoadLib(FindFileData.cFileName));
        while (FindNextFile(hFind, &FindFileData))
        {
            tab.push_back(LoadLib(FindFileData.cFileName));
        }
    }
    else
        std::cerr << "invalid_handle" << std::endl;
    FindClose(hFind);
}

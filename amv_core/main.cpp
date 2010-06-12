#include <iostream>

#include <string>
#include "script.h"
#ifdef WIN32
#include "WSharedLib.h"
#else
#include "LSharedLib.h"
#endif


int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cout << "Usage ./amv [Script ...]" << std::endl;
        return 0;
    }

#ifdef WIN32
    WSharedLib shared;
#else
    LSharedLib shared;
#endif

    ObjFactory factory(shared);
    for (int i = 1; i < ac; ++i)
    {
        Script file(factory, av[i]);
        file.run();
    }
    return 0;
}

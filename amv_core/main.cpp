#include <iostream>

#include <string>
#include "script.h"
#ifdef WIN32
#include "WSharedLib.h"
#else
#include "LSharedLib.h"
#endif


int main()
{
#ifdef WIN32
    WSharedLib shared;
#else
    LSharedLib shared;
#endif

    Script file("test.src");

    file.run();
    return 0;
}

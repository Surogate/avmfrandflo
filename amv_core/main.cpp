#include <iostream>

#include <string>
#include "script.h"

int main()
{
    Script file("test.src");

    file.run();
    return 0;
}

#include <iostream>

#include <string>
#include "script.h"

int main()
{
    std::string instruction;
    Script file("test.src");

    while(file.getNextInstruction(instruction))
    {
        //execute l'instruction
    }
    if (file.getError())
    {
        std::cerr << "error at instruction " << instruction << std::endl;
    }
    else
    {
        std::cout << "le fichier c'est correctement executer" << std::endl;
    }
    return 0;
}

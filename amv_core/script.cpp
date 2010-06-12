
#include <iostream>
#include "script.h"

Script::Script(std::string dir)
    : error_(0)
{
    //ctor
}

Script::~Script()
{
    //dtor
}

bool Script::getNextInstruction(std::string& new_instruction)
{
    return false;
}

int const& Script::getError() const
{
    return error_;
}

void Script::run()
{
    std::string instruction;

    while(getNextInstruction(instruction))
    {
        //execute l'instruction
    }
    if (error_)
    {
        std::cerr << "error at instruction " << instruction << std::endl;
    }
    else
    {
        std::cout << "le fichier c'est correctement executer" << std::endl;
    }
}

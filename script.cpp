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

int const& Script::getError()
{
    return error_;
}

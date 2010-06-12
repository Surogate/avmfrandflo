
#include <iostream>
#include "script.h"

Script::Script(ObjFactory& factory, std::string dir)
    : error_(0), factory_(factory), ifs_(dir.data())
{
    if (!ifs_.good())
    {
        std::cerr << "Can't open file " << dir << std::endl;
        error_ = Script::invalid_file;
    }
}

Script::~Script()
{
    ifs_.close();
}

void Script::clean(std::string&)
{

}

bool Script::getNextInstruction(Instruction& instru)
{
    if (ifs_.good())
    {
        getline(ifs_, instru.instr);
        unsigned int pos = std::string::npos;
        if ((pos = instru.instr.find(";")) != std::string::npos)
        {
            instru.instr.erase(pos);
        }
        pos  = instru.instr.find_first_of(" ");
        instru.bytecode = instru.instr.substr(0, pos);
        if (pos != std::string::npos)
        {
            unsigned int pos2  = instru.instr.find_first_of("(");
            instru.argument = instru.instr.substr(pos + 1, pos2);
            if (pos2 != std::string::npos)
            {
                unsigned int pos3 = instru.instr.find_first_of(")");
                instru.value = instru.instr.substr(pos2 + 1, pos3);
            }
        }
    }
    return false;
}

int const& Script::getError() const
{
    return error_;
}

void Script::run()
{
    if (error_)
        return ;
    Instruction instru_;

    while(getNextInstruction(instru_) && !error_)
    {

    }
    if (error_)
    {
        std::cerr << "error at instruction " << instru_.instr << std::endl;
    }
    else
    {
        std::cerr << "Script ok" << std::endl;
    }
}

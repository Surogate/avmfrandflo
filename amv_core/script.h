#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include <fstream>
#include <stack>
#include "objfactory.h"

struct Instruction
{
    Instruction() : instr(""), bytecode(""), argument(""), value("") {}
    std::string instr;
    std::string bytecode;
    std::string argument;
    std::string value;
};

class Script
{
public:
    Script(ObjFactory&, std::string);
    ~Script();
    bool getNextInstruction(Instruction& instru);
    int const& getError() const;
    void run();

    enum
    {
        invalid_file = 1
    };

private:
    int error_;
    ObjFactory& factory_;
    std::ifstream ifs_;
    std::stack< AObj* > stack_;

    void clean(std::string&);
    void do_push();
    void do_add();
    void do_mul();
    void do_dump();
    void do_pop();
    void do_assert();
};

#endif // SCRIPT_H

#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include <fstream>
#include <stack>
#include <map>
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

    typedef void (Script::*func_ptr)();

    Script(ObjFactory&, std::string);
    ~Script();
    bool getNextInstruction();
    int const& getError() const;
    void run();

    enum
    {
        invalid_file = 1,
        invalid_bytecode = 2,
        false_assert = 3,
        unknow_type = 4,
        not_enough_object = 5,
        divide_by_zero = 6,
        empty_stack = 7
    };

private:

    int error_;
    ObjFactory& factory_;
    std::ifstream ifs_;
    std::stack< AObj* > stack_;
    std::map< std::string, func_ptr > func_tab;
    Instruction instru_;

    void clean(std::string&);
    void execute();
    void do_push();
    void do_add();
    void do_mul();
    void do_div();
    void do_sub();
    void do_dump();
    void do_pop();
    void do_assert();
};

#endif // SCRIPT_H

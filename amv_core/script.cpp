
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

    func_tab["push"] = &Script::do_push;
    func_tab["add"] = &Script::do_add;
    func_tab["mul"] = &Script::do_mul;
    func_tab["dump"] = &Script::do_dump;
    func_tab["pop"] = &Script::do_pop;
    func_tab["assert"] = &Script::do_assert;
    func_tab["div"] = &Script::do_div;
    func_tab["sub"] = &Script::do_sub;
}

Script::~Script()
{
    ifs_.close();
}

void Script::clean(std::string&)
{

}

bool Script::getNextInstruction()
{
    if (ifs_.good())
    {
        getline(ifs_, instru_.instr);
        if (ifs_.good())
        {
            unsigned int pos = std::string::npos;
            if ((pos = instru_.instr.find(";")) != std::string::npos)
            {
                instru_.instr.erase(pos);
            }
            pos  = instru_.instr.find_first_of(" ");
            instru_.bytecode = instru_.instr.substr(0, pos);
            if (pos != std::string::npos)
            {
                unsigned int pos2  = instru_.instr.find_first_of("(");
                instru_.argument = instru_.instr.substr(pos + 1, pos2);
                if (pos2 != std::string::npos)
                {
                    unsigned int pos3 = instru_.instr.find_first_of(")");
                    instru_.value = instru_.instr.substr(pos2 + 1, pos3);
                }
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
    while(getNextInstruction() && !error_)
    {
        execute();
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

void Script::execute()
{
    std::map< std::string, func_ptr >::const_iterator it = func_tab.find(instru_.bytecode);

    if (it != func_tab.end())
    {
        (this->*func_tab[instru_.bytecode])();
    }
    else
    {
        error_ = invalid_bytecode;
    }
}

void Script::do_push()
{
    AObj* arg = factory_.creat(instru_.argument, instru_.value);
    if (arg)
    {
        stack_.push(arg);
    }
    else
    {
        error_ = unknow_type;
    }
}

void Script::do_add()
{
    if (stack_.size() < 2)
    {
        error_ = not_enough_object;
    }
    else
    {
        IOperand* ope1 = stack_.top();
        stack_.pop();
        IOperand* ope2 = stack_.top();
        stack_.pop();
        stack_.push(static_cast< AObj* >(ope1->Add(*ope2)));
    }
}

void Script::do_mul()
{
    if (stack_.size() < 2)
    {
        error_ = not_enough_object;
    }
    else
    {
        IOperand* ope1 = stack_.top();
        stack_.pop();
        IOperand* ope2 = stack_.top();
        stack_.pop();
        stack_.push(static_cast< AObj* >(ope1->Multiply(*ope2)));
    }
}

void Script::do_div()
{
    if (stack_.size() < 2)
    {
        error_ = not_enough_object;
    }
    else
    {
        IOperand* ope1 = stack_.top();
        stack_.pop();
        IOperand* ope2 = stack_.top();
        stack_.pop();
        AObj* obj = static_cast< AObj* >(ope1->Divide(*ope2));
        if (obj)
        {
            stack_.push(obj);
        }
        else
        {
            error_ = divide_by_zero;
        }
    }
}

void Script::do_sub()
{
    if (stack_.size() < 2)
    {
        error_ = not_enough_object;
    }
    else
    {
        IOperand* ope1 = stack_.top();
        stack_.pop();
        IOperand* ope2 = stack_.top();
        stack_.pop();
        stack_.push(static_cast< AObj* >(ope1->Subtract(*ope2)));
    }
}

void Script::do_dump()
{
    while (!stack_.empty())
    {
        stack_.pop();
    }
}

void Script::do_pop()
{
    if (!stack_.empty())
    {
        stack_.pop();
    }
}

void Script::do_assert()
{
    AObj* arg = factory_.creat(instru_.argument, instru_.value);

    if (!arg)
    {
        error_ = unknow_type;
    }
    if (!(static_cast<IObject*>(stack_.top())->Equals(*arg)))
    {
        error_ = false_assert;
    }
}

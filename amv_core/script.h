#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>

class Script
{
    public:
        Script(std::string script);
        ~Script();
        bool getNextInstruction(std::string& new_instruction);
        int const& getError() const;
        void run();
    private:
        int error_;
};

#endif // SCRIPT_H

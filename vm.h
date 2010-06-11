#ifndef VM_H
#define VM_H

#include <stack>
#include "iobject.h"

class Vm
{
    public:
        Vm();
        ~Vm();
    private:
        std::stack< IObject* > objStack_;
};

#endif // VM_H

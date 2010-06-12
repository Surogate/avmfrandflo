#include "main.h"
#include "avm_elem.h"

// a sample exported function
AObj * getInstance()
{
    return new avm_elem();
}

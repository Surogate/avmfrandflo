#include "main.h"
#include "avm_double.h"

// a sample exported function
AObj * getInstance()
{
    return new avm_double();
}

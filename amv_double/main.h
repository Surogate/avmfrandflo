#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include "AObj.h"

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#define DLL_EXPORT __declspec(dllexport)

extern "C"
{
DLL_EXPORT AObj* getInstance();
}

#endif // __MAIN_H__

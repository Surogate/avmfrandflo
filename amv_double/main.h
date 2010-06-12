#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef WIN32
#include <windows.h>


#endif
#include "AObj.h"

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
extern "C"
{
DLL_EXPORT AObj* getInstance();
}

#endif // __MAIN_H__

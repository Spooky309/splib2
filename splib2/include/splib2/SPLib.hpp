/* date = December 14th 2021 8:21 pm */

/**
* This is the main header you want to include if you want to use splib.
*
* You can define the following constants
*
* SPLIB_PFN_HEADER: Header to include for alloc functions, and panic function
* SPLIB_MALLOC: Function for allocation
* SPLIB_FREE: Function for free
* SPLIB_REALLOC: Function for reallocation
* SPLIB_PANIC: Function to call on panic (receives exit code)
*/

#ifndef SPLIB_H
#define SPLIB_H

typedef char i8;
typedef unsigned char u8;
typedef short i16;
typedef unsigned short u16;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef decltype(sizeof(char)) size_t;

#ifndef SPLIB_ALLOC_HEADER
#define SPLIB_ALLOC_HEADER <stdlib.h>
#endif

#include SPLIB_ALLOC_HEADER

#ifndef SPLIB_MALLOC
#define SPLIB_MALLOC(Size) malloc(Size)
#endif

#ifndef SPLIB_FREE
#define SPLIB_FREE(Pointer) free(Pointer)
#endif

#ifndef SPLIB_REALLOC
#define SPLIB_REALLOC(Pointer, NewSize) realloc(Pointer, NewSize)
#endif

#ifndef SPLIB_PANIC
#define SPLIB_PANIC(ExitCode) exit(ExitCode)
#endif

extern void* operator new(size_t Size);
 
extern void operator delete(void* Pointer) noexcept;

enum
{
    SPLIB_EXIT_CODE_PANIC_ALLOC_FAIL = -1024
};

#ifndef INCLUDE_UTIL_HPP
#include "Util.hpp"
#endif
#ifndef INCLUDE_STRING_HPP
#include "String.hpp"
#endif

#endif //SPLIB_H

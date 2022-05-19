#include <splib2/SPLib.hpp>

void* operator new(size_t Size)
{
    if (Size == 0)
    {
        Size++;
    }
 
    void *ReturnValue = SPLIB_MALLOC(Size);
    if (ReturnValue != nullptr)
    {
        return ReturnValue;
    }
    SPLIB_PANIC(SPLIB_EXIT_CODE_PANIC_ALLOC_FAIL);
}
 
void operator delete(void* Pointer) noexcept
{
    SPLIB_FREE(Pointer);
}
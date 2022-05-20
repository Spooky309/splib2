#include <splib2/SPLib.hpp>
#include <string.h>

int FromCStr(int, char**)
{
    SPLib::String TestString = "Hi";
    if (strcmp(TestString.CString(), "Hi") != 0)
    {
        return 1;
    }
    if (TestString.Length() != 2)
    {
        return 2;
    }
    if (TestString.Capacity() != 3)
    {
        return 3;
    }
    return 0;
}
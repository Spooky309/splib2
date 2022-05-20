#include <splib2/SPLib.hpp>
#include <string.h>

int Constructors(int, char**)
{
    // String(const char*)
    SPLib::String cstr = "Hi";
    if (strcmp(cstr.CString(), "Hi") != 0) return 1;
    if (cstr.Length() != 2) return 2;
    if (cstr.Capacity() != 3) return 3;

    // String(bool)
    SPLib::String bstr = true;
    if (strcmp(bstr.CString(), "true") != 0) return 1;
    if (bstr.Length() != 4) return 2;
    if (bstr.Capacity() != 5) return 3;

    // String(int)
    SPLib::String istr = 1337;
    if (strcmp(istr.CString(), "1337") != 0) return 1;
    if (istr.Length() != 4) return 2;
    if (istr.Capacity() != 5) return 3;

    // we can't test string(float) because the results are unpredictable...

    // Copy constructor
    SPLib::String copystr(cstr);
    if (strcmp(copystr.CString(), "Hi") != 0) return 1;
    if (copystr.Length() != 2) return 2;
    if (copystr.Capacity() != 3) return 3;

    // Move constructor
    SPLib::String movestr(SPLib::Move(copystr));
    if (strcmp(movestr.CString(), "Hi") != 0) return 1;
    if (movestr.Length() != 2) return 2;
    if (movestr.Capacity() != 3) return 3;

    if (copystr.CString() != nullptr) return 1;

    return 0;
}
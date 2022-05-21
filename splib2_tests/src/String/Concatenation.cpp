#include <splib2/SPLib.hpp>
#include <string.h>

int Concatenation(int, char**)
{
    using namespace SPLib;
    String A = "AA";
    String B = "BB";
    String cat = A + B;
    if (strcmp(cat.CString(), "AABB") != 0) return 1;
    if (cat.Length() != 4) return 2;
    if (cat.Capacity() != 5) return 3;

    String cat2 = A;
    cat2 += B;
    if (strcmp(cat2.CString(), "AABB") != 0) return 1;
    if (cat2.Length() != 4) return 2;
    if (cat2.Capacity() != 5) return 3;

    String cat3 = Move(cat2);
    if (strcmp(cat3.CString(), "AABB") != 0) return 1;
    if (cat3.Length() != 4) return 2;
    if (cat3.Capacity() != 5) return 3;

    if (cat2.CString() != nullptr) return 1;
    if (cat2.Length() != 0) return 2;
    if (cat2.Capacity() != 0) return 3;

    return 0;
}
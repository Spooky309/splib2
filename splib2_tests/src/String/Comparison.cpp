#include <splib2/SPLib.hpp>

int Comparison(int, char**)
{
    using namespace SPLib;
    String A = "AABB";
    String B = "AA";
    String C = "BB";

    String D = B + C;
    if (A != D)
    {
        return 1;
    }
    if (A == B)
    {
        return 2;
    }
    return 0;
}
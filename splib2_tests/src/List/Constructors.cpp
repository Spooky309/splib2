#include <splib2/List.hpp>

int Constructors(int, char**)
{
    using namespace SPLib;
    List<int> ListA = {1, 2, 3, 4, 5};
    if (ListA.Count() != 5) return 1;
    for (u64 i = 0; i < 5; i++)
    {
        if (ListA[i] != (i + 1)) return 2;
    }

    return 0;
}
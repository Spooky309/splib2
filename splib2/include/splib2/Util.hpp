#ifndef INCLUDE_UTIL_HPP
#define INCLUDE_UTIL_HPP
#include <splib2/SPLib.hpp>

//! @cond Doxygen_Suppress

namespace SPLib
{
    template < class T > struct RemoveReference         { typedef T type; };
    template < class T > struct RemoveReference<T&>     { typedef T type; };
    template < class T > struct RemoveReference<T&&>    { typedef T type; };
    template < class T > using RemoveReferenceT = typename RemoveReference<T>::type;

    template < class T > constexpr RemoveReferenceT<T>&& Move(T& t)
    { return static_cast<typename RemoveReference<T>::type&&>(t); }
}

[[nodiscard]] inline void* operator new(size_t, void* __p) noexcept
{ return __p; }
[[nodiscard]] inline void* operator new[](size_t, void* __p) noexcept
{ return __p; }

inline void operator delete  (void*, void*) noexcept { }
inline void operator delete[](void*, void*) noexcept { }

//! @endcond

#endif
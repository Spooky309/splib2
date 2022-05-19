#ifndef INCLUDE_STRING_HPP
#define INCLUDE_STRING_HPP
#include <splib2/SPLib.hpp>

namespace SPLib
{
    class String
    {
    public:
        const char* CString();
        u64 Length();
        u64 Capacity();
        void Reserve(u64 Res);
        String();
        String(const char* Src);
        String(bool Src);
        String(int Src);
        String(float Src);
        ~String();
        String(const String& Other);
        String(String&& Other);
        String operator+(const String& Other);
        String& operator+=(const String& Other);
        String& operator=(String&& Other) = default;
        String& operator=(const String& Other) = default;
    private:
        char* m_Memory;
        u64 m_Length;
        u64 m_Capacity;
    };
    
}

#endif
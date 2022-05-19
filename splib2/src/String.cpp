#include <splib2/String.hpp>
#include <string.h>
#include <stdio.h>

namespace SPLib
{
    const char* String::CString()
    {
        return (const char*)m_Memory;
    }
    u64 String::Length()
    {
        return m_Length;
    }
    u64 String::Capacity()
    {
        return m_Capacity;
    }
    void String::Reserve(u64 Res)
    {
        if (Res == 0) return;
        m_Capacity += Res;
        m_Memory = (char*)SPLIB_REALLOC(m_Memory, m_Capacity);
    }

    String::String() : m_Memory(nullptr), m_Length(0), m_Capacity(0) {}

    String::String(const char* Src) : m_Memory(nullptr), m_Length(0), m_Capacity(0)
    {
        m_Length = strlen(Src);
        m_Capacity = m_Length + 1;
        m_Memory = (char*)SPLIB_MALLOC(m_Capacity);
        strcpy(m_Memory, Src); 
    }

    String::String(bool Src) : String::String(Src ? "true" : "false")
    { }

    String::String(int Src)   : m_Memory(nullptr), m_Length(0), m_Capacity(0)
    {
        int len = snprintf(nullptr, 0, "%d", Src);
        m_Capacity = len + 1;
        m_Length = len;
        m_Memory = (char*)SPLIB_MALLOC(m_Capacity);
        sprintf(m_Memory, "%d", Src);
    }

    String::String(float Src) : m_Memory(nullptr), m_Length(0), m_Capacity(0)
    {
        int len = snprintf(nullptr, 0, "%f", Src);
        m_Capacity = len + 1;
        m_Length = len;
        m_Memory = (char*)SPLIB_MALLOC(m_Capacity);
        sprintf(m_Memory, "%f", Src);
    }

    String::~String()
    {
        if (m_Memory != nullptr) SPLIB_FREE(m_Memory);
        m_Length = 0;
        m_Capacity = 0;
    }
    String::String(const String& Other) : m_Memory(nullptr), m_Length(0), m_Capacity(0)
    {
        m_Length = Other.m_Length;
        m_Capacity = Other.m_Capacity;
        if (m_Capacity != 0)
        {
            m_Memory = (char*)SPLIB_MALLOC(m_Capacity);
            strcpy(m_Memory, Other.m_Memory);
        }
    }
    String::String(String&& Other) : m_Memory(nullptr), m_Length(0), m_Capacity(0)
    {
        m_Length = Other.m_Length;
        m_Capacity = Other.m_Capacity;
        m_Memory = Other.m_Memory;
        Other.m_Memory = nullptr;
    }

    String String::operator+(const String& Other)
    {
        String ret;
        ret.m_Memory = nullptr;
        ret.m_Length = m_Length + Other.m_Length;
        ret.m_Capacity = ret.m_Length + 1;
        if (ret.m_Capacity != 0)
        {
            ret.m_Memory = (char*)SPLIB_MALLOC(ret.m_Capacity);
            if (m_Memory != nullptr) strcpy(ret.m_Memory, m_Memory);
            if (Other.m_Memory != nullptr) strcat(ret.m_Memory, Other.m_Memory);
        }
        return ret;
    }
    String& String::operator+=(const String &Other)
    {
        m_Length += Other.m_Length;
        if (m_Capacity < m_Length + 1)
        {
            m_Capacity =  m_Length + 1;
            if (m_Memory != nullptr)
            {
                m_Memory = (char*)SPLIB_REALLOC(m_Memory, m_Capacity);
            }
            else
            {
                m_Memory = (char*)calloc(m_Capacity, 1);
            }
        }
        if (Other.m_Memory != nullptr) strcat(m_Memory, Other.m_Memory);
        return *this;
    }
}
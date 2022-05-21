#ifndef INCLUDE_STRING_HPP
#define INCLUDE_STRING_HPP
#include <splib2/SPLib.hpp>

namespace SPLib
{
    /**
    * This is a string class, it stores ASCII strings ONLY right now (MBCS support pending).
    */
    class String
    {
    public:
        // Constructors

        /**
        * Constructs an empty string
        */
        String();

        /**
        * Constructs a new string from a C String
        *
        * @param[in] Src: Source to read string from
        */
        String(const char* Src);

        /**
        * Constructs a new string from a bool, where the result reads either "true" or "false"
        *
        * @param[in] Src: Bool to construct from
        */
        String(bool Src);

        /**
        * Constructs a new string from an integer.
        *
        * @param[in] Src: Integer to construct from
        */
        String(int Src);

        /**
        * Constructs a new string from a floating point value.
        *
        * @param[in] Src: Float to construct from
        */
        String(float Src);

        /**
        * Copy constructor. This will allocate new memory, and copy the string passed in up to the null byte.
        *
        * @param[in] Other: String to copy
        */
        String(const String& Other);

        /**
        * Move constructor. This will steal the memory from the string passed in, and leave it nullptr.
        */
        String(String&& Other);

        // Destructors

        /**
        * Destructor, this deallocates memory used by the string
        */
        ~String();

        // Mutation Operators

        /**
        * Concatenates two strings together.
        *
        * @param[in] Other: String to concatenate
        * @return Result of concatenation
        */
        String operator+(const String& Other);

        /**
        * Concatenates a string in-place, returning the result
        * @param[in] Other: String to concatenate
        * @return *this
        */
        String& operator+=(const String& Other);

        /**
        * Move assignment operator
        */
        String& operator=(String&& Other);

        /**
        * Copy assignment operator
        */
        String& operator=(const String& Other);

        // Comparison Operators
        
        /**
        * Equality check.
        *
        * This is the result of a comparison between the result of a strcmp between the underlying strings
        * and 0.
        */
        bool operator==(const String& Other) const;
        
        // Getters

        /**
        * Use this to get a pointer to the underlying data of the string
        *
        * @return Underlying string pointer, as const. This should not be modified.
        */
        const char* CString() const;

        /**
        * @return Length of the string up to the null byte
        */
        u64 Length() const;

        /**
        * @return Capacity of the string buffer
        */
        u64 Capacity() const;

        // Mutating functions
        
        /**
        * Pre-allocates space for the string, this will be used before any more allocations are issued.
        *
        * @param[in] Res: Requested reservation size increase
        */
        void Reserve(u64 Res);
    private:
        char* m_Memory;
        u64 m_Length;
        u64 m_Capacity;
    };
    
}

#endif
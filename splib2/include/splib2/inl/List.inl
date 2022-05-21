#ifndef INCLUDE_LIST_INL
#define INCLUDE_LIST_INL
#include "../List.hpp"
#endif

namespace SPLib
{
    // Constructors

    template < class T >
    List<T>::List()
        : m_Block(nullptr),
          m_Capacity(0),
          m_Count(0)
    {}

    template < class T >
    List<T>::List(std::initializer_list<T> InitList)
        : m_Block((T*)SPLIB_MALLOC(InitList.size() * sizeof(T))),
          m_Capacity(InitList.size()),
          m_Count(InitList.size())
    {
        u64 i = 0;
        for (auto it = InitList.begin(); it < InitList.end(); it++)
        {
            new (&m_Block[i]) T{*it};
            i++;
        }
    }

    template < class T >
    List<T>::List(const List<T>& Other)
        : m_Block((T*)SPLIB_MALLOC(Other.m_Count)),
          m_Capacity(Other.m_Count),
          m_Count(Other.m_Count)
    {
        for (u64 i = 0; i < Other.m_Count; i++)
        {
            new (&m_Block[i]) T{Other.m_Block[i]};
        }
    }

    template < class T >
    List<T>::List(List<T>&& Other)
        : m_Block(Other.m_Block),
          m_Capacity(Other.m_Capacity),
          m_Count(Other.m_Count)
    {
        Other.m_Block = nullptr;
        Other.m_Capacity = 0;
        Other.m_Count = 0;
    }

    // Destructors

    template < class T >
    List<T>::~List()
    {
        if (m_Block != nullptr)
        {
            for (u64 i = 0; i < m_Count; i++)
            {
                m_Block[i].~T();
            }
            SPLIB_FREE(m_Block);
            m_Block = nullptr;
        }
        m_Capacity = 0;
        m_Count = 0;
    }

    // Mutation Operators

    template < class T >
    List<T>& List<T>::operator=(const List<T>& Other)
    {
        if (m_Capacity >= Other.m_Count)
        {
            for (u64 i = 0; i < m_Count; i++)
            {
                m_Block[i].~T();
            }
            for (u64 i = 0; i < Other.m_Count; i++)
            {
                new (m_Block[i]) T{Other.m_Block[i]};
            }
            return *this;
        }
        // If we don't have the space to simply copy all the elements, do a destroy-and-reconstruct
        this->~List<T>();
        new (this) List<T>{Other};
        return *this;
    }

    template < class T >
    List<T>& List<T>::operator=(const List<T>&& Other)
    {
        this->~List<T>();
        new (this) List<T>{Other};
        return *this;
    }

    template < class T >
    T& List<T>::operator[](u64 Item)
    {
        return m_Block[Item];
    }

    // Getters
    template < class T >
    u64 List<T>::Capacity() const
    {
        return m_Capacity;
    }

    template < class T >
    u64 List<T>::Count() const
    {
        return m_Count;
    }

    // Mutating Functions

    template < class T >
    void List<T>::Reserve(u64 Num)
    {
        m_Capacity += Num;
        m_Block = (T*)SPLIB_REALLOC(m_Block, sizeof(T) * m_Capacity);
    }

    template < class T >
    void List<T>::Push(const T& NewItem)
    {
        if (m_Count == m_Capacity)
        {
            m_Capacity += AllocationBlockSize;
            m_Block = (T*)SPLIB_REALLOC(m_Block, sizeof(T) * m_Capacity);
        }
        new (&m_Block[m_Count]) T{NewItem};
        m_Count++;
    }

    template < class T >
    void List<T>::Push(T&& NewItem)
    {
        // Same as above... Since we defer to the underlying object constructor
        // We can trust that it either has a move constructor, or will defer to copy.
        if (m_Count == m_Capacity)
        {
            m_Capacity += AllocationBlockSize;
            m_Block = SPLIB_REALLOC(m_Block, sizeof(T) * m_Capacity);
        }
        new (&m_Block[m_Count]) T{NewItem};
        m_Count++;
    }

    template < class T >
    void List<T>::Push(const List<T>& Other)
    {
        for (u64 i = 0; i < Other.m_Count; i++)
        {
            Push(Other[i]);
        }
    }

    template < class T >
    void List<T>::Push(List<T>&& Other)
    {
        for (u64 i = 0; i < Other.m_Count; i++)
        {
            Push(Move(Other[i]));
        }
        if (Other.m_Block != nullptr) SPLIB_FREE(Other.m_Block);
        Other.m_Capacity = 0;
        Other.m_Count = 0;
    }

    template < class T >
    void List<T>::RemoveAt(u64 Item)
    {
        m_Block[Item].~T();
        for (u64 i = Item; i < m_Count; i++)
        {
            memcpy(&m_Block[i], &m_Block[i + 1], sizeof(T));
        }
        m_Count--;
    }
}
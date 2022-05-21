#ifndef INCLUDE_LIST_HPP
#define INCLUDE_LIST_HPP

#include <initializer_list> // We need this, it's integrated with the compiler tightly... ugh
#include "SPLib.hpp"

namespace SPLib
{
    /**
    * Generic List class, you can use this to store stuff dynamically.
    *
    * @tparam T: Class to store in this list
    */
    template < class T >
    class List
    {
    public:
        // Constructors

        /**
        * Construct an empty list
        */
        List();

        /**
        * Construct a list by copying elements from an array
        */
        List(std::initializer_list<T> InitList);

        /**
        * Copy constructor
        *
        * @param[in] Other: List to copy
        */
        List(const List<T>& Other);

        /**
        * Move constructor
        *
        * @param[in] Other: List to move
        */
        List(List<T>&& Other);
        // Destructors

        /**
        * Destroy the list, deallocating its memory and setting capacity and count to 0.
        *
        * This will also call destructors of all objects in the list
        */
        ~List();

        // Mutation Operators

        /**
        * Copy assignment operator
        *
        * @param[in] Other: List to copy
        * @return *this
        */
        List<T>& operator=(const List<T>& Other);

        /**
        * Move assignment operator
        *
        * @param[in] Other: List to Move
        * @return *this
        */
        List<T>& operator=(const List<T>&& Other);

        /**
        * Element access operator. This does not do range checking.
        *
        * @param[in] Item: Index of item to access
        * @return A mutable reference to that item
        */
        T& operator[](u64 Item);

        // Getters

        /**
        * @return List's current capacity
        */
        u64 Capacity() const;

        /**
        * @return List's current item count
        */
        u64 Count() const;

        // Mutating Functions

        /**
        * Pre-allocate space in the list
        *
        * @param[in] Items: Number of items to reserve
        */
        void Reserve(u64 Num);

        /**
        * Copy a new item onto the list
        *
        * @param[in] NewItem: A reference to the new item
        */
        void Push(const T& NewItem);

        /**
        * Move a new item onto the list
        *
        * @param[in] NewItem: An rvalue reference to the new item
        */
        void Push(T&& NewItem);

        /**
        * Copy another list to the end of this list
        *
        * @param[in] Other: A reference to the list to copy
        */
        void Push(const List<T>& Other);

        /**
        * Move another list to the end of this list
        *
        * @param[in] Other: An rvalue reference to the list to move
        */
        void Push(List<T>&& Other);

        /**
        * Remove an item from this list, calling its destructor
        *
        * @param[in] Item: Index of the item to remove
        */
        void RemoveAt(u64 Item);
    private:
        T* m_Block;
        u64 m_Capacity;
        u64 m_Count;
        constexpr static u64 AllocationBlockSize = 64;
    };
};

#ifndef INCLUDE_LIST_INL
#define INCLUDE_LIST_INL
#include "inl/List.inl"
#endif

#endif
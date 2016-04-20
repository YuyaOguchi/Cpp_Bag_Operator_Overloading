//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 3, Project 3
//  1/13/2016
//  Given code onlline for bag class.

#ifndef MAIN_SAVITCH_Chapter3Project2_H
#define MAIN_SAVITCH_Chapter3Project2_H
#include <cstdlib>

namespace main_savitch_3
{
    class bag
    {
    public:
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        bag( ) { used = 0; }
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const bag& addend);
        void operator -=(const bag& addend);
        size_type size( ) const { return used; }
        size_type count(const value_type& target) const;
    private:
        value_type data[CAPACITY];
        size_type used;
    };

    bag operator +(const bag& b1, const bag& b2);
    bag operator -(const bag& b1, const bag& b2);
}

#endif

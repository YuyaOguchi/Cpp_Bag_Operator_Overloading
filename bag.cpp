//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 3, Project 3
//  1/13/2016
//  Given code onlline for bag class.
#include <algorithm>
#include <cassert>
#include "bag.h"
using namespace std;

namespace main_savitch_3
{
    const bag::size_type bag::CAPACITY;

    bag::size_type bag::erase(const value_type& target)
    {
	size_type index = 0;
	size_type many_removed = 0;

	while (index < used)
	{
	    if (data[index] == target)
	    {
		--used;
		data[index] = data[used];
		++many_removed;
	    }
	    else
		++index;
	}

	return many_removed;
    }

    bool bag::erase_one(const value_type& target)
    {
	size_type index;

	index = 0;
	while ((index < used) && (data[index] != target))
	    ++index;

	if (index == used)
	    return false;
	--used;
	data[index] = data[used];
	return true;
    }

    void bag::insert(const value_type& entry)
    {
        assert(size( ) < CAPACITY);

        data[used] = entry;
	++used;
    }

    void bag::operator +=(const bag& addend)
    {
	assert(size( ) + addend.size( ) <= CAPACITY);

	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
    }

    bag::size_type bag::count(const value_type& target) const
    {
        size_type answer;
        size_type i;

        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }

    bag operator +(const bag& b1, const bag& b2)
    {
        bag answer;

        assert(b1.size( ) + b2.size( ) <= bag::CAPACITY);

        answer += b1;
        answer += b2;
        return answer;
    }
}

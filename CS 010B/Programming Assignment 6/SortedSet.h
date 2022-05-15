#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"

class SortedSet : public IntList
{
public:
    SortedSet();                     // done
    SortedSet(const SortedSet &set); // done
    SortedSet(const IntList &list);  // done
    ~SortedSet();                    // done
    // accessors;
    bool in(int value) const;                        // done
    SortedSet operator|(const SortedSet &rhs) const; // done
    SortedSet operator&(const SortedSet &rhs) const; // done
    // //mutators
    void add(int value);                         // done
    void push_front(int value);                  // done
    void push_back(int value);                   // done
    void insert_ordered(int value);              // done
    SortedSet &operator|=(const SortedSet &rhs); // done
    SortedSet &operator&=(const SortedSet &rhs); // done
};

#endif

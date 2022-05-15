#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"

class SortedSet : public IntList {
public:
    SortedSet(); //done
    SortedSet(const SortedSet &set); //done
    SortedSet(const IntList &list); //done
    // ~SortedSet();
    // //accessors
    bool in(int value) const; //done
    // SortedSet operator|(const &lhs, const &rhs) const;
    // SortedSet operator&(const &lhs, const &rhs) const;
    // //mutators
    void add(int value); //done
    void push_front(int value);
    void push_back(int value);
    // void insert_ordered (int value);
    // SortedSet operator|=(const &rhs);
    // SortedSet operator &=(const &rhs);
};

#endif

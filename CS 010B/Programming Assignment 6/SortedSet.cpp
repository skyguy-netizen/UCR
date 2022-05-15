#include "SortedSet.h"
#include <iostream>

// default constructor
SortedSet::SortedSet()
{
    IntList();
}

// SortedSet(const SortedSet)
SortedSet::SortedSet(const SortedSet &set) : IntList(set) {}
// IntList(set)
// IntList *temp = set;
///.......
// saying its protected
// so cannot access...

// SortedSet(const IntList)
SortedSet::SortedSet(const IntList &list) : IntList(list)
{
    selection_sort();
    remove_duplicates();
}

// destructor
SortedSet::~SortedSet() {}

// overridden push_back() function
void SortedSet::push_back(int value)
{

    add(value);
}

// in() function
bool SortedSet::in(int value) const
{
    IntNode *temp = head;
    while (temp != nullptr)
    {
        if (temp->value == value)
        {
            return true;
        }
        temp = temp->next;
    }
    temp = nullptr;

    return false;
}

// the big add() function
void SortedSet::add(int value)
{
    if (head == nullptr)
    {
        IntNode *currObj = new IntNode(value);
        head = currObj;
        tail = currObj;
    }
    else if (value <= head->value)
    {
        if (value < head->value)
        {
            IntList::push_front(value);
        }
        else
        {
            return;
        }
    }
    else if (value >= tail->value)
    {
        if (value > tail->value)
        {
            IntList::push_back(value);
        }
        else
        {
            return;
        }
    }
    else
    {
        IntNode *currObj = new IntNode(value);
        IntNode *curr = head->next;
        IntNode *prev = head;
        while (prev != nullptr && value >= curr->value)
        {
            curr = curr->next;
            prev = prev->next;
        }
        if (prev->value != value)
        {
            prev->next = currObj;
            currObj->next = curr;
        }
        else
        {
            delete currObj;
        }
    }
}

// overridden push_front() function
void SortedSet::push_front(int value)
{
    add(value);
}

// overridden insert_ordered() function
void SortedSet::insert_ordered(int value)
{
    add(value);
}

// operator| function
SortedSet SortedSet::operator|(const SortedSet &rhs) const
{
    // std::cout << "rhs: " << rhs << std::endl;
    SortedSet temp(rhs);
    // std::cout << temp << std::endl;
    IntNode *curr = head;
    while (curr != nullptr)
    {
        if (!temp.in(curr->value))
        {
            temp.add(curr->value);
        }
        curr = curr->next;
    }
    return temp;
}

// operator& function
SortedSet SortedSet::operator&(const SortedSet &rhs) const
{
    IntNode *tempNode = rhs.head;
    SortedSet tempSet;
    while (tempNode != nullptr)
    {
        if (in(tempNode->value))
        {
            tempSet.add(tempNode->value);
        }
        tempNode = tempNode->next;
    }
    return tempSet;
}

// operator |= function
SortedSet &SortedSet::operator|=(const SortedSet &rhs)
{
    // SortedSet *tempSet = new SortedSet(*this | rhs);
    // *this = *tempSet;
    // cout << temp << std::endl;
    // if (head == nullptr)
    // {
    //     *this = temp;
    // }
    // else
    // {
    //     // IntNode *curr = head;
    //     IntNode *copier = temp.head;
    //     std::cout << "Seg test before loop" << std::endl;
    //     while (copier != nullptr)
    //     {
    //         std::cout << "Seg test in loop" << std::endl;
    //         this->add(copier->value);
    //         copier = copier->next;
    //         std::cout << "Seg test in loop after assignment" << std::endl;
    //     }
    // }
    // delete tempSet;
    // SortedSet tempSet = *this | rhs;
    // delete this;
    *this = *this | rhs;
    return *this;
}

SortedSet &SortedSet::operator&=(const SortedSet &rhs)
{
    // SortedSet *temp = new SortedSet();
    // *temp = *this & rhs;
    // *this = *temp;
    // delete temp;
    // return *this;
    // *this = *this & rhs;
    // SortedSet *temp = this;
    // *this = *temp | rhs;
    // SortedSet *tempSet = new SortedSet(*this & rhs);
    // *this = *tempSet;
    // delete tempSet;
    // return *this;
    *this = *this & rhs;
    // *this = tempSet;
    return *this;
}
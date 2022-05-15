#include "SortedSet.h"

SortedSet::SortedSet()
{
    IntList();
}

SortedSet::SortedSet(const SortedSet &set) : IntList(set) {}
// IntList(set)
// IntList *temp = set;
///.......
// saying its protected
// so cannot access...

SortedSet::SortedSet(const IntList &list) : IntList(list)
{
    selection_sort();
    remove_duplicates();
}

void SortedSet::push_back(int value)
{

    add(value);
}

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
    }
    else if (value >= tail->value)
    {
        if (value > tail->value)
        {
            IntList::push_back(value);
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

void SortedSet::push_front(int value)
{
    add(value);
}

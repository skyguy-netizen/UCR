#include "IntList.h"
#include <iostream>

using namespace std;

IntList::~IntList()
{
    IntNode *temp = dummyHead;
    while (temp != dummyTail)
    {
        IntNode *next = temp->next;
        delete temp;
        temp = next;
    }
    delete temp;
}
void IntList::push_front(int value)
{
    IntNode *temp = new IntNode(value);
    IntNode *head = dummyHead->next;
    temp->prev = dummyHead;
    temp->next = head;
    head->prev = temp;
    dummyHead->next = temp;
}
void IntList::pop_front()
{
    IntNode *toPop = dummyHead->next;
    dummyHead->next = toPop->next;
    dummyHead->next->next->prev = dummyHead;
    delete toPop;
}
void IntList::push_back(int value)
{
    IntNode *temp = new IntNode(value);
    IntNode *tail = dummyTail->prev;
    temp->prev = tail;
    temp->next = dummyTail;
    dummyTail->prev = temp;
    tail->next = temp;
}
void IntList::pop_back()
{
    IntNode *toPop = dummyTail->prev;
    dummyTail->prev = toPop->prev;
    toPop->prev->next = dummyTail;
    delete toPop;
}
bool IntList::empty() const
{
    return (dummyHead->next == dummyTail && dummyTail->prev == dummyHead);
}
void IntList::printReverse() const
{
    if (!empty())
    {
        IntNode *temp = dummyTail->prev;
        while (temp->prev != dummyHead)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << temp->data;
    }
}

ostream &operator<<(ostream &out, const IntList &rhs)
{
    if (!rhs.empty())
    {
        IntNode *temp = rhs.dummyHead->next;
        while (temp->next != rhs.dummyTail)
        {
            out << temp->data << " ";
            temp = temp->next;
        }
        out << temp->data;
        return out;
    }
    else
    {
        out << "";
        return out;
    }
}
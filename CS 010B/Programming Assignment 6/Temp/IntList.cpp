#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList()
{
    if (head != nullptr)
    {
        IntNode *currObj = head;
        IntNode *temp = nullptr;
        while (currObj != nullptr)
        {
            temp = currObj;
            currObj = currObj->next;
            delete (temp);
        }
    }
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList &rhs)
{
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        IntNode *newObj = new IntNode(rhs.head->value);
        head = newObj;
        tail = newObj;
        // IntNode *copier = head->next;
        // IntNode *curr = rhs.head;
        // while (curr != nullptr)
        // {
        //     cout << "Test" << endl;
        //     IntNode *newNode = new IntNode(curr->value);
        //     copier = newNode;
        //     copier = copier->next;
        //     curr = curr->next;
        // }
        // cout << "Test 2" << endl;
        // tail = curr;
        // cout << "Test 3" << endl;
        // cout << "Test 4" << endl;
        // IntNode *p = head;
        // while (p != nullptr)
        // {
        //     cout << p->value << endl;
        //     p = p->next;
        // }
        IntNode *curr = rhs.head->next;
        while (curr != nullptr)
        {
            // cout << "test " << curr->value << endl;
            // //this->push_back(curr->value);
            // ta
            // IntNode *p = head;
            // while (p != nullptr)
            // {
            //     cout << p->value << endl;
            //     p = p->next;
            // }
            IntNode *newNode = new IntNode(curr->value);
            tail->next = newNode;
            tail = newNode;
            curr = curr->next;
        }
        curr = nullptr;
    }
}

IntList &IntList::operator=(const IntList &rhs)
{
    if (this != &rhs)
    {
        if (rhs.head == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            IntNode *temp = new IntNode(rhs.head->value);
            head = temp;
            tail = temp;
            IntNode *curr = rhs.head->next;
            while (curr != nullptr)
            {
                IntNode *newNode = new IntNode(curr->value);
                tail->next = newNode;
                tail = newNode;
                curr = curr->next;
            }
        }
    }

    return *this;
}

void IntList::push_front(int value)
{
    IntNode *newNode = new IntNode(value);
    // cout << "newnode value: " << newNode->value << endl;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        // cout << newNode->value << endl;
        head = newNode;
        // cout << head->value << ' ' << head->next->value << endl;
        // IntNode* currObj = head;
        //  while (currObj != nullptr){
        //      cout << head->value << " ";
        //      currObj = currObj->next;
        //  }
        //  cout << endl;
    }
}

void IntList::pop_front()
{
    if (head != nullptr)
    {
        IntNode *curr = head->next;
        delete head;
        head = curr;
        if (empty())
        {
            head = nullptr;
            tail = nullptr;
        }
    }
    // cout << head << " " << tail << endl;
}

bool IntList::empty() const
{
    if (head == nullptr)
    {
        return true;
    }

    return false;
}

const int &IntList::front() const
{
    return head->value;
}

const int &IntList::back() const
{
    return tail->value;
}

ostream &operator<<(ostream &out, const IntList &rhs)
{
    // out << list.head->value;
    if (rhs.head != nullptr)
    {
        IntNode *currObj = rhs.head;
        while (currObj->next != nullptr)
        {
            out << currObj->value << " ";
            currObj = currObj->next;
        }
        out << currObj->value;
    }
    else
    {
        out << "";
    }

    return out;
}

void IntList::push_back(int value)
{
    IntNode *newNode = new IntNode(value);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::clear()
{
    if (head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        IntNode *currObj = head;
        while (currObj != nullptr)
        {
            IntNode *temp = currObj;
            currObj = currObj->next;
            delete temp;
        }
        head = currObj;
        tail = currObj;
    }
}

void IntList::selection_sort()
{
    IntNode *currObj = head;
    IntNode *min = head;
    while (currObj != nullptr && min != nullptr)
    {
        IntNode *nextObj = currObj;
        min = currObj;
        while (nextObj != nullptr)
        {
            if (nextObj->value < min->value)
            {
                min = nextObj;
            }
            nextObj = nextObj->next;
        }
        int temp = currObj->value;
        currObj->value = min->value;
        min->value = temp;

        currObj = currObj->next;
    }
}

void IntList::insert_ordered(int value)
{
    // IntNode *currObj = new IntNode(value);
    if (head == nullptr)
    {
        IntNode *currObj = new IntNode(value);
        head = currObj;
        tail = currObj;
    }
    else if (value <= head->value)
    {
        push_front(value);
    }
    else if (value >= tail->value)
    {
        push_back(value);
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
        prev->next = currObj;
        currObj->next = curr;
    }
}

void IntList::remove_duplicates()
{
    IntNode *currObj = head;
    IntNode *toDelete = nullptr;
    while (currObj != nullptr)
    {
        IntNode *nextObj = currObj;
        while (nextObj->next != nullptr)
        {
            if (currObj->value == nextObj->next->value)
            {
                if (nextObj->next == tail)
                {
                    toDelete = nextObj->next;
                    tail = nextObj;
                    tail->next = nullptr;
                    delete toDelete;
                }
                else
                {
                    toDelete = nextObj->next;
                    nextObj->next = nextObj->next->next;
                    delete toDelete;
                }
            }
            else
            {
                nextObj = nextObj->next;
            }
        }
        currObj = currObj->next;
    }

    // while (currObj != nullptr)
    // {
    //     IntNode *curr = currObj;
    //     while (curr->next != nullptr)
    //     {
    //         IntNode *next = curr;
    //         if (next->value == currObj->value)
    //         {
    //             if (next == tail)
    //             {
    //                 IntNode *temp = curr;
    //                 tail = curr;
    //                 delete temp;
    //             }
    //             else
    //             {
    //                 IntNode *temp = curr;
    //                 next = next->next;
    //                 curr = curr->next;
    //                 delete temp;
    //             }
    //         }
    //         else
    //         {
    //             next = next->next;
    //             curr = curr->next;
    //         }
    //     }
    //     currObj = currObj->next;
    // }
}
// while (currObj != nullptr)
// {
//     IntNode *prev = currObj;
//     IntNode *nextNode = currObj->next;
//     while (nextNode != nullptr)
//     {
//         if (currObj->value == nextNode->value)
//         {
//             if (nextNode == tail)
//             {
//                 delete tail;
//                 prev->next = nullptr;
//                 tail = currObj;
//                 nextNode = nullptr;
//             }
//             else
//             {
//                 IntNode *temp = nextNode->next;
//                 delete nextNode;
//                 nextNode = temp;
//                 prev->next = nextNode;
//                 prev = prev->next;
//             }
//         }
//         else
//         {
//             nextNode = nextNode->next;
//             prev = prev->next;
//         }
//     }
//     currObj = currObj->next;
// }
// il)
//             {
//                 delete tail;
//                 prev->next = nullptr;
//                 tail = currObj;
//                 nextNode = nullptr;
//             }
//             else
//             {
//                 IntNode *temp = nextNode->next;
//                 delete nextNode;
//                 nextNode = temp;
//                 prev->next = nextNode;
//                 prev = prev->next;
//             }
//         }
//         else
//         {
//             nextNode = nextNode->next;
//             prev = prev->next;
//         }
//     }
//     currObj = currObj->next;
// }

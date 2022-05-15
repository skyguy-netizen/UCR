#include "IntList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

bool IntList::bubbleUp()
{
   return bubbleUp(head);
}

bool IntList::bubbleUp(IntNode *curr)
{
   // IntList list = *this;
   bool checker;
   if (curr == nullptr)
   {
      return false;
   }
   else if (curr->next == nullptr)
   {
      return false;
   }
   else
   {
      // IntNode *next = curr->next;
      //  cout << "Test" << endl;
      // bubbleUp(curr->next);
      // cout << "Test" << endl;
      checker = bubbleUp(curr->next);
      cout << "Checker: " << checker << "......";
      if (curr->next->value < curr->value)
      {
         // cout << curr->value << " " << curr->next->value << "......";
         swap(curr->value, curr->next->value);
         // bubbleUp(curr->next); doing this creates a sorting algorithm
         // cout << *this << endl;
         return true;
      }
      cout << "List: " << *this << endl;
   }
   // if (list == *this)
   // {
   //    return true;
   // }
   // else
   // {
   //    return false;
   // }
   return checker;
}

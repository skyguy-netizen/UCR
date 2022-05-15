#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val)
{
   if (!head)
   {
      head = new IntNode(val);
   }
   else
   {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream &operator<<(ostream &out, const IntList &list)
{
   // IntNode *temp = list.head;
   out << "";
   if (!list.head)
   {
      return out;
   }
   else
   {
      out << list.head;
      return out;
   }
}
ostream &operator<<(ostream &out, IntNode *node)
{
   if (!node)
   {
      return out;
   }
   else
   {
      if (node->next == nullptr)
      {
         out << node->value;
         out << node->next;
      }
      else
      {
         out << node->value << " ";
         out << node->next;
      }
   }
   return out;
}

bool IntList::exists(int val) const
{
   // bool checker = false;
   // IntNode *temp = this->head;
   // if (temp == nullptr && temp != this->head)
   // {
   //    return exists(temp, val);
   // }
   // else if (temp == head && temp == nullptr)
   // {
   //    return false;
   // }
   if (exists(head, val))
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool IntList::exists(IntNode *node, int val) const
{
   bool checker = false;
   if (node == nullptr)
   {
      checker = false;
   }
   else if (node->value == val)
   {
      checker = true;
   }
   else
   {
      checker = exists(node->next, val);
   }
   return checker;
}
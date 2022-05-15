#include "IntList.h"
#include "SortedSet.h"

#include <iostream>
using namespace std;

int main()
{
   cout << "Test 1: tests constructor, destructor, push_front, pop_front, display" << endl;
   cout << "Test 2: tests push_back" << endl;
   cout << "Test 3: tests selection_sort" << endl;
   cout << "Test 4: insert_sorted" << endl;
   cout << "Test 5: tests remove_duplicates" << endl;
   cout << "Test 6: tests copy constructor and assingment operator for IntList" << endl;
   cout << "Test 7: tests pop_front & push_back for special cases" << endl;
   cout << "Test 8: tests functions of the SortedSet class" << endl;
   cout << "Test 9: tests union, intersection, union-assignment, intersection-assignment" << endl;
   cout << "Enter a test number(1-9): ";
   int test;
   cin >> test;
   cout << endl;
   // tests constructor, destructor, push_front, pop_front, display
   if (test == 1)
   {
      cout << endl;
      cout << "list1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
   }
   if (test == 1)
   {
      cout << "list1 destructor called" << endl;
   }

   // tests push_back
   if (test == 2)
   {
      cout << endl;
      cout << "list2 constructor called" << endl;
      IntList list2;
      cout << "pushback 10" << endl;
      list2.push_back(10);
      cout << "pushback 20" << endl;
      list2.push_back(20);
      cout << "pushback 30" << endl;
      list2.push_back(30);
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
      cout << "pop" << endl;
      list2.pop_front();
      cout << "list2: " << list2 << endl;
   }
   if (test == 2)
   {
      cout << "list2 destructor called" << endl;
   }

   // tests selection_sort
   if (test == 3)
   {
      cout << endl;
      cout << "list3 constructor called" << endl;
      IntList list3;
      cout << "pushfront 10" << endl;
      list3.push_front(10);
      cout << "pushfront 20" << endl;
      list3.push_front(20);
      cout << "pushfront 30" << endl;
      list3.push_front(30);
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      // me
      list3.push_front(45);
      list3.push_front(234);
      list3.push_back(-23);
      list3.push_back(-232);
      list3.push_back(0);
      list3.push_front(2423);
      cout << "Me list3(old): " << list3 << endl;
      list3.selection_sort();
      cout << "Me list3(new): " << list3 << endl;
      // me

      cout << "pop" << endl;
      list3.pop_front();
      cout << "pop" << endl;
      list3.pop_front();
      cout << "pop" << endl;
      list3.pop_front();
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      cout << "pushfront 10" << endl;
      list3.push_front(10);
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
      cout << "pushfront 20" << endl;
      list3.push_front(20);
      cout << "list3: " << list3 << endl;
      cout << "selection_sort()" << endl;
      list3.selection_sort();
      cout << "list3: " << list3 << endl;
   }
   if (test == 3)
   {
      cout << "list3 destructor called" << endl;
   }

   // tests insert_sorted
   if (test == 4)
   {
      cout << endl;
      cout << "list4 constructor called" << endl;
      IntList list4;
      cout << "insert 20" << endl;
      list4.insert_ordered(20);
      cout << "List: " << list4 << endl; // me
      cout << "insert 10" << endl;
      list4.insert_ordered(10);
      cout << "List: " << list4 << endl; // me
      cout << "insert 30" << endl;
      list4.insert_ordered(30);
      cout << "List: " << list4 << endl; // me
      cout << "list4: " << list4 << endl;
      cout << "insert 50" << endl;
      list4.insert_ordered(50);
      cout << "list4: " << list4 << endl;
      cout << "insert 40" << endl;
      list4.insert_ordered(40);
      cout << "list4: " << list4 << endl;
      cout << "insert 11" << endl;
      list4.insert_ordered(11);
      cout << "list4: " << list4 << endl;
      cout << "insert 10" << endl;
      list4.insert_ordered(10);
      cout << "list4: " << list4 << endl;
      cout << "insert 11" << endl;
      list4.insert_ordered(11);
      cout << "list4: " << list4 << endl;
      cout << "insert 9" << endl;
      list4.insert_ordered(9);
      cout << "list4: " << list4 << endl;
      cout << "insert 50" << endl;
      list4.insert_ordered(50);
      cout << "list4: " << list4 << endl;
      cout << "insert 51" << endl;
      list4.insert_ordered(51);
      cout << "list4: " << list4 << endl;
   }
   if (test == 4)
   {
      cout << "list4 destructor called" << endl;
   }

   // tests remove_duplicates
   if (test == 5)
   {
      cout << endl;
      cout << "list5 constructor called" << endl;
      IntList list5;
      cout << "pushfront 10" << endl;
      list5.push_front(10);
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "pushfront 10" << endl;
      list5.push_front(10);
      cout << "pushfront 30" << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 10" << endl;
      cout << "List5 back()..should be 20: " << list5.back() << endl;
      list5.push_front(10);
      cout << "List5 back()..should be 20: " << list5.back() << endl;
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "pushfront 20" << endl;
      list5.push_front(20);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pop" << endl;
      list5.pop_front();
      cout << "pop" << endl;
      list5.pop_front();
      cout << "push_front(30)" << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      // me
      cout << "List5 back()..should be 30: " << list5.back() << endl;
      cout << "list5: " << list5 << endl;
      cout << "push_front(30)" << endl;
      list5.push_front(30);
      cout << "List5 back()..should be 30: " << list5.back() << endl;
      cout << "push_front(30)" << endl;
      cout << "List5 back()..should be 30: " << list5.back() << endl;
      list5.push_front(30);
      cout << "list5: " << list5 << endl;
      // me
      cout << "List5 back should be 30: " << list5.back() << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
      cout << "pop" << endl;
      list5.pop_front();
      cout << "list5: " << list5 << endl;
      cout << "remove_duplicates()" << endl;
      list5.remove_duplicates();
      cout << "list5: " << list5 << endl;
   }
   if (test == 5)
   {
      cout << "list5 destructor called" << endl;
   }

   /*
    * Destructor will be tested by looking at code. There is no run-time
    * test for it. Make sure your destructor actually deletes ALL nodes, not
    * just the head and/or tail.
    */

   // tests copy constructor and assingment operator for IntList
   if (test == 6)
   {
      IntList list;
      list.push_back(-425352);
      list.push_back(234235434);
      list.push_back(-34);
      list.push_back(34);
      list.push_back(23);
      list.push_back(56);
      list.push_back(3);
      list.push_back(-3);
      cout << "Before seg fault:" << list << endl;
      IntList list2 = list;
      cout << "After where previous seg fault:" << list2 << endl;
      // IntList list2;
      list2.push_back(3234);
      cout << "pushback 3234: " << list2 << endl;
      list2.selection_sort();
      cout << "After sorting:" << list2 << endl;
      list2.insert_ordered(323);
      cout << "After inserting 323:" << list2 << endl;
      cout << "Final List1: " << list << endl;
      cout << "Final List2: " << list2 << endl;

      cout << "Testing assignment:" << endl;
      IntList list3;
      list3.push_back(-4);
      list3.push_back(5);
      list3.push_back(-3);
      list3.push_back(4);
      list3.push_back(3);
      list3.push_back(6);
      list3.push_back(3);
      list3.push_back(-3);
      IntList list4;
      cout << "Assigning" << endl;
      list4 = list3;
      cout << "List3: " << list3 << endl;
      cout << "List4: " << list4 << endl;
      cout << "Changing list4: ";
      list4.insert_ordered(5);
      list4.push_back(3);
      list4.push_back(-3);
      cout << list4 << endl;

      cout << "Empty list copy" << endl;
      IntList list5;
      IntList list6 = list5;
      cout << "Empty list copy with assignment" << endl;
      IntList list7;
      IntList list8;
      list7 = list8;
   }

   // tests pop_front & push_back for special cases
   if (test == 7)
   {
      IntList list1;
      cout << "Head and tail on empty list: ";
      list1.pop_front();
      list1.push_back(1);
      cout << endl;
      cout << "Head and tail after empty list: ";
      list1.pop_front();
      list1.push_back(2);
      list1.push_front(3);
      cout << endl;
      cout << "Head and tail after non-empty list: ";
      list1.pop_front();
      cout << endl;
   }

   // tests functions of the SortedSet class
   if (test == 8)
   {
      cout << "Testing SortedSet class" << endl;
      cout << "Set1: ";
      SortedSet set1;
      cout << set1 << endl;
      set1.push_back(1);
      set1.push_back(1);
      set1.push_back(1);
      set1.push_back(1);
      cout << "Testing constructor with set passed as parameter" << endl;
      cout << "set1: ";
      SortedSet set2(set1);
      cout << set1 << endl;
      cout << "set2: ";
      cout << set2 << endl;
      cout << "Testing constructor with list passed as parameter" << endl;
      IntList list1;
      list1.push_back(1);
      list1.push_back(2);
      list1.push_back(3);
      list1.push_back(4);
      list1.push_back(6);
      SortedSet set3(list1);
      cout << "List:" << list1 << endl;
      cout << "Set: " << set3 << endl;
      cout << "Testing add function (when value passed in already exists)..passing in 3" << endl;
      cout << "Old set: " << set3 << endl;
      set3.add(3);
      cout << "New set: " << set3 << endl;
      cout << "Testing add function (when value passed doesn't already exists) passing in 5" << endl;
      cout << "Old set: " << set3 << endl;
      set3.add(5);
      cout << "New set: " << set3 << endl;
      cout << "Testing add function with empty set" << endl;
      SortedSet emptySet;
      cout << "Old set: " << emptySet << endl;
      emptySet.add(3);
      cout << "New set: " << emptySet << endl;
      cout << "Testing add function when just one element exists: " << endl;
      cout << "Old set: " << emptySet << endl;
      emptySet.add(1);
      cout << "New set: " << emptySet << endl;
      cout << "Testing add function when passed in value to be inserted at back" << endl;
      cout << "Old set: " << emptySet << endl;
      emptySet.add(4);
      cout << "New set: " << emptySet << endl;
      cout << "Testing push front function (pushing 3 to the front)" << endl;
      cout << "Old set: " << set3 << endl;
      set3.push_front(3);
      cout << "New set: " << set3 << endl;
      cout << "Testing push front where value pushed is equal to head (1)" << endl;
      cout << "Old set: " << set3 << endl;
      set3.push_front(1);
      cout << "New set: " << set3 << endl;
      SortedSet set4;
      cout << "Testing push front on empty set" << endl;
      cout << "Old set: " << set4 << endl;
      set4.add(2);
      cout << "New set: " << set4 << endl;
      cout << "Testing operator<< function" << endl;
      SortedSet set5;
      set5.add(-62);
      set5.add(-34);
      set5.add(-5);
      set5.add(8);
      set5.add(13);
      set5.add(40);
      set5.add(52);
      set5.add(53);
      set5.add(136);
      set5.add(147);
      set5.add(200);
      cout << "Set: " << set5 << endl;
      cout << "Test insert_ordered y inserting -62" << endl;
      cout << "Old set: " << set5 << endl;
      set5.insert_ordered(-62);
      cout << "New set: " << set5 << endl;

      SortedSet set7;
      set7.push_front(-97);
      set7.add(-91);
      set7.push_back(-22);
      set7.add(46);
      set7.push_front(193);
      set7.add(112);
      set7.add(46);
      set7.push_back(49);
      cout << "Set7: " << set7 << endl;
      SortedSet set6 = SortedSet(set7);
      cout << "Set6: " << set6 << endl;
      cout << endl;
   }
   if (test == 8)
   {
      cout << "Destructor called" << endl;
   }

   // tests
   if (test == 9)
   {
      SortedSet set5;
      set5.add(-62);
      set5.add(-34);
      set5.add(-5);
      set5.add(8);
      set5.add(13);
      set5.add(40);
      set5.add(52);
      set5.add(53);
      set5.add(136);
      set5.add(147);
      set5.add(200);

      SortedSet set7;
      set7.push_front(-97);
      set7.add(-91);
      set7.push_back(-22);
      set7.add(46);
      set7.push_front(193);
      set7.add(112);
      set7.add(46);
      set7.push_back(49);

      cout << "Operator testing" << endl;

      cout << "Testing union operator" << endl;
      SortedSet set1 = SortedSet(set5);
      cout << "Set1: " << set1 << endl;
      SortedSet set2 = SortedSet(set7);
      cout << "Set2: " << set2 << endl;
      SortedSet set3 = set1 | set2;
      cout << "set1 | set2: " << set3 << endl;

      cout << "Testing union operator with common elements" << endl;
      SortedSet set11 = SortedSet(set5);
      cout << "Set11: " << set11 << endl;
      SortedSet set12 = SortedSet(set5);
      cout << "Set12: " << set12 << endl;
      SortedSet set13 = set11 | set12;
      cout << "set11 | set12: " << set13 << endl;

      cout << "Testing intersection operator" << endl;
      set5.add(9);
      set5.add(323);
      set5.add(-3);
      set5.add(3);
      set7.add(9);
      set7.add(323);
      set7.add(-3);
      set7.add(3);
      cout << "Set5: " << set5 << endl;
      cout << "Set7: " << set7 << endl;
      SortedSet set4 = set5 & set7;
      cout << "Set5 & Set7: " << set4 << endl
           << endl;
      cout << "Testing union assignment operator with empty set" << endl;
      SortedSet set8;
      cout << "Set8: " << set8 << endl;
      cout << "Set7: " << set7 << endl;
      set8 |= set7;
      cout << "Set8 |= Set7 gives Set8: " << set8 << endl;
      cout << "Testing union assignment operator without empty set (have cleared set8)" << endl;
      SortedSet set9;
      set9.add(1); // giving mem leak
      set9.add(2); // giving mem leak
      cout << "Set9: " << set9 << endl;
      cout << "Set7: " << set7 << endl;
      set9 |= set7;
      cout << "Set8 |= Set7 gives Set9: " << set9 << endl;
      cout << endl;
      cout << "Testing intersection assignment operator with empty set" << endl;
      set8.clear();
      cout << "Set8: " << set8 << endl;
      cout << "Set7: " << set7 << endl;
      set8 &= set7;
      cout << "Set8 &= Set7 gives Set8: " << set8 << endl;
      cout << "Testing union assignment operator without empty set (have cleared set8)" << endl;
      set8.clear();
      set8.add(1);   // giving mem leak
      set8.add(2);   // giving mem leak
      set8.add(-97); // giving mem leak
      set8.add(3);   // giving mem leak
      cout << "Set8: " << set8 << endl;
      cout << "Set7: " << set7 << endl;
      set8 &= set7;
      cout << "Set8 &= Set7 gives Set8: " << set8 << endl;
      set7.add(2323);
      cout << "Set7: " << set7 << endl;
      cout << "Set8: " << set8 << endl;
   }

   if (test == 9)
   {
      cout << "Destructor called" << endl;
   }

   return 0;
}

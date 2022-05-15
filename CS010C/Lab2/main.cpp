#include <iostream>
#include "IntList.h"

using namespace std;

int main()
{
    IntList list1;
    // out << list1.empty() << endl;
    list1.push_front(1);
    list1.push_back(2);
    cout << list1 << endl;
    list1.printReverse();
    // cout << "test" << endl;
    // list1.push_back(8);
    // list1.push_back(15);
    // list1.push_back(23);
    // list1.push_back(23);
    // list1.push_back(3);
    // cout << list1 << endl;
}

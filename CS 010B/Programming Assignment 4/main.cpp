#include <iostream>
#include "IntVector.h"

using namespace std;

int main()
{

    IntVector v = IntVector(3, 4);
    // cout << "Old data: ";
    // for (unsigned int i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i) << " ";
    // }
    // cout << endl;

    // v.insert(2, 4);

    // cout << "Size: ";
    // cout << v.size() << endl;

    // cout << "NEW DATA ACCESSED IN MAIN: " << endl;
    // for (unsigned int i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i) << endl;
    // }

    // return 0;

    cout << "Original vector: ";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl << endl;

    cout << "Size: ";
    cout << v.size() << endl << endl;

    cout << "Front of vector: " << v.front() << endl << endl;

    cout << "Back of vector: " << v.back() << endl << endl;

    cout << "Changing front of vector: ";
    v.front() = 2;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl << endl;

    cout << "Changing back of vector: ";
    v.back() = 3;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl << endl;

    //at() accessor function
    cout << "Changing element at index 1 => " << endl;
    cout << "-> Old values: ";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    v.at(1) = 7;

    cout << "-> New values: ";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }

    cout << endl << endl;
    cout << "Inserting a new value 6 at index 2: " << endl;
    cout << "-> Old values: ";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> Old capacity: " << v.capacity() << endl;
    cout << "-> Old size: " << v.size() << endl;

    v.insert(2, 6);

    cout << "-> New values: ";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> New capacity: " << v.capacity() << endl;
    cout << "-> New size: " << v.size() << endl;

    cout << "Inserting a new value -1 at index 3: " << endl;
    cout << "-> Old values: ";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> Old capacity: " << v.capacity() << endl;
    cout << "-> Old size: " << v.size() << endl;

    v.insert(3, -1);

    cout << "-> New values: ";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> New capacity: " << v.capacity() << endl;
    cout << "-> New size: " << v.size() << endl << endl;

    // cout << "Insert function: ";
    // v.insert(3, 8);
    // for (unsigned int i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i) << " ";
    // }
    // cout << endl;
    cout << endl;

    //erase() function
    cout << "Testing erase function: " << endl;
    cout << "-> Old values: ";
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> Old size: " << v.size() << endl;

    v.erase(2);

    cout << "-> New values: ";
    for (unsigned i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> New size: " << v.size() << endl << endl;

    //assign() function
    cout << "Testing assign function: " << endl;
    cout << "-> Test 1 where n is greater than _capacity * 2: " << endl;
    cout << "---> Old values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "---> Old size: " << v.size() << endl;
    cout << "---> Old capacity: " << v.capacity() << endl;

    v.assign(13,2);

    cout << "---> New values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "---> New size: " << v.size() << endl;
    cout << "---> New capacity: " << v.capacity() << endl;

    v.assign(6,4);
    v.at(0) = 3;
    v.at(1) = 2;
    v.at(2) = -1;
    v.at(4) = 23;
    v.at(5) = -22;
    v.at(3) = 22;

    cout << endl;

    cout << "-> Test 2 where n is less than _capacity * 2: " << endl;
    cout << "---> Old values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "---> Old size: " << v.size() << endl;
    cout << "---> Old capacity: " << v.capacity() << endl;

    v.assign(8,2);

    cout << "---> New values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "---> New size: " << v.size() << endl;
    cout << "---> New capacity: " << v.capacity() << endl << endl;


    //push_back() function
    cout << "Testing push_back() function: " << endl;
    cout << "-> Old values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> Old size: " << v.size() << endl;
    cout << "-> Old capacity: " << v.capacity() << endl;

    v.push_back(7);
    v.push_back(-3224414);

    cout << "-> New values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> New size: " << v.size() << endl;
    cout << "-> New capacity: " << v.capacity() << endl << endl;


    //pop_back() function
    cout << "Testing pop_back() function: " << endl;
    cout << "-> Old values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> Old size: " << v.size() << endl;
    cout << "-> Old capacity: " << v.capacity() << endl;

    v.pop_back();
    v.pop_back();

    cout << "-> New values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> New size: " << v.size() << endl;
    cout << "-> New capacity: " << v.capacity() << endl << endl;


    //resize() function
    cout << "Testing resize() function: " << endl;
    cout << "-> Test 1 where given size is more than old size: " << endl;
    cout << "---> Old values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "---> Old size: " << v.size() << endl;
    cout << "---> Old capacity: " << v.capacity() << endl;

    v.resize(12,5);

    cout << "---> New values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "---> New size: " << v.size() << endl;
    cout << "---> New capacity: " << v.capacity() << endl;


    cout << "-> Test 2 where given size is less than old size: " << endl;
    cout << "---> Old values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "---> Old size: " << v.size() << endl;
    cout << "---> Old capacity: " << v.capacity() << endl;

    v.resize(7);

    cout << "---> New values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "---> New size: " << v.size() << endl;
    cout << "---> New capacity: " << v.capacity() << endl << endl;


    //clear() function
    cout << "Testing clear() function: ";
    cout << "-> Old values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> Old size: " << v.size() << endl;
    cout << "-> Old capacity: " << v.capacity() << endl;

   	v.clear();

    cout << "-> New values: ";
    for (unsigned i = 0; i < v.size(); i++){
    	cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "-> New size: " << v.size() << endl;
    cout << "-> New capacity: " << v.capacity() << endl << endl;

    IntVector v1 = IntVector(6,1);
    v1.assign(13,5);
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;

    IntVector v2 = IntVector();
    //v2.insert(1,5);

    return 0;
}

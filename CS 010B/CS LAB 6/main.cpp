
#include <iostream>
#include "IntVector.h"

using namespace std;

int main()
{
    //     cout << "Test for code run" << endl;
    //     IntVector *vector = new IntVector(2, 3);
    //     cout << "Test for size of vector: " << vector->size() << endl;

    //     cout << "Vector[0]: " << vector->at(0) << endl;
    //     cout << "Vector[1]: " << vector->at(1) << endl;

    //     for (int i = 0; i < vector->size(); i++)
    //     {
    //         cout << "Vector[" << i << "]: " << vector->at(i);
    //         cout << " " << vector->at(i) << endl;
    //     }

    //     cout << "Test 2 to check if issue with for loop" << endl;

    // cout << "Testing Vector Class" << endl;

    // constructing object with pointer
    cout << "Constructing pointer for our vector" << endl;
    IntVector *vector = new IntVector(4, 5);

    // size() function test
    cout << "Testing size function: ";
    if (vector->size() == 4)
    {
        cout << "TEST PASSED" << endl;
    }
    else
    {
        cout << "TEST FAILED" << endl;
    }

    // capacity() function test
    cout << "Testing capacity function: ";
    if (vector->capacity() == 4)
    {
        cout << "TEST PASSED" << endl;
    }
    else
    {
        cout << "TEST FAILED" << endl;
    }

    // empty() function test
    cout << "Testing empty function: ";
    if (vector->empty() == false)
    {
        cout << "TEST PASSED" << endl;
    }
    else
    {
        cout << "TEST FAILED" << endl;
    }
    // cout << vector->size() << endl;
    // cout << vector->at(0) << endl;
    // cout << vector->at(1) << endl;
    // cout << vector->at(2) << endl;

    // at() function test
    for (unsigned i = 0; i < vector->size(); i++)
    {
        cout << "Vector.at(" << i << "): " << vector->at(i) << endl;
    }

    // front() function check
    cout << "Testing front() function: ";
    if (vector->front() == 5)
    {
        cout << "TEST PASSED" << endl;
    }
    else
    {
        cout << "TEST FAILED" << endl;
    }

    // back() function check
    cout << "Testing back() function: ";
    if (vector->back() == 5)
    {
        cout << "TEST PASSED" << endl;
    }
    else
    {
        cout << "TEST FAILED" << endl;
    }

    // trying to access out of range elements in vector
    // cout << "Vector.at(3): " << vector->at(3) << endl; // working checked

    // cout << vector->size() << endl;

    delete vector;
    // // cout << vector->size() << endl;

    // int n1, n2;
    // cin >> n1 >> n2;
    // IntVector *vector = new IntVector();
    // IntVector *vector2 = new IntVector(n1);
    // IntVector *vector3 = new IntVector(n1, n2);

    // cout << "Sizes: " << vector->size() << "  " << vector2->size() << " " << vector3->size() << endl;
    // cout << "Capacity: " << vector->capacity() << " " << vector2->capacity() << " " << vector3->capacity() << endl;
    // cout << "Front: " << vector->front() << " " << vector2->front() << " " << vector3->front

    return 0;
}
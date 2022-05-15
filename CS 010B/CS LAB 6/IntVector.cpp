#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

IntVector::IntVector(unsigned capacity, int value)
{
    _capacity = capacity;
    if (capacity > 0)
    {
        _size = capacity;
        _data = new int[capacity];
        for (unsigned i = 0; i < _size; i++)
        {
            _data[i] = value;
        }
    }
    else
    {
        _capacity = 0;
        _size = 0;
        _data = nullptr;
    }
}

IntVector::~IntVector()
{
    // cout << "Destructor constructed" << endl;
    // int *head = nullptr;
    // // cout << endl
    // //      << "Size before destructor: " << _size << endl;
    // for (unsigned i = 0; i < _size; i++)
    // {
    //     head = &_data[i];
    //     // cout << "Deleting " << &_data[i] << endl;
    //     delete head;
    // }
    delete[] _data;
    // cout << "Size after destructor: " << _size << endl;
}

const int &IntVector::at(unsigned int index) const
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return _data[index];
    }
}

unsigned IntVector::size() const
{
    return _size;
}

unsigned IntVector::capacity() const
{
    return _capacity;
}

bool IntVector::empty() const
{
    return (_size == 0);
}

const int &IntVector::front() const
{
    return _data[0];
}

const int &IntVector::back() const
{
    return _data[_size - 1];
}

// int IntVector::_data1() const
// {
//     return *(_data + 4);
// }
#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

// Constructor
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

// Destructor
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

// at() function

const int &IntVector::at(unsigned index) const
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::at_range_check");
        exit(1);
    }
    else
    {
        return _data[index];
    }
}

int &IntVector::at(unsigned index)
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::at_range_check");
        exit(1);
    }
    else
    {
        return _data[index];
    }
}

// size() function
unsigned IntVector::size() const
{
    return _size;
}

// capacity() function
unsigned IntVector::capacity() const
{
    return _capacity;
}

// empty() function
bool IntVector::empty() const
{
    return (_size == 0);
}

// front() function
const int &IntVector::front() const
{
    return _data[0];
}

int &IntVector::front()
{
    return _data[0];
}

// back() function
const int &IntVector::back() const
{
    return _data[_size - 1];
}

int &IntVector::back()
{
    return _data[_size - 1];
}

// insert() function
void IntVector::insert(unsigned index, int value)
{
    if (index > _size)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    else
    {
        // cout << "In insert function: ";
        // for (unsigned i = 0; i < _capacity; ++i)
        // {
        //     cout << _data[i] << " ";
        // }
        // cout << endl;
        if (_size == _capacity)
        {
            expand();
        }
        _size++;
        unsigned i;
        for (i = _size - 1; i > index; i--)
        {
            _data[i] = _data[i - 1];
        }
        _data[i] = value;
    }
}

void IntVector::expand()
{
    if (_capacity == 0)
    {
        _capacity = 1;
    }
    else
    {
        _capacity = _capacity * 2;
    }

    int *temp = new int[_capacity];
    // cout << "New _data: ";
    // for (unsigned i = 0; i < _capacity; i++)
    // {
    //     cout << _data[i] << " ";
    // }

    for (unsigned i = 0; i < _size; i++)
    {
        temp[i] = _data[i];
    }

    delete[] _data;
    _data = temp;

    // cout << "In expand function: ";
    // for (unsigned i = 0; i < _capacity; i++)
    // {
    //     cout << _data[i] << " ";
    // }
    // cout << endl;
    // cout << endl
    //      << "Temp: ";
    // for (unsigned i = 0; i < _size; i++)
    // {
    //     cout << temp[i] << " ";
    // }
    // cout << endl
    // cout << "New _data with actual _data:" << endl;
    // for (unsigned i = 0; i < _size; i++)
    // {
    //     _data[i] = *(temp + i);
    // }
    // for (unsigned i = 0; i < _size; i++)
    // {
    //     cout << _data[i] << " ";
    // }
    // cout << endl;
    // delete[] temp;
}

void IntVector::expand(unsigned amount)
{
    _capacity += amount;

    int *temp = new int[_capacity];
    // cout << "New _data: ";
    // for (unsigned i = 0; i < _capacity; i++)
    // {
    //     cout << _data[i] << " ";
    // }

    for (unsigned i = 0; i < _size; i++)
    {
        temp[i] = _data[i];
    }

    delete[] _data;
    _data = temp;
}

// erase() function
void IntVector::erase(unsigned index)
{
    if (index >= _size || index < 0)
    {
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i < _size; i++)
    {
        _data[i] = _data[i + 1];
    }
    _size--;
}

// assign() function
void IntVector::assign(unsigned n, int value)
{
    if (n > _capacity)
    {
        unsigned temp = n - _capacity;
        if (temp > _capacity * 2)
        {
            expand(temp);
        }
        else
        {
            expand();
            if (_capacity < n)
            {
                expand(n - _capacity);
            }
        }
    }

    _size = n;
    for (unsigned i = 0; i < _size; i++)
    {
        _data[i] = value;
    }
}

// push_back() function
void IntVector::push_back(int value)
{
    if (_size == _capacity || _size + 1 > _capacity)
    {
        expand();
    }

    _data[_size] = value;
    _size++;
}

// pop_back() function
void IntVector::pop_back()
{
    _size--;
}

// clear() function
void IntVector::clear()
{
    _size = 0;
}

// resize() function
void IntVector::resize(unsigned size, int value)
{
    if (size > _capacity)
    {
        unsigned temp = size - _capacity;
        if (temp > _capacity * 2)
        {
            expand(temp);
        }
        else
        {
            expand();
            if (_capacity < size)
            {
                expand(size - _capacity);
            }
        }
    }

    if (size < _size)
    {
        _size = size;
    }
    else
    {
        for (unsigned i = _size; i < size; i++)
        {
            _data[i] = value;
        }
        _size = size;
    }
}

// reserve() function
void IntVector::reserve(unsigned n)
{
    if (n > _capacity)
    {
        _capacity = n;
    }
}

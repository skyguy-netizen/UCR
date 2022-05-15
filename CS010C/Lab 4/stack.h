#ifndef STACK_H
#define STACK_H
// #include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 20;

template <typename T>
class stack
{
private:
    T data[MAX_SIZE];
    int size;

public:
    stack()
    {
        size = 0;
    }
    void push(T val)
    {
        try
        {
            if (size >= MAX_SIZE)
            {
                throw overflow_error("Called push on full stack.");
            }
            data[size] = val;
            size++;
        }
        catch (overflow_error &err)
        {
            cout << err.what() << endl;
            exit(1);
        }
    }
    void pop()
    {
        try
        {
            if (size == 0)
            {
                throw out_of_range("Called pop on empty stack.");
            }
            size--;
        }
        catch (out_of_range &err)
        {
            cout << err.what() << endl;
            exit(1);
        }
    }

    void pop_two()
    {
        try
        {
            if (size == 0)
            {
                throw out_of_range("Called pop_two on empty stack");
            }
            else if (size == 1)
            {
                throw out_of_range("Called pop_two on a stack of size 1.");
            }
            size -= 2;
        }
        catch (out_of_range &err)
        {
            cout << err.what() << endl;
            exit(1);
        }
    }

    bool empty()
    {
        return size == 0;
    }

    T top()
    {
        try
        {
            if (empty())
            {
                throw underflow_error("Called top on empty stack.");
            }
            return data[size - 1];
        }
        catch (underflow_error &err)
        {
            cout << err.what() << endl;
            exit(1);
        }
    }
};
#endif
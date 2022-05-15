#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector
{
private:
    unsigned _size;
    unsigned _capacity;
    int *_data;

public:
    IntVector(unsigned capacity = 0, int value = 0); // implemented
    ~IntVector();                                    // implemented
    unsigned size() const;                           // implemented
    unsigned capacity() const;                       // implemented
    bool empty() const;                              // implemented
    const int &at(unsigned index) const;             // implemented
    const int &front() const;
    const int &back() const;
    // int data1() const; // implemented
};

#endif
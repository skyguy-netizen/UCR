#ifndef INTVECTOR_h
#define INTVECTOR_h

class IntVector
{
private:
    unsigned _size;
    unsigned _capacity;
    int *_data;
    void expand();                // done
    void expand(unsigned amount); // done

public:
    IntVector(unsigned capacity = 0, int value = 0); // done
    ~IntVector();                                    // done
    unsigned size() const;                           // done
    unsigned capacity() const;                       // done
    bool empty() const;                              // done
    const int &at(unsigned index) const;             // done
    int &at(unsigned index);                         // done
    void insert(unsigned index, int value);          // done
    void erase(unsigned index);                      // done
    const int &front() const;                        // done
    int &front();                                    // done
    const int &back() const;                         // done
    int &back();                                     // done
    void assign(unsigned n, int value);              // done
    void push_back(int value);                       // done
    void pop_back();                                 // done
    void clear();                                    // done
    void resize(unsigned size, int value = 0);       // done
    void reserve(unsigned n);                        //
};

#endif
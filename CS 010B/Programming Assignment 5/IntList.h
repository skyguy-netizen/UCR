#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode
{
	int value;
	IntNode *next;
	IntNode(int value) : value(value), next(nullptr) {}
};

class IntList
{

	friend ostream &operator<<(ostream &, const IntList &rhs); // done

private:
	IntNode *head;
	IntNode *tail;

public:
	IntList();								// done
	~IntList();								// done
	IntList(const IntList &cpy);			// done
	void push_front(int);					// done
	void pop_front();						// done
	bool empty() const;						// done
	const int &front() const;				// done
	const int &back() const;				// done
	IntList &operator=(const IntList &rhs); // done
	void push_back(int value);				// done
	void clear();							// done
	void selection_sort();					// done
	void insert_ordered(int value);			// done
	void remove_duplicates();				// done
};

#endif

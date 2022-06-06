#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>

using namespace std;

class Node
{
private:
    string value;
    Node *left;
    Node *right;
    int count;

public:
    Node() : value(0), left(0), right(0), count(0) {}
    Node(string value, Node *left, Node *right, int count) : value(value), left(left), right(right), count(count) {}
    Node *getLeft() { return left; }
    Node *getRight() { return right; }
    void setLeft(Node *left) { this->left = left; }
    void setRight(Node *right) { this->right = right; }
    string getData() const { return value; }
    void setData(string value) { this->value = value; }
    int getCount() const { return count; }
    // void incrementCount() { this->count += 1; }
    // void decrementCount() { this->count -= 1; }
    void setCount(int count) { this->count = count; }
};

#endif
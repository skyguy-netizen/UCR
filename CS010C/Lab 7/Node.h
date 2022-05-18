#ifndef NODE_H
#define NODE_H

// #include <cstring>
#include <iostream>

using namespace std;

class Node
{
private:
    string data;
    Node *left;
    Node *right;
    Node *parent;
    int height;

public:
    Node(string data) : data(data), left(nullptr), right(nullptr), parent(nullptr), height(0){};
    Node(string data, Node *left, Node *right, Node *parent) : data(data), left(left), right(right), parent(parent){};
    Node *getLeft() { return left; }
    Node *getRight() { return right; }
    Node *getParent() { return parent; }
    Node *getHeight() { return height; }
    string getData() { return data; }
    void setParent(Node *parent) { this->parent = parent; };
    int getHeight()
    {
        return height;
    }
};

#endif
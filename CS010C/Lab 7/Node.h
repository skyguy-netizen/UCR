#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
private:
    string data;
    Node *left;
    Node *right;
    Node *parent;
    int balanceFactor;

public:
    Node(string data) : data(data), left(nullptr), right(nullptr), parent(nullptr), balanceFactor(0){};
    Node(string data, Node *left, Node *right, Node *parent) : data(data), left(left), right(right), parent(parent){};
    Node *getLeft();
    Node *getRight();
    Node *getParent();
    string getData(){return data;}
    int balanceFactor() { return balanceFactor; }
    void setParent(Node *parent);
};

#endif
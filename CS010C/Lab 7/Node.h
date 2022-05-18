#ifndef NODE_H
#define NODE_H

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
}

#endif
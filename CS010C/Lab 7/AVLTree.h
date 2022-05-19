#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"
#include <string>
#include <fstream>

using namespace std;

class AVLTree
{
private:
    Node *root;

public:
    AVLTree(Node *root = 0) : root(root){};
    void insert(const string &val);
    void printBalanceFactors();
    int BalanceFactor(Node *node);
    void visualizeTree(const string &);

private:
    void visualizeTree(ofstream &outFS, Node *n);
    bool empty();
    void balanceTree(Node *root);
    void rotateRight(Node *node);
    void rotateLeft(Node *node);
    void printBalanceFactors(Node *root);
    void updateHeight(Node *node);
};

#endif
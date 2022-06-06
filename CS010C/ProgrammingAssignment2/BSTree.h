#ifndef __BSTREE_H__
#define __BSTREE_H__
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;
class BSTree
{
private:
    Node *root;

public:
    /* Constructors */
    /* Default constructor */
    BSTree(); // done
    ~BSTree();
    void insert(const string &newString); // done
    void remove(const string &key);
    bool search(const string &key); // done
    string largest() { return root ? minVal(this->root) : ""; }
    string smallest() { return root ? maxVal(this->root) : ""; }
    int height(const string &);
    void preOrder();
    void postOrder();
    void inOrder();

    // private helper functions
private:
    Node* search(Node *node, const string &key);
    void preOrder(Node *node);
    void postOrder(Node *node);
    void inOrder(Node *node);
    void deleteNode(Node *node);
    Node* insert(Node *node, const string &key);
    int heightOfTree(Node *node);
    Node* remove(Node *node, const string &key);
    string minVal(Node *root);
    string maxVal(Node *node);
};

#endif // __BSTREE_H__
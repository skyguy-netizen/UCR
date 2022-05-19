#include "AVLTree.h"
#include <fstream>
#include <iostream>

using namespace std;

// public member functions
void AVLTree::insert(const string &val)
{
    if (empty())
    {
        root = new Node(val);
    }

    Node *curr = root;
    while (curr != nullptr && curr->getData() != val)
    {
        if (curr->getData() < val)
        {
            curr = curr->getLeft();
        }
        else
        {
            curr = curr->getRight();
        }
    }
    if (curr->getLeft() != nullptr)
    {
        curr->setLeft(new Node(val));
        curr->getLeft()->setParent(curr);
        curr = curr->getLeft();
    }
    else if (curr->getRight() != nullptr)
    {
        curr->setRight(new Node(val));
        curr->getRight()->setParent(curr);
        curr = curr->getRight();
    }
    else
    {
        return;
    }

    while (curr != nullptr)
    {
        balanceTree(curr);
        curr = curr->getParent();
    }
}
void AVLTree::printBalanceFactors()
{
    printBalanceFactors(root);
}

void AVLTree::printBalanceFactors(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    printBalanceFactors(root->getLeft());
    cout << BalanceFactor(root) << " ";
    printBalanceFactors(root->getRight());
}

int AVLTree::BalanceFactor(Node *node)
{

    int leftHeight = -1;
    if (node->getLeft() != NULL)
    {
        leftHeight = node->getLeft()->getHeight();
    }
    int rightHeight = -1;
    if (node->getRight() != NULL)
    {
        rightHeight = node->getRight()->getHeight();
    }
    return leftHeight - rightHeight;
}

void AVLTree::visualizeTree(const string &outputFilename)
{
    ofstream outFS(outputFilename.c_str());
    if (!outFS.is_open())
    {
        cout << "Error" << endl;
        return;
    }
    outFS << "digraph G {" << endl;
    visualizeTree(outFS, root);
    outFS << "}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

// private helper functions

void AVLTree::visualizeTree(ofstream &outFS, Node *n)
{
    if (n)
    {
        if (n->getLeft())
        {
            visualizeTree(outFS, n->getLeft());
            outFS << n->getData() << " -> " << n->getLeft()->getData() << ";" << endl;
        }

        if (n->getRight())
        {
            visualizeTree(outFS, n->getRight());
            outFS << n->getData() << " -> " << n->getRight()->getData() << ";" << endl;
        }
    }
}
bool AVLTree::empty()
{
    return (root == nullptr);
}

void AVLTree::balanceTree(Node *root)
{
    updateHeight(root);
    if (BalanceFactor(root) == -2)
    {
        if (BalanceFactor(root->getRight()) == 1)
        {
            rotateRight(root->getRight());
        }
        rotateLeft(root);
    }
    else if (BalanceFactor(root) == 2)
    {
        if (BalanceFactor(root->getLeft()) == -1)
        {
            rotateLeft(root->getLeft());
        }
        rotateRight(root);
    }
}

void AVLTree::updateHeight(Node *root)
{
    int leftHeight = -1;
    if (root->getLeft() != nullptr)
    {
        leftHeight = root->getLeft()->getHeight();
    }
    int rightHeight = -1;
    if (root->getRight() != nullptr)
    {
        rightHeight = root->getRight()->getHeight();
    }
    root->setHeight(max(leftHeight, rightHeight));
}

void AVLTree::rotateLeft(Node *root)
{
    if (root->getParent() != nullptr)
    {
        Node *temp = root->getParent();
        temp->setRight(root->getRight());
        Node *newRight = temp->getRight()->getLeft();
        temp->getRight()->setLeft(root);
        root->setRight(newRight);
    }
    else
    {
        Node *temp = root;
        Node *newRight = temp->getRight()->getLeft();
        this->root = temp;
        this->root->setLeft(temp);
        temp->setRight(newRight);
    }
}

void AVLTree::rotateRight(Node *root)
{
    if (root->getParent() != nullptr)
    {
        Node *temp = root->getParent();
        temp->setLeft(root->getLeft());
        Node *newLeft = temp->getLeft()->getRight();
        temp->getLeft()->setRight(root);
        root->setLeft(newLeft);
    }
    else // node is root
    {
        Node *temp = root;
        Node *newLeft = temp->getLeft()->getRight();
        this->root = temp;
        this->root->setRight(temp);
        temp->setLeft(newLeft);
    }
}

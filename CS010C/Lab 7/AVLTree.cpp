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
        return;
    }

    Node *curr = root;
    Node *storeCurr = curr;
    // while (curr != nullptr && curr->getData() != val)
    // {
    //     cout << "Inside while" << endl;
    //     if (curr->getData() < val)
    //     {
    //         curr = curr->getLeft();
    //     }
    //     else
    //     {
    //         curr = curr->getRight();
    //     }
    // }
    // cout << "Outside while" << endl;
    // curr = new Node(val);
    while (curr != nullptr)
    {
        if (val < curr->getData())
        {
            if (curr->getLeft() == nullptr)
            {
                curr->setLeft(new Node(val));
                curr->getLeft()->setParent(curr);
                storeCurr = curr;
                curr = nullptr;
            }
            else
            {
                curr = curr->getLeft();
            }
        }
        else
        {
            if (curr->getRight() == nullptr)
            {
                curr->setRight(new Node(val));
                curr->getRight()->setParent(curr);
                storeCurr = curr;
                curr = nullptr;
            }
            else
            {
                curr = curr->getRight();
            }
        }
    }

    // cout << "Entering second while" << endl;
    curr = storeCurr;
    while (curr != nullptr)
    {
        // cout << "Test" << endl;
        if (curr == root){
            cout << "Inside root rotate" << endl;
            balanceTree(curr);
            curr = nullptr;
        }
        else {
            balanceTree(curr);
            curr = curr->getParent();
        }
        // cout << "Inside while" << endl;
    }
    // balanceTree(curr);
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
    // cout << "Test" << endl;
    root->setHeight(updateHeight(root));
    printBalanceFactors(root->getLeft());
    cout << root->getData() << "(" << BalanceFactor(root) << "), ";
    printBalanceFactors(root->getRight());
}

int AVLTree::BalanceFactor(Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    int leftHeight = -1;
    if (node->getLeft() != NULL)
    {
        leftHeight = updateHeight(node->getLeft());
    }
    int rightHeight = -1;
    if (node->getRight() != NULL)
    {
        // node->getRight()->setHeight(updateHeight(node));
        rightHeight = updateHeight(node->getRight());
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
    root->setHeight(updateHeight(root));
    // cout << "Inside balanceTree" << endl;
    // cout << root->getData() << " balance factor is  " << BalanceFactor(root) << endl;
    if (BalanceFactor(root) == -2)
    {
        // cout << "Inside balanceTree for node " << root->getData() << endl;
        if (BalanceFactor(root->getRight()) == 1)
        {
            cout << "Inside if" << endl;
            rotateRight(root->getRight());
        }
        rotateLeft(root);
    }
    else if (BalanceFactor(root) == 2)
    {
        // cout << "test" << endl;
        if (BalanceFactor(root->getLeft()) == -1)
        {
            rotateLeft(root->getLeft());
        }
        rotateRight(root);
    }
}

int AVLTree::updateHeight(Node *root)
{
    // int leftHeight = -1;
    // if (root->getLeft() != nullptr)
    // {
    //     leftHeight = root->getLeft()->getHeight();
    // }
    // int rightHeight = -1;
    // if (root->getRight() != nullptr)
    // {
    //     rightHeight = root->getRight()->getHeight();
    // }
    // root->setHeight(max(leftHeight, rightHeight));
    // cout << root->getData() << " height: " << root->getHeight() << endl;
    if (root == nullptr)
    {
        return -1;
    }
    return 1 + max(updateHeight(root->getLeft()), updateHeight(root->getRight()));
}

void AVLTree::rotateLeft(Node *root)
{
    // cout << "Inside rotate left" << endl;
    if (root->getParent() != nullptr)
    {
        Node *temp = root->getParent();
        if (temp->getLeft() == root){
            temp->setLeft(root->getRight());
            temp->getLeft()->setParent(temp);
            Node *newRight = root->getRight()->getLeft();
            temp->getLeft()->setLeft(root);
            root->setParent(temp->getLeft());
            root->setRight(newRight);
            if (newRight != nullptr){
                newRight->setParent(root);
            }
        }
        else if (temp->getRight() == root)
        {
            cout << "Inside not root rotate for node " << root->getData() << endl;
            temp->setRight(root->getRight());
            temp->getRight()->setParent(temp);
            Node *newRight = root->getRight()->getLeft();
            temp->getRight()->setLeft(root);
            root->setParent(temp->getRight());
            root->setRight(newRight);
            if (newRight != nullptr){
                newRight->setParent(root);
            }
        }
    }
    else // node is root
    {
        // cout << "Inside root rotate" << endl;
        Node *temp = root;
        Node *newRight = temp->getRight()->getLeft();
        this->root = temp->getRight();
        this->root->setLeft(temp);
        temp->setParent(this->root);
        // cout << "Test" << endl;
        temp->setRight(newRight);
        // cout << "Test" << endl;
        if (newRight != nullptr) {
            newRight->setParent(temp);
        }
        // cout << "Test" << endl;
    }
}

void AVLTree::rotateRight(Node *root)
{
    // cout << "Test" << endl;
    if (root->getParent() != nullptr)
    {
        Node *temp = root->getParent();
        if (temp->getLeft() == root){
            temp->setLeft(root->getLeft());
            temp->getLeft()->setParent(temp);
            Node *newLeft = root->getLeft()->getRight();
            temp->getLeft()->setRight(root);
            root->setParent(temp->getLeft());
            root->setLeft(newLeft);
            if (newLeft != nullptr){
                newLeft->setParent(root);
            }
        }
        else if (temp->getRight() == root)
        {
            temp->setRight(root->getLeft());
            temp->getRight()->setParent(temp);
            Node *newLeft = root->getLeft()->getRight();
            temp->getRight()->setRight(root);
            root->setParent(temp->getRight());
            root->setLeft(newLeft);
            if (newLeft != nullptr){
                newLeft->setParent(root);
            }
        }
    }
    else // node is root
    {
        // cout << "Inside root rotate" << endl;
        Node *temp = this->root;
        Node *newLeft = temp->getLeft()->getRight();
        this->root = temp->getLeft();
        this->root->setRight(root);
        temp->setParent(this->root);
        temp->setLeft(newLeft);
        if (newLeft != nullptr){
            newLeft->setParent(temp);
        }
    }
}

#include "BSTree.h"
#include <cstdlib>

using namespace std;

BSTree::BSTree()
{
    root = nullptr;
}
BSTree::~BSTree(){
    deleteNode(root);
}

// insert function
void BSTree::insert(const string &newString)
{
    // if (root == nullptr)
    // {
    //     root = new Node(newString, 0, 0, 1);
    //     return;
    // }
    // Node *temp = root;
    // while (temp != nullptr || temp->getData() != newString)
    // {
    //     if (temp->getData() < newString)
    //     {
    //         temp = temp->getRight();
    //     }
    //     else if (temp->getData() > newString)
    //     {
    //         temp = temp->getLeft();
    //     }
    // }
    // if (temp != NULL && temp->getData() == newString)
    // {
    //     temp->incrementCount();
    // }
    // else
    // {
    //     temp = new Node(newString, 0, 0, 1);
    // }
    // return;
    root = insert(root, newString);
}

Node* BSTree::insert(Node *node, const string &key){
    //cout << "Test" << endl;
    if (node == nullptr){
        node = new Node(key, nullptr, nullptr, 1);
        // cout << node->getData() << endl;
        return node;
    }
    else {
        if (node->getData() > key){
            node->setLeft(insert(node->getLeft(), key));
            return node;
        }
        else if (node->getData() < key) {
            node->setRight(insert(node->getRight(), key));
            return node;
        }
        else {
            node->setCount(node->getCount() + 1);
            return node;
        }
    }
}

void BSTree::preOrder()
{
    preOrder(root);
}

void BSTree::postOrder()
{
    postOrder(root);
}

void BSTree::inOrder()
{
    inOrder(root);
}

bool BSTree::search(const string &key)
{

    // return search(this->root, key) ? true : false;
    // cout << this->root->getData() << endl;
    return (search(this->root, key)) ? true : false;
}


// string BSTree::largest() const
// {
//     if (root == nullptr){
//         return "";
//     }
//     else {
//         Node *current = root;
//         while (current->getRight() != nullptr) {
//             current = current->getRight();
//         }
//         return current->getData();
//     }
// }

// string BSTree::smallest() const{
//     if (root == nullptr){
//         return "";
//     }
//     else {
//         Node *current = root;
//         while (current->getLeft() != nullptr){
//             current = current->getLeft();
//         }
//         // cout << "Inside else" << endl;
//         //cout << current->getData() << endl;
//         return current->getData();
//     }
// }

int BSTree::height(const string &key){
    Node *current = search(root, key);
    if (current == nullptr){
        return -1;
    }
    else {
        return heightOfTree(current);
    }
}

void BSTree::remove(const string &key){
    this->root = remove(root, key);
    return;
}

// helper functions
int BSTree::heightOfTree(Node *node){
    if (node == nullptr)
        return -1;
    return 1 + max(heightOfTree(node->getLeft()), heightOfTree(node->getRight()));
}

Node* BSTree::search(Node *node, const string &key)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (node->getData() < key)
    {
        return search(node->getRight(), key);
    }
    else if (node->getData() > key)
    {
        return search(node->getLeft(), key);
    }
    else 
    {
        return node;
    }
}


void BSTree::preOrder(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->getData() << "(" << node->getCount() << "), ";
    preOrder(node->getLeft());
    preOrder(node->getRight());
}

void BSTree::postOrder(Node *node)
{
    if (node == nullptr)
        return;
    postOrder(node->getLeft());
    postOrder(node->getRight());
    cout << node->getData() << "(" << node->getCount() << "), ";
}
void BSTree::inOrder(Node *node)
{
    if (node == nullptr)
        return;
    inOrder(node->getLeft());
    cout << node->getData() << "(" << node->getCount() << "), ";
    inOrder(node->getRight());

}

void BSTree::deleteNode(Node *root){
    if (root != nullptr){
        Node *left = root->getLeft();
        Node *right = root->getRight();
        delete root;
        deleteNode(left);
        deleteNode(right);
    }
}

Node* BSTree::remove(Node *node, const string &key){
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->getData() < key){
        node->setRight(remove(node->getRight(), key));
        return node;
    }
    else if (node->getData() > key){
        node->setLeft(remove(node->getLeft(), key));
        return node;
    }
    else {
        if (node->getCount() > 1){
            // cout << "temp " << endl;
            node->setCount(node->getCount() - 1);
            return node;
        }
        else {
            if (node->getRight() == nullptr && node->getLeft() == nullptr){
                if (node == root){
                    delete node;
                    root = nullptr;
                    return root;
                }
                delete node;
                return nullptr;
            }
            if (node->getLeft() == nullptr){
                Node* newNode = node->getRight();
                delete node;
                return newNode;
            }
            if (node->getRight() == nullptr){
                Node *newNode = node->getLeft();
                delete node;
                return newNode;
            }
            
            string successor = maxVal(node->getLeft());
            node->setData(successor);
            node->setLeft(remove(node->getLeft(), successor));
            return node;
        }
    }
}

string BSTree::minVal(Node* node){
    if (node->getLeft() == nullptr){
        return node->getData();
    }
    return minVal(node->getLeft());

}

string BSTree::maxVal(Node* node){
    if (node->getRight() == nullptr){
        return node->getData();
    }
    return maxVal(node->getRight());
}
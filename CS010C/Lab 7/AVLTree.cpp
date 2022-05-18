#include "AVLTree.h"
#include <fstream>
#include <iostream>

using namespace std;


//public member functions
void AVLTree::insert(const string &val){
    if (empty()){
        root = new Node(val);
    }
}
void AVLTree::printBalanceFactors(){}
int AVLTree::BalanceFactor(Node *node){}
void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->getLeft()){
            visualizeTree(outFS,n->getLeft());
            outFS<<n->getData() <<" -> " <<n->getLeft()->getData()<<";"<<endl;    
        }

        if(n->getRight()){
            visualizeTree(outFS,n->getRight());
            outFS<<n->getData() <<" -> " <<n->getRight()->getData()<<";"<<endl;    
        }
    }
}


//private helper functions

bool AVLTree::empty(){
    return (root == nullptr);
}
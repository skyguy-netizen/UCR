#include "arithmeticExpression.h"
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

// helper functions
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int addToArray(TreeNode *node, TreeNode *arr[], int i);

// public functions
arithmeticExpression::arithmeticExpression(const string &expression) : infixExpression(expression)
{
}

void enumarateTree(TreeNode *root);

void arithmeticExpression::buildTree()
{
    string postfix = infix_to_postfix();
    // infixExpression = infix_to_postfix();
    // cout << infixExpression << endl;
    stack<TreeNode *> s;
    char key = 'a';
    for (unsigned i = 0; i < postfix.size(); i++)
    {
        if (isOperator(postfix[i]))
        {
            TreeNode *right = s.top();
            s.pop();
            TreeNode *left = s.top();
            s.pop();
            TreeNode *parent = new TreeNode(postfix[i], key++, left, right);
            s.push(parent);
        }
        else
        {
            s.push(new TreeNode(postfix[i], key++));
        }
    }
    root = s.top();
    // TreeNode *arr[13];
    // addToArray(root, arr, 0);
    // cout << "Array representation of tree: " << endl;
    // for (int i = 0; i < 13; i++)
    // {
    //     cout << arr[i]->data << " ";
    // }
    // cout << endl;
    enumarateTree(root);
    // cout << "Test" << endl;
    // keyTheTree(root);
    // cout << "Test" << endl;
}

void arithmeticExpression::visualizeTree(const string &outputFilename)
{
    ofstream outFS(outputFilename.c_str());
    if (!outFS.is_open())
    {
        cout << "Error opening " << outputFilename << endl;
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

void arithmeticExpression::infix()
{
    infix(root);
}

void arithmeticExpression::postfix()
{
    postfix(root);
}

void arithmeticExpression::prefix()
{
    prefix(root);
}

// private helper functions
// stack<char> mainStack;
void arithmeticExpression::infix(TreeNode *root)
{
    if (root == NULL)
        return;
    // if (!isOperator(root->data))
    // {
    //     cout << "(";
    //     mainStack.push('(');
    // }
    if (root->left != NULL)
    {
        cout << "(";
    }
    infix(root->left);
    cout << root->data;
    infix(root->right);
    // while (!mainStack.empty())
    // {
    //     cout << ")";
    //     mainStack.pop();
    // }
    if (root->left != NULL)
    {
        cout << ")";
    }
}

void arithmeticExpression::postfix(TreeNode *root)
{
    if (root == NULL)
        return;
    postfix(root->left);
    postfix(root->right);
    cout << root->data;
}

void arithmeticExpression::prefix(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    prefix(root->left);
    prefix(root->right);
}

// given
int arithmeticExpression::priority(char op)
{
    int priority = 0;
    if (op == '(')
    {
        priority = 3;
    }
    else if (op == '*' || op == '/')
    {
        priority = 2;
    }
    else if (op == '+' || op == '-')
    {
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix()
{
    stack<char> s;
    ostringstream oss;
    char c;
    for (unsigned i = 0; i < infixExpression.size(); ++i)
    {
        c = infixExpression.at(i);
        if (c == ' ')
        {
            continue;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
        { // c is an operator
            if (c == '(')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                while (s.top() != '(')
                {
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.empty() && priority(c) <= priority(s.top()))
                {
                    if (s.top() == '(')
                    {
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else
        { // c is an operand
            oss << c;
        }
    }
    while (!s.empty())
    {
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

// int addToArray(TreeNode *node, TreeNode *arr[], int i)
// {
//     if (node == NULL)
//         return i;
//     if (node->left != NULL)
//         i = addToArray(node->left, arr, i);
//     if (node->right != NULL)
//         i = addToArray(node->right, arr, i);
//     arr[i] = node;
//     i++;

//     return i;
// }
// string arithmeticExpression::infix_to_prefix()
// {
//     stack<char> s;
//     ostringstream oss;
//     char c;
//     for (unsigned i = 0; i < infixExpression.size(); i++)
//     {
//         if
//     }
// }
// void arithmeticExpression::visualizeTree(const string &outputFilename)
// {
//     ofstream outFS(outputFilename.c_str());
//     if (!outFS.is_open())
//     {
//         cout << "Error opening " << outputFilename << endl;
//         return;
//     }
//     outFS << "digraph G {" << endl;
//     visualizeTree(outFS, root);
//     outFS << "}";
//     outFS.close();
//     string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
//     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//     system(command.c_str());
// }


void arithmeticExpression::visualizeTree(ofstream &os, TreeNode *root)
{
    if (root->left == nullptr || root->right == nullptr)
    {
        return;
    }
    // root->key = globalCounter++;
    // root->left->key = globalCounter++;
    // root->right->key = globalCounter;
    // globalCounter--;
    os << "\"" << root->key << root->data << "\"" << "->" << "\"" << root->left->key << root->left->data << "\"" << ";" << endl;
    os << "\"" << root->key << root->data << "\"" << "->" << "\"" << root->right->key << root->right->data << "\";" << endl;
    visualizeTree(os, root->left);
    // globalCounter++;
    visualizeTree(os, root->right);
}

int heightOfTree(TreeNode *root){
    if (root == nullptr){
        return -1;
    }
    return 1 + max(heightOfTree(root->left),heightOfTree(root->right));
}

char c = '['-6;


void enumarateCurrentLevel(TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1){
        root->key = c;
        c++;
    }

    else if (level > 1) {
        enumarateCurrentLevel(root->left, level - 1);
        enumarateCurrentLevel(root->right, level - 1);
    }
}

void enumarateLevelOrder(TreeNode* root)
{
    int h = heightOfTree(root);
    // char c = 'a' - 2*(h+2);
    cout << "C: " << c << endl;
    int i;
    for (i = 1; i <= h+1; i++)
        enumarateCurrentLevel(root, i);
}

void enumarateTree(TreeNode *root)
{
    enumarateLevelOrder(root); 
}

 


// #include "arithmeticExpression.h"
// #include <fstream>
// #include <sstream>
// #include <stack>
// using namespace std;

// // helper functions
// bool isOperator(char c)
// {
//     return (c == '+' || c == '-' || c == '/' || c == '*');
// }
// // void enumarateTree(TreeNode *root);

// // public functions
// arithmeticExpression::arithmeticExpression(const string &expression) : infixExpression(expression)
// {
// }

// void arithmeticExpression::buildTree()
// {
//     string postfix = infix_to_postfix();
//     // infixExpression = infix_to_postfix();
//     // cout << infixExpression << endl;
//     stack<TreeNode *> s;
//     // cout << "Test" << endl;
//     // cout << nodesOfTree(root);
//     //  cout << key << endl;
//     char key = 'a';
//     // cout << "Test" << endl;
//     for (unsigned i = 0; i < postfix.size(); i++)
//     {
//         if (isOperator(postfix[i]))
//         {
//             TreeNode *right = s.top();
//             s.pop();
//             TreeNode *left = s.top();
//             s.pop();
//             TreeNode *parent = new TreeNode(postfix[i], key++, left, right);
//             s.push(parent);
//         }
//         else
//         {
//             s.push(new TreeNode(postfix[i], key++));
//         }
//     }
//     root = s.top();
//     // enumarateTree(root);
//     //  cout << "Test" << endl;
//     //  keyTheTree(root);
//     //  cout << "Test" << endl;
// }

// void arithmeticExpression::visualizeTree(const string &outputFilename)
// {
//     ofstream outFS(outputFilename.c_str());
//     if (!outFS.is_open())
//     {
//         cout << "Error opening " << outputFilename << endl;
//         return;
//     }
//     outFS << "digraph G {" << endl;
//     visualizeTree(outFS, root);
//     outFS << "}";
//     outFS.close();
//     string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
//     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//     system(command.c_str());
// }

// void arithmeticExpression::infix()
// {
//     infix(root);
// }

// void arithmeticExpression::postfix()
// {
//     postfix(root);
// }

// void arithmeticExpression::prefix()
// {
//     prefix(root);
// }

// // private helper functions
// // stack<char> mainStack;
// void arithmeticExpression::infix(TreeNode *root)
// {
//     if (root == NULL)
//         return;
//     // if (!isOperator(root->data))
//     // {
//     //     cout << "(";
//     //     mainStack.push('(');
//     // }
//     if (root->left != NULL)
//     {
//         cout << "(";
//     }
//     infix(root->left);
//     cout << root->data;
//     infix(root->right);
//     // while (!mainStack.empty())
//     // {
//     //     cout << ")";
//     //     mainStack.pop();
//     // }
//     if (root->left != NULL)
//     {
//         cout << ")";
//     }
//     // cout << "Height of tree: " << nodesOfTree(root) << endl;
// }

// void arithmeticExpression::postfix(TreeNode *root)
// {
//     if (root == NULL)
//         return;
//     postfix(root->left);
//     postfix(root->right);
//     cout << root->data;
// }

// void arithmeticExpression::prefix(TreeNode *root)
// {
//     if (root == NULL)
//         return;
//     cout << root->data;
//     prefix(root->left);
//     prefix(root->right);
// }

// // given
// int arithmeticExpression::priority(char op)
// {
//     int priority = 0;
//     if (op == '(')
//     {
//         priority = 3;
//     }
//     else if (op == '*' || op == '/')
//     {
//         priority = 2;
//     }
//     else if (op == '+' || op == '-')
//     {
//         priority = 1;
//     }
//     return priority;
// }

// string arithmeticExpression::infix_to_postfix()
// {
//     stack<char> s;
//     ostringstream oss;
//     char c;
//     for (unsigned i = 0; i < infixExpression.size(); ++i)
//     {
//         c = infixExpression.at(i);
//         if (c == ' ')
//         {
//             continue;
//         }
//         if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
//         { // c is an operator
//             if (c == '(')
//             {
//                 s.push(c);
//             }
//             else if (c == ')')
//             {
//                 while (s.top() != '(')
//                 {
//                     oss << s.top();
//                     s.pop();
//                 }
//                 s.pop();
//             }
//             else
//             {
//                 while (!s.empty() && priority(c) <= priority(s.top()))
//                 {
//                     if (s.top() == '(')
//                     {
//                         break;
//                     }
//                     oss << s.top();
//                     s.pop();
//                 }
//                 s.push(c);
//             }
//         }
//         else
//         { // c is an operand
//             oss << c;
//         }
//     }
//     while (!s.empty())
//     {
//         oss << s.top();
//         s.pop();
//     }
//     return oss.str();
// }

// // void arithmeticExpression::visualizeTree(const string &outputFilename)
// // {
// //     ofstream outFS(outputFilename.c_str());
// //     if (!outFS.is_open())
// //     {
// //         cout << "Error opening " << outputFilename << endl;
// //         return;
// //     }
// //     outFS << "digraph G {" << endl;
// //     visualizeTree(outFS, root);
// //     outFS << "}";
// //     outFS.close();
// //     string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
// //     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
// //     system(command.c_str());
// // }

// // char globalChar = 'a';
// void arithmeticExpression::visualizeTree(ofstream &os, TreeNode *root)
// {
//     if (root->left == nullptr || root->right == nullptr)
//     {
//         return;
//     }
//     os << "\"" << root->key << root->data << "\""
//        << "->";
//     os << "\"" << root->key << root->left->data << "\""
//        << ";" << endl;
//     os << "\"" << root->key << root->data << "\""
//        << "->";
//     os << "\"" << root->key << root->right->data << "\";"
//        << endl;
//     visualizeTree(os, root->left);
//     visualizeTree(os, root->right);
// }

// // int arithmeticExpression::nodesOfTree(TreeNode *root)
// // {
// //     if (root == nullptr)
// //         return 0;
// //     cout << "SFSFSF" << endl;
// //     return 1 + nodesOfTree(root->left) + nodesOfTree(root->right);
// // }

// // char globalChar = 'a';
// // void enumarateTree(TreeNode *root)
// // {
// //     if (root == nullptr)
// //     {
// //         return;
// //     }
// //     else
// //     {
// //         root->key = globalChar++;
// //         root->left->key = globalChar++;
// //         root->right->key = globalChar++;
// //         enumarateTree(root->left);
// //         enumarateTree(root->right);
// //     }
// // }
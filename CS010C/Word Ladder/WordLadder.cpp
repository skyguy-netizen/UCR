#include "WordLadder.h"
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

WordLadder::WordLadder(const std::string &fileName){
    std::ifstream fin(fileName);
    std::string input;
    if (!fin.is_open()){
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        exit(0);
    }
    while (fin >> input){
        if (input.size() != 5){
            std::cerr << "Error: Words in dictionary must have exactly 5 characters." << std::endl;
            exit(0);
        }
        dict.push_front(input);
    }
    fin.close();
}

void WordLadder::outputLadder(const std::string &start, const std::string &end, const std::string &outputFile){
    if (!isValidInput(start, end)){
        std::cerr << "Error: Invalid input(s)" << std::endl;
        exit(0);
    }
        
    std::stack<std::string> st;
    st.push(start);
    std::queue<std::stack<std::string> > q;
    q.push(st);
    std::stack<std::string> finalStack;
    bool done = false;
    if (start == end){
        finalStack.push(start);
    }
    else {
        while (!q.empty() && !done){
            std::string temp = q.front().top();
            std::stack<std::string> tempSt = q.front();
            for (auto i = dict.begin(); i != dict.end();)
            {
                std::string key = *i;
                if (key == temp)
                {
                    i++;
                }
                else if (differsByOne(key, temp))
                    {
                        std::stack<std::string> newStack = tempSt;
                        newStack.push(key);
                        if (key == end)
                        {
                            // std::cout << "Inside break while loop" << std::endl;
                            finalStack = newStack;
                            done = true;
                            i++;
                            // std::cout << "after break while loop" << std::endl;
                        }
                        else
                        {
                            // std::cout << "Test" << std::endl;
                            q.push(newStack);
                            i = dict.erase(i);
                            // i++;
                            // std::cout << "Test 2" << std::endl;
                        }
                    }
                else {
                    i++;
                }
                // else {
                //     std::cout << "Test inside else branch" << std::endl;
                //     q.push(newStack);
                //     std::cout << "Test pushed new stack to queue of stacks" << std::endl;
                // }
            }
            q.pop();
        }
    }
    // std::cout << "Outside word ladder creation loop" << std::endl;
    std::ofstream fout(outputFile);
    if (q.empty() && !done){
        fout << "No world ladder found" << std::endl;
        return;
    }
    if (!fout.is_open()) {
        std::cerr << "Error: could not open output file " << outputFile << std::endl;
        exit(0);
    }
    std::stack<std::string> finalOrder;
    while (!finalStack.empty())
    {
        finalOrder.push(finalStack.top());
        finalStack.pop();
    }
    while (!finalOrder.empty()){
        fout << finalOrder.top() << std::endl;
        finalOrder.pop();
    }
    fout.close();
}

bool WordLadder::differsByOne(const std::string &word, const std::string &target){
    int count = 0;
    if (word.size() != 5 || target.size() != 5) return false;

    for (int i = word.size() - 1; i >= 0;i--){
        if (word[i] != target[i])
            count++;
    }
    return (count == 1) ? true : false;
}
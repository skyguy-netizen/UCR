#ifndef WORDLADDER_H
#define WORDLADDER_H
#include <list>
#include <string>
#include <stack>

class WordLadder {
    private:
        std::list<std::string> dict;
    public: 
    /* Passes in the name of a file that contains a dictionary of 5-letter words.
       Fills the list (dict) with the words within this file. 
       If the file does not open for any reason or if any word within the file
       does not have exactly 5 characters, this function should output an
       error message and return.
    */
    WordLadder(const std::string &);

    /* Passes in two 5-letter words and the name of an output file.
       Outputs to this file a word ladder that starts from the first word passed in
       and ends with the second word passed in.
       If either word passed in does not exist in the dictionary (dict),
       this function should output an error message and return.
       Otherwise, this function outputs to the file the word ladder it finds or outputs
       to the file, the message, "No Word Ladder Found."
    */
    void outputLadder(const std::string &start, const std::string &end, const std::string &outputFile);

    private:
        bool differsByOne(const std::string &word, const std::string &target);
        // int hash(char a){
        //     return a % 26;
        // }
        bool isValidInput(const std::string &word){
            for (auto i = dict.begin(); i != dict.end(); i++) {
                if (*i == word) {
                    return true;
                }
            }
            return false;
        }
};

#endif
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a Card's value as: Rank of Suit
// i.e., Ace of Spades
ostream &operator<<(ostream &, const vector<Card> &);

int main()
{
    srand(2222);
    string ans;
    int cardsPerHand;
    int numSims;
    Deck sample;
    // Card toCompare;
    int count = 0;
    string fileName;

    ofstream fout;
    //     Card Card1('D', 13);
    //     cout << Card1 << endl;
    //     cout << "test" << endl;
    //     Card Card2;

    //     Deck Deck1;
    // sample.Print();
    //     cout << "Deal Card: ";
    //     //cout << Deck1.dealCard() << endl;
    //     Card temp = Deck1.dealCard();
    //     cout << temp << endl;
    //     if (temp.suit() == 's' && temp.rank() == 13){
    //         cout << "Test Passed" << endl;
    //     } else {
    //         cout << "Deal card test failed" << endl;
    //     }
    //     cout << endl;
    //     cout << "Shuffled deck: " << endl;
    //     Deck1.shuffleDeck();
    //     Deck1.Print();

    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> ans;
    cout << endl;

    if (ans == "Yes")
    {
        cout << "Enter name of output file: ";
        cin >> fileName;
        cout << endl;
        fout.open(fileName);
        if (!fout.is_open())
        {
            cout << "Error opening file " << fileName << endl;
            exit(1);
        }
    }

    cout << "Enter number of cards per hand: ";
    cin >> cardsPerHand;
    cout << endl;
    cout << "Enter number of deals (simulations): ";
    cin >> numSims;
    for (int i = 0; i < numSims; i++)
    {
        sample.shuffleDeck();
        vector<Card> hand;
        for (int j = 0; j < cardsPerHand; j++)
        {
            hand.push_back(sample.dealCard());
        }

        if (hasPair(hand))
        {
            count++;
        }

        if (ans == "Yes")
        {
            if (hasPair(hand))
            {
                fout << "Found Pair!! " << hand;
            }
            else
            {
                fout << "             " << hand;
            }
        }

        fout << endl;
    }

    // for (int i = 0; i < hand.size(); i++){
    //     cout << hand.at(i) << ", ";
    // }
    // cout << endl << "Hand size: " << hand.size() << endl << endl;
    cout << endl;

    cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: ";
    // cout << count << endl;
    cout << (static_cast<double>(count) / numSims) * 100 << "%" << endl;

    fout.close();

    return 0;
}

bool hasPair(const vector<Card> &hand)
{
    int temp;
    for (unsigned i = 0; i < hand.size(); i++)
    {
        temp = hand.at(i).rank();
        for (unsigned j = i + 1; j < hand.size(); j++)
        {
            if (temp == hand.at(j).rank())
            {
                return true;
            }
        }
    }

    return false;
}

ostream &operator<<(ostream &out, const vector<Card> &hand)
{
    unsigned i;
    if (hand.size() > 0)
    {
        for (i = 0; i + 1 < hand.size(); i++)
        {
            out << hand.at(i) << ",";
        }
        out << hand.at(i);
    }

    return out;
}
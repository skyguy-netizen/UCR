#include <algorithm>
#include "Deck.h"

using namespace std;

// THE FOLLOWING shuffleDeck() IMPLEMENTATION IS GIVEN TO YOU. 
// DO NOT CHANGE!!

/* Places all cards back into theDeck and shuffles them into random order.
   Uses random_shuffle function from algorithm library.
*/
void Deck::shuffleDeck() {
	for (unsigned i = 0; i < dealtCards.size(); ++i) {
		theDeck.push_back(dealtCards.at(i));
	}
	dealtCards.clear();
	random_shuffle(theDeck.begin(), theDeck.end());
}

Deck::Deck(){
    const char suits[4] = {'s','h','d','c'};
    char temp;
    Card Temp;
    
    for (unsigned j = 0; j < 4; j++){
        temp = suits[j];
        for (unsigned i = 0; i < 13; i++){
            Temp = Card(temp, 13-i);
            theDeck.push_back(Temp);
        
    }
}
}

// Deck::Deck(){
//     const char suits[4] = {'c','d','h','s'};
//     char temp;
//     Card Temp;
    
//     for (unsigned j = 0; j < 4; j++){
//         temp = suits[j];
//         for (unsigned i = 0; i < 13; i++){
//             Temp = Card(temp, i+1);
//             theDeck.push_back(Temp);
        
//     }
// }
// }

// void Deck::Print() const{
//     for (unsigned i = 0; i < theDeck.size(); i++){
//         cout << theDeck.at(i) << endl;
//         //if ((i+1) % 13 == 0){//to print a new line after printing every suit
//           //  cout << endl;
//         //}
//     }
// }

Card Deck::dealCard(){
    Card temp = theDeck.back();
    dealtCards.push_back(temp);
    theDeck.pop_back();
    return temp;
}

unsigned Deck::deckSize() const {
    return theDeck.size();
}
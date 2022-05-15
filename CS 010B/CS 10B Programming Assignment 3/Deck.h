#ifndef __DECK_H__
#define __DECK_H__

#include <vector>
using namespace std;

#include "Card.h"

class Deck {
 private:
    vector<Card> theDeck;
    vector<Card> dealtCards;
 public:
    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
       For best efficiency, top of Deck should be stored at 
       back end of vector.
    */
    Deck();

    /* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
       As mentioned in comments for constructor, for best efficiency,
       top card should be at back end of vector.
    */
    Card dealCard();


    /* Places all cards back into theDeck and shuffles them into random order.
       Use random_shuffle function from algorithm library.
       This function goes forward through dealtCards pushing each Card 
       onto back end of theDeck, then clears dealtCards.
    */
    void shuffleDeck();


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    unsigned deckSize() const;
    //void Print() const;
};

#endif

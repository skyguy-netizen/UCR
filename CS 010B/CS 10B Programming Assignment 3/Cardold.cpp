#include "Card.h"
#include <stdio.h>

using namespace std;

Card::Card(){
    _suit = 'c';
    _rank = 2;
}

Card::Card(char userSuit, int userRank){
    _suit = userSuit;
    _rank = userRank;
    //_suit = static_cast<char>(to_lower(_suit));
    if (isupper(_suit)){
        _suit += 32;
    }
    if (_suit != 'c' && _suit != 'd' && _suit != 'h' && _suit != 's'){
        _suit = 'c';
    }
    
    if (_rank > 13 || _rank < 1){
        _rank = 2;
    }
}

char Card::suit() const{
    return _suit;
}

int Card::rank() const{
    return _rank;
}

ostream & operator<<(ostream &out, const Card &userCard){
    
    //outputting card rank accordingly to ostream
    if (userCard._rank == 1){
        out << "Ace";
    } else if (userCard._rank == 11){
        out << "Jack";
    } else if (userCard._rank == 12){
        out << "Queen";
    } else if (userCard._rank == 13){
        out << "King";
    } else {
        out << userCard._rank;
    }
    
    //outputting suit to ostream
    if (userCard._suit == 'c'){
        out << " of Clubs";
    } else if (userCard._suit == 'h'){
        out << " of Hearts";
    } else if (userCard._suit == 'd'){
        out << " of Diamonds";
    } else {
        out << " of Spades";
    }
    
    return out;
}

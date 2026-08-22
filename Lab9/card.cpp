#include "card.h"
#include <iostream> // Required for cout
#include <string>   // Required for string

// Using directive
using namespace std;

/*
 * Default Constructor
 * [cite: 145]
 */
Card::Card() {
    this->point = 0; 
    this->suit = cSuits::Invalid; 
}

/*
 * Alternate Constructor
 * [cite: 146]
 */
Card::Card(cSuits s, cPoints p) {
    this->point = p;
    this->suit = s;
}

Card::cPoints Card::getPoint() const {
    return this->point;
}

Card::cSuits Card::getSuit() const {
    return this->suit;
}



bool operator<(Card C1, Card C2) {
    // We must use the public 'getPoint()' accessor functions
    // because this is not a member of the Card class.
    return C1.getPoint() < C2.getPoint();
}

ostream& operator<<(ostream& out, const Card& C) {
    
    int point = C.getPoint();

    const char* printSuit;

    if (C.suit == Card::cSuits::Spade) {
	printSuit = SPADE;
    }
    if (C.suit == Card::cSuits::Club) {
	printSuit = CLUB;
    }
    if (C.suit == Card::cSuits::Heart) {
	printSuit = HEART;
    }
    if (C.suit == Card::cSuits::Diamond) {
	printSuit = DIAMOND;
    }




    // Print the face value based on the point
    switch (point) {
        case 10:
            out << printSuit << "10" << printSuit;
            break;
        case 11:
            out << printSuit << "J" << printSuit;
            break;
        case 12:
            out << printSuit << "Q" << printSuit;
            break;
        case 13:
            out << printSuit << "K" << printSuit;
            break;
        case 14:
            out << printSuit << "A" << printSuit;
            break;
        default:
            out << printSuit << point << printSuit;
            break;
    }
    return out;



}
          
 
bool Card::HigherBefore(const Card& C1, const Card&C2) {
	return C1.getPoint() > C2.getPoint();
}


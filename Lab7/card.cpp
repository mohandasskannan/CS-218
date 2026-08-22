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

/*
 * getPoint() (const)
 * [cite: 147]
 */
Card::cPoints Card::getPoint() const {
    return this->point;
}

/*
 * getSuit() (const)
 * [cite: 147]
 */
Card::cSuits Card::getSuit() const {
    return this->suit;
}

/*
 * pointLessThan(Card other) (const)
 * [cite: 147]
 * Returns 1 if this card's point is less than other [cite: 30]
 * Returns -1 if this card's point is greater than other [cite: 31]
 * Returns 0 if points are the same [cite: 32]
 */
int Card::pointLessThan(Card other) const {
    if (this->point < other.getPoint()) {
        return -1; // this->point is less
    } else if (this->point > other.getPoint()) {
        return 1; // this->point is greater
    } else {
        return 0; // points are the same
    }
}

/*
 * print() (const)
 * [cite: 148]
 * Prints the card to standard output in the format: suit-point-suit [cite: 37]
 * Adds padding for single-digit points [cite: 38]
 */
void Card::print() const { 
    string suit_char;

    // 1. Get the Unicode suit character [cite: 56]
    switch (this->suit) {
        case cSuits::Club:
            suit_char = "\e[0;30;47m\xe2\x99\xa3\e[0;37;40m"; // ♣
            break;
        case cSuits::Diamond:
            suit_char = "\e[0;31;47m\xe2\x99\xa6\e[0;37;40m"; // ♦
            break;
        case cSuits::Heart:
            suit_char = "\e[0;31;47m\xe2\x99\xa5\e[0;37;40m"; // ♥
            break;
        case cSuits::Spade:
            suit_char = "\e[0;30;47m\xe2\x99\xa0\e[0;37;40m"; // ♠
            break;
        case cSuits::Invalid:
        default:
            suit_char = "?";
            break;
    }

    // 2. Print the first suit character [cite: 37]
    cout << suit_char;

    // 3. Add padding if point value is a single digit (2-9) [cite: 38]
    if (this->point < 10) {
        cout << " ";
    }

    // 4. Print the point value (handling 10, J, Q, K, A) [cite: 33]
    switch (this->point) {
        case 10:
            cout << "10";
            break;
        case 11: // Jack
            cout << "J";
            break;
        case 12: // Queen
            cout << "Q";
            break;
        case 13: // King
            cout << "K";
            break;
        case 14: // Ace
            cout << "A";
            break;
        default: // For points 2-9
            cout << this->point;
            break;
    }

    // 5. Print the second suit character [cite: 37]
    cout << suit_char;
}

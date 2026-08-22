/* File: rank.cpp
 * Course: CS218-00x
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 *
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
    kind = hRanks::NoRank;
    point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    kind = r;
    point = p;
}

// access the hand ranking kind
Rank::hRanks Rank::getKind() const
{
    return kind;
}

// access the card point value of the corresponding ranking kind
Rank::rPoints Rank::getPoint() const
{
    return point;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse(10)
//   Flush( A)
//   ...
void Rank::print() const
{


    const int POINTMIN = 2;
    const int POINTMAX = 14;
    
    if (point < POINTMIN ||point > POINTMAX) {
	cout << "Invalid card value!" << endl;
	return;
    }

    
    // An array of strings to hold the names of the ranks.
    // This assumes 'kind' is an int/enum from 0 (StraightFlush)
    // to 7 (HighCard), matching the order in the sample output.

    // 1. Print the string name of the rank (e.g., "StraightFlush")
    //    using the 'kind' member variable as the index.
    cout << RANK_NAMES[static_cast<int>(this->kind)];

    // 2. Print the point value, handling face cards.
    cout << " (";

    // Use a switch statement to convert point values
    // 11-14 into "J", "Q", "K", and "A".
    switch (this->point) {
        case 11:
            cout << "J";
            break;
        case 12:
            cout << "Q";
            break;
        case 13:
            cout << "K";
            break;
        case 14:
            cout << "A";
            break;
        default:
            // For any other point (like 2-10)
            cout << this->point;
            break;
    }

    cout << ")";

    // The sample output shows each rank on its own line.
    cout << endl;
}

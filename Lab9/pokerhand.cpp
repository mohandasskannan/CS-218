#include "pokerhand.h"
#include <iostream>
#include <algorithm>
#include <string> // Added for string helpers
#include <sstream> // Added for string helpers

using namespace std;

// --- Helper Functions ---
// These are needed to print ranks and cards, since
// they don't have .print() or operator<<

// Helper function to convert point (2-14) to string
string pointToString(int point) {
    if (point >= 2 && point <= 10) {
        return to_string(point);
    }
    switch (point) {
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        case 14: return "A";
        // Special case for A-low straight rank
        case 5: return "5"; 
        default: return "?";
    }
}

// Helper function to convert rank kind to string
string kindToString(Rank::hRanks kind) {
    switch (kind) {
        case Rank::hRanks::HighCard: return "HighCard";
        case Rank::hRanks::Pair: return "Pair";
        case Rank::hRanks::ThreeOfAKind: return "ThreeOfAKind";
        case Rank::hRanks::Straight: return "Straight";
        case Rank::hRanks::Flush: return "Flush";
        case Rank::hRanks::FullHouse: return "FullHouse";
        case Rank::hRanks::FourOfAKind: return "FourOfAKind";
        case Rank::hRanks::StraightFlush: return "StraightFlush";
        case Rank::hRanks::NoRank: return "NoRank";
        default: return "Unknown";
    }
}
// --- End Helper Functions ---

bool compareCards(const Card& a, const Card& b) {
    return a.getPoint() > b.getPoint();
}

PokerHand::PokerHand() {
    hand_rank = Rank(Rank::hRanks::NoRank, 0);
}

void PokerHand::setPokerHand(Card in_hand[], int size) {
    if (size != HANDS) {
        cout << "Invalid number of cards!" << endl;
        hand_rank = Rank(Rank::hRanks::NoRank, 0);
        return;
    }

    for (int i = 0; i < HANDS; ++i) {
        cards[i] = in_hand[i];
    }

    sort();

    if (isStraightFlush()) { return; }
    if (isFourOfAKind())  { return; }
    if (isFullHouse())    { return; }
    if (isFlush())        { return; }
    if (isStraight())     { return; }
    if (isThreeOfAKind()) { return; }
    if (isPair())         { return; }
    if (isHighCard())     { return; }
}

int PokerHand::compareHand(const PokerHand &otherHand) const {
    
    Rank::hRanks myKind = hand_rank.getKind(); 
    Rank::hRanks otherKind = otherHand.hand_rank.getKind();

    if (myKind > otherKind) {
        return 1;
    } else if (myKind < otherKind) {
        return -1;
    } else {
        int myPoint = hand_rank.getPoint();
        int otherPoint = otherHand.hand_rank.getPoint();

        if (myPoint > otherPoint) {
            return 1;
        } else if (myPoint < otherPoint) {
            return -1;
        } else {
            
            return 0;
        }
    }
    
}

void PokerHand::print() const {
    cout << "Five cards in order:" << endl;
    for (int i = 0; i < HANDS; ++i) {
        
        cout << cards[i] << " ";
    }
    cout << endl;
    
    cout << "Its rank is: ";
    
    
    Rank::hRanks kind = hand_rank.getKind();
    int point = hand_rank.getPoint();
    
    
    cout << kindToString(kind) << "(" << pointToString(point) << ")" << endl;
}

Rank PokerHand::getRank() const {
    return hand_rank;
}

bool PokerHand::isStraightFlush() {
    if (isAllOneSuit() && isSequence()) {
        int highPoint = (cards[0].getPoint() == 14 && cards[1].getPoint() == 5) ? 5 : cards[0].getPoint();
        hand_rank = Rank(Rank::hRanks::StraightFlush, highPoint);
        return true;
    }
    return false;
}

bool PokerHand::isFourOfAKind() {
    if (cards[0].getPoint() == cards[1].getPoint() &&
        cards[1].getPoint() == cards[2].getPoint() &&
        cards[2].getPoint() == cards[3].getPoint()) {
        hand_rank = Rank(Rank::hRanks::FourOfAKind, cards[0].getPoint());
        return true;
    }
    if (cards[1].getPoint() == cards[2].getPoint() &&
        cards[2].getPoint() == cards[3].getPoint() &&
        cards[3].getPoint() == cards[4].getPoint()) {
        hand_rank = Rank(Rank::hRanks::FourOfAKind, cards[1].getPoint());
        return true;
    }
    return false;
}

bool PokerHand::isFullHouse() {
    if (cards[0].getPoint() == cards[1].getPoint() && cards[1].getPoint() == cards[2].getPoint() &&
        cards[3].getPoint() == cards[4].getPoint()) {
        hand_rank = Rank(Rank::hRanks::FullHouse, cards[0].getPoint());
        return true;
    }
    if (cards[0].getPoint() == cards[1].getPoint() &&
        cards[2].getPoint() == cards[3].getPoint() && cards[3].getPoint() == cards[4].getPoint()) {
        hand_rank = Rank(Rank::hRanks::FullHouse, cards[2].getPoint());
        return true;
    }
    return false;
}

bool PokerHand::isFlush() {
    if (isAllOneSuit()) {
        hand_rank = Rank(Rank::hRanks::Flush, cards[0].getPoint());
        return true;
    }
    return false;
}

bool PokerHand::isStraight() {
    if (isSequence()) {
        int highPoint = (cards[0].getPoint() == 14 && cards[1].getPoint() == 5) ? 5 : cards[0].getPoint();
        hand_rank = Rank(Rank::hRanks::Straight, highPoint);
        return true;
    }
    return false;
}

bool PokerHand::isThreeOfAKind() {
    if (cards[0].getPoint() == cards[1].getPoint() && cards[1].getPoint() == cards[2].getPoint()) {
        hand_rank = Rank(Rank::hRanks::ThreeOfAKind, cards[0].getPoint());
        return true;
    }
    if (cards[1].getPoint() == cards[2].getPoint() && cards[2].getPoint() == cards[3].getPoint()) {
        hand_rank = Rank(Rank::hRanks::ThreeOfAKind, cards[1].getPoint());
        return true;
    }
    if (cards[2].getPoint() == cards[3].getPoint() && cards[3].getPoint() == cards[4].getPoint()) {
        hand_rank = Rank(Rank::hRanks::ThreeOfAKind, cards[2].getPoint());
        return true;
    }
    return false;
}

bool PokerHand::isPair() {
    int highPairPoint = 0;
    int numPairs = 0;

    if (cards[0].getPoint() == cards[1].getPoint()) {
        numPairs++;
        highPairPoint = cards[0].getPoint(); 
    }
    if (cards[1].getPoint() == cards[2].getPoint()) {
        numPairs++;
        highPairPoint = cards[1].getPoint();
    }
    if (cards[2].getPoint() == cards[3].getPoint()) {
        numPairs++;
        highPairPoint = (highPairPoint > cards[2].getPoint()) ? highPairPoint : cards[2].getPoint();
    }
    if (cards[3].getPoint() == cards[4].getPoint()) {
        numPairs++;
        highPairPoint = (highPairPoint > cards[3].getPoint()) ? highPairPoint : cards[3].getPoint();
    }

    if (numPairs > 0) {
        hand_rank = Rank(Rank::hRanks::Pair, highPairPoint);
        return true;
    }
    return false;
}

bool PokerHand::isHighCard() {
    hand_rank = Rank(Rank::hRanks::HighCard, cards[0].getPoint());
    return true;
}

void PokerHand::sort() {
    std::sort(cards, cards + HANDS, compareCards);
}

bool PokerHand::isAllOneSuit() const {
    
    auto firstSuit = cards[0].getSuit();
    for (int i = 1; i < HANDS; ++i) {
        if (cards[i].getSuit() != firstSuit) {
            return false;
        }
    }
    return true;
}

bool PokerHand::isSequence() const {
    if (cards[0].getPoint() == 14 &&
        cards[1].getPoint() == 5  &&
        cards[2].getPoint() == 4  &&
        cards[3].getPoint() == 3  &&
        cards[4].getPoint() == 2) {
        return true;
    }

    for (int i = 0; i < HANDS - 1; ++i) {
        if (cards[i].getPoint() != cards[i+1].getPoint() + 1) {
            return false;
        }
    }
    return true;
}

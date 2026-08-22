#include "deck.h"
#include <algorithm> 
#include <random>    
#include <cstdlib>   // Required for rand() and srand()
#include <ctime>     // Required for time()
#include <utility>

// Use the standard namespace as requested
using namespace std;


void Deck::createDeck() {
    // Clear the vector in case it's not empty
    deck.clear();

    // Loop through all 4 suits (1=Clubs, 2=Diamonds, 3=Hearts, 4=Spades)
    for (int s = 1; s <= 4; s++) {
        
        // Cast the integer 's' to the enum type Card::cSuits
        Card::cSuits suit = static_cast<Card::cSuits>(s);

        // Loop through all 13 points (2-14)
        for (Card::cPoints p = 2; p <= 14; p++) {
            
            // Create a new Card object and add it to the deck vector
            deck.push_back(Card(suit, p));
        }
    }
}

void Deck::shuffleDeck() {

	static bool is_seeded = false;
	if (!is_seeded) {
		srand(time(NULL));
		is_seeded = true;
	}

	int n = deck.size();
    	for (int i = n - 1; i > 0; i--) {
        // Get a random index j such that 0 <= j <= i
        	int j = rand() % (i + 1); 
        
        // Swap the elements at i and j
        	swap(deck[i], deck[j]);
    	}
}


Card Deck::deal_a_card() {
    // 1. Get a copy of the last card in the vector
    Card c = deck.back();
    
    // 2. Remove the last card from the vector
    deck.pop_back();
    
    // 3. Return the copy
    return c;
}

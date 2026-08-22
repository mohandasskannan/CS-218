/*
 * Course: CS218-1
 * Project: Project 2 (Modified Variable Version)
 * Purpose: Determine the strongest 5-card poker hand out of 7 cards
 */

#include <iostream>
#include <vector>
#include "pokerhand.h"
#include "deck.h"

using namespace std;

// symbolic constants
const int CARDS_TOTAL = 7;
const int CARDS_IN_HAND = 5;
const int PRIV_CARDS = 2;

// function prototype
PokerHand selectBestFive(const vector<Card>& allCards);

int main()
{
    string input;

    do {
        Deck gameDeck;
        gameDeck.createDeck();
        gameDeck.shuffleDeck();

        Card playerCards[PRIV_CARDS];
        Card cpuCards[PRIV_CARDS];

        // dealing hole cards
        cpuCards[0] = gameDeck.deal_a_card();
        playerCards[0] = gameDeck.deal_a_card();
        cpuCards[1] = gameDeck.deal_a_card();
        playerCards[1] = gameDeck.deal_a_card();

        // dealing community cards
        Card tableCards[CARDS_IN_HAND];
        for (int t = 0; t < CARDS_IN_HAND; t++)
            tableCards[t] = gameDeck.deal_a_card();

        // display player cards
        cout << "Your cards:" << endl;
        cout << "    " << playerCards[0] << endl;
        cout << "       " << playerCards[1] << endl << endl;

        // display community cards
        cout << "Community cards:" << endl;
        cout << "\t********************" << endl;
        for (int c = 0; c < CARDS_IN_HAND; c++)
            cout << "\t*       " << tableCards[c] << "       *" << endl;
        cout << "\t********************" << endl;

        // display CPU cards
        cout << "Computer's cards:" << endl;
        cout << "    " << cpuCards[0] << endl;
        cout << "       " << cpuCards[1] << endl << endl;

        // evaluate player's best hand
        cout << "Player 1: You" << endl;
        vector<Card> sevenCards = {
            playerCards[0], playerCards[1],
            tableCards[0], tableCards[1], tableCards[2], tableCards[3], tableCards[4]
        };
        PokerHand pBest = selectBestFive(sevenCards);

        // evaluate computer’s best hand
        cout << "Player 2: Computer" << endl;
        sevenCards[0] = cpuCards[0];
        sevenCards[1] = cpuCards[1];
        PokerHand cBest = selectBestFive(sevenCards);

        // determine winner
        cout << endl;
        int result = pBest.compareHand(cBest);
        if (result > 0)
            cout << "You win!" << endl;
        else if (result < 0)
            cout << "The computer wins!" << endl;
        else
            cout << "It's a tie!" << endl;

        cout << endl << "Play again? (Press \"q\" or \"Q\" to quit): ";
        getline(cin, input);

    } while (input != "q" && input != "Q");

    cout << "Thank you for playing CS218 Poker Game, have a great DAY!" << endl;
    return 0;
}

// ---------------------------------------------------------

PokerHand selectBestFive(const vector<Card>& allCards)
{
    PokerHand bestHandSoFar;
    PokerHand testHand;

    if (allCards.size() != CARDS_TOTAL) {
        cout << "Error: must provide exactly SEVEN cards." << endl;
        return testHand;
    }

    // generate all 21 possible 5-card selections
    for (int first = 0; first < CARDS_TOTAL; first++) {
        for (int second = first + 1; second < CARDS_TOTAL; second++) {

            Card combo[CARDS_IN_HAND];
            int pos = 0;

            for (int m = 0; m < CARDS_TOTAL; m++) {
                if (m == first || m == second) continue;
                combo[pos++] = allCards[m];
            }

            testHand.setPokerHand(combo, CARDS_IN_HAND);

            if (bestHandSoFar.compareHand(testHand) < 0)
                bestHandSoFar = testHand;
        }
    }

    cout << "*** Strongest 5-card poker hand ***" << endl;
    bestHandSoFar.print();
    cout << endl << endl;

    return bestHandSoFar;
}

//
//  DeckFunc.h
//  BlackJack
//
//  Created by Brendan Souksamlane on 2015-09-04.
//  Copyright (c) 2015 All rights reserved.
//

#ifndef BlackJack_DeckFunc_h
#define BlackJack_DeckFunc_h
#include <string>
namespace DeckFunc {
    void randCard(int& card);
    void randSuit(int& suit);
    int randDeckSlot();
    struct Deck
    {
        int card; //0-12 representing value
        int suit; //0-3 representing suit
        bool OoD; //Out of Deck, tests whether card is in the deck or not
    };
    void deckShffl(Deck* toBeShffled[]);
    std::string printCard(Deck* card[], int location);
    int valueOfHand(Deck* hand[], int handsize);
    int dealerplay(Deck* dealerHand[], Deck* houseDeck[]);
    bool Aces (Deck* hand[]);
}
#endif

//
//  DeckFunc.cpp
//  BlackJack
//
//  Created by Brendan Souksamlane on 2015-09-04.
//  Copyright (c) 2015 All rights reserved.
//

#include "DeckFunc.h"
#include <cstdlib>
#include <ctime>
#include <string>

namespace DeckFunc {
    //THESE ASSUME srand() HAS BEEN CALLED
    void randCard(int& card)
    //Generates a random card and puts it in the input variable. Cards start at 0 and go to 12; 0 being ace and all others being following suite ie king = 12, 7 = 6 etc.
    {
        card = rand() % 13;
    }

    void randSuit(int& suit)
    //Generates a random suit and puts it in the input variable. Suits start at 0 and go to 3, in order of Hearts Spades Diamonds Clubs
    {
        suit = rand() % 4;
    }

    int randDeckSlot()
    //picks a random array location to deal to the hand
    {
        int location = rand() % 52;
        return (location);
    }

    int valueOfHand(Deck* hand[], int handsize)
    //Evaluates value of hand, Hand size is ACTUAL number of cards in hand
    {
        int value = 0;
        for (int x = 0; x < handsize; x++) {
            if (hand[x]->card >= 10) {
                //if Jack Queen King then value = 10 - 1
                value += 9;
            }
            else
            {
                value += hand[x]->card;
            }
        }
        //because of how arrays work, must add +1 for each card in hand
        value += handsize;
        return value;
    }

    int dealerplay(Deck* dealerHand[], Deck* houseDeck[])
    //Plays dealer hand until dealer hits/passes 17, returns the value of dealer's hand
    {
        int dealerValue;
        bool dealt1 = false;
        int loc;
        int x = 2;

        dealerValue = valueOfHand(dealerHand, 2);

        //if dealer is already over 17, simply return his hand value
        if (dealerValue >= 17) {
            return dealerValue;
        }
        else {
            //deal card, evaluate hand and loop if it's less than or equal to 17
            do {
                do {
                    loc = DeckFunc::randDeckSlot();
                    if (houseDeck[loc]->OoD == false) {
                        dealerHand[x] = houseDeck[loc];
                        houseDeck[loc]->OoD = true;
                        dealt1 = true;
                    }
                } while (dealt1 == false);
                dealt1 = false;
                dealerValue = valueOfHand(dealerHand, x + 1);
                x++;
            } while (dealerValue <= 17);
            return dealerValue;
        }
    }
    void deckShffl(Deck* toBeShffled[])
    //Puts all cards back into the deck, assumes OoD is false for all cards
    {
        //These integers count how many of each card type needs to be put into the deck
        int t = 4, tr = 4, f = 4, fi = 4, s = 4, se = 4, e = 4, n = 4, ten = 4, j = 4, k = 4, q = 4, a = 4;

        //For each card, find a random location and put all 4 suits of that card in, move on.
        for (int x = 0; x < a; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 0;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < t; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 1;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < tr; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 2;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < f; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 3;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < fi; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 4;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < s; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 5;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < se; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 6;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < e; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 7;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < n; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 8;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < ten; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 9;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < j; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 10;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < q; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 11;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x < k; x++) {
            int loc = randDeckSlot();
            if (toBeShffled[loc]->OoD == false) {
                toBeShffled[loc]->card = 12;
                toBeShffled[loc]->suit = x;
                toBeShffled[loc]->OoD = true;
            }
            else{
                x--;
            }
        }
        for (int x = 0; x <52; x++) {
            toBeShffled[x]->OoD = false;
        }
        //THIS WAS THE OLD BROKEN DECK SHUFFLE
        /*
         int card;
         int suit;
         bool check1 = false, check2 = false;

         int hearts = 13, spades = 13, diamonds = 13, clubs = 13;
         int *selectedCard = &a, *selectedSuit = &hearts;

         for (int x = 0; x < 52; x++)
         {
         randCard(card);
         randSuit(suit);
         //check if any cards of 'card' are left
         switch (card) {
         case 0:
         if (a != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &a;
         }
         else
         {
         check1 = false;
         }
         break;
         case 1:
         if (t != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &t;
         }
         else
         {
         check1 = false;
         }
         break;
         case 2:
         if (tr != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &tr;
         }
         else
         {
         check1 = false;
         }
         break;
         case 3:
         if (f != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &f;
         }
         else
         {
         check1 = false;
         }
         break;
         case 4:
         if (fi != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &fi;
         }
         else
         {
         check1 = false;
         }
         break;
         case 5:
         if (s != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &s;
         }
         else
         {
         check1 = false;
         }
         break;
         case 6:
         if (se != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &se;
         }
         else
         {
         check1 = false;
         }
         break;
         case 7:
         if (e != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &e;
         }
         else
         {
         check1 = false;
         }
         break;
         case 8:
         if (n != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &n;
         }
         else
         {
         check1 = false;
         }
         break;
         case 9:
         if (ten != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &ten;
         }
         else
         {
         check1 = false;
         }
         break;
         case 10:
         if (j != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &j;
         }
         else
         {
         check1 = false;
         }
         break;
         case 11:
         if (q != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &q;
         }
         else
         {
         check1 = false;
         }
         break;
         case 12:
         if (k != 0 && toBeShffled[x]->OoD == false) {
         check1 = true;
         selectedCard = &k;
         }
         else
         {
         check1 = false;
         }
         break;

         default:
         check1 = false;
         selectedCard = NULL;
         break;
         }
         if (check1 == true) {
         toBeShffled[x]->card = card;
         toBeShffled[x]->OoD = true;
         //decrement the counter of whatever card was selected
         *selectedCard = *selectedCard - 1;
         }
         //check if any suits of 'suit' are left
         switch (suit) {
         case 0:
         if (hearts != 0 && toBeShffled[x]->OoD == false) {
         check2 = true;
         selectedSuit = &hearts;
         }
         else
         {
         check2 = false;
         }
         break;
         case 1:
         if (spades != 0 && toBeShffled[x]->OoD == false) {
         check2 = true;
         selectedSuit = &spades;
         }
         else
         {
         check2 = false;
         }
         break;
         case 2:
         if (diamonds != 0 && toBeShffled[x]->OoD == false) {
         check2 = true;
         selectedSuit = &diamonds;
         }
         else
         {
         check2 = false;
         }
         break;
         case 3:
         if (clubs != 0 && toBeShffled[x]->OoD == false) {
         check2 = true;
         selectedSuit = &clubs;
         }
         else
         {
         check2 = false;
         }
         break;
         default:
         check2 = false;
         selectedCard = NULL;
         break;
         }
         //if both card and suit exist,
         if (check1 == true && check2 == true) {
         toBeShffled[x]->card = card;
         toBeShffled[x]->suit = suit;
         toBeShffled[x]->OoD = true;
         //decrement the counter of whatever card was selected
         *selectedCard = *selectedCard - 1;
         *selectedSuit = *selectedSuit - 1;
         }
         else
         {
         x--;
         }
         }*/
    }

    std::string printCard(Deck* card[], int location)
    //returns a string that prints out Card of Suit
    {
        std::string Name;
        std::string Suit;
        switch (card[location]->card) {
            case 0:
                Name = "Ace";
                break;
            case 1:
                Name = "2";
                break;
            case 2:
                Name = "3";
                break;
            case 3:
                Name = "4";
                break;
            case 4:
                Name = "5";
                break;
            case 5:
                Name = "6";
                break;
            case 6:
                Name = "7";
                break;
            case 7:
                Name = "8";
                break;
            case 8:
                Name = "9";
                break;
            case 9:
                Name = "10";
                break;
            case 10:
                Name = "Jack";
                break;
            case 11:
                Name = "Queen";
                break;
            case 12:
                Name = "King";
                break;
            default:
                Name = "INVALID CARD";
                break;
        }
        switch (card[location]->suit) {
            case 0:
                Suit = "Hearts";
                break;
            case 1:
                Suit = "Spades";
                break;
            case 2:
                Suit = "Diamonds";
                break;
            case 3:
                Suit = "Clubs";
                break;
            default:
                Suit = "INVALID SUIT";
                break;
        }
        return (Name + " of " + Suit);
    }

    bool Aces (Deck* hand[])
    //Checks hand for Aces, returns T/F if present/not present
    {
        int x = 0;
        while (hand[x] != NULL) {
            if (hand[x]->card == 0) {
                return true;
            }
            x++;
        }
        return false;
    }
}

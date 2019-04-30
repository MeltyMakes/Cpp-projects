//
//  main.cpp
//  BlackJack
//
//  A commandline based BlackJack game.
//
//  Created by Brendan Souksamlane on 2015-09-04.
//  Copyright (c) 2015 All rights reserved.
//

#include <iostream>
#include "DeckFunc.h"
using namespace std;

int main()
{

    int x;                                  //Counter variable
    int loc;                                //Used various times to find random location to draw cards
    bool quit = false;                      //True when the player no longer wants to play
    bool lose = false;                      //True when the player loses
    bool dealt1, dealt2;                    //Used to manage card dealing
    char advance;                           //Used when the player is asked to hit stand or dd

    int playernum = 0;                      //Player's hand value
    int dealernum = 0;                      //Dealer's hand value
    bool pHandA = false;                    //True if player has aces in hand
    bool dHandA = false;                    //True if dealer has aces in hand

    float money = 1000.00;                  //Player's money; resets to default if player busts
    float bet = 0;                          //Player's bet
    float winMult;                          //Win multiplier that changes based on dd or just h/s
    DeckFunc::Deck* houseDeck[52];          //Points to card deck, used with functions and the hands
    DeckFunc::Deck  cardList[52];           //The actual cards
    DeckFunc::Deck* yourHand[25];           //Player hand
    DeckFunc::Deck* dealerHand[25];         //Dealer hand

    //seeds random numbers
    srand((unsigned)time(0));

    //Setup--initialize houseDeck to be cardList
    for (x = 0; x <52; x++) {
        houseDeck[x] = &cardList[x];
    }

    //Enter game instance
    do {
        lose = false;
        winMult = 2;
        //Take player bet
        do {
            cout << "Welcome to Blackjack!"<< endl
            << "You have $" << money << endl
            << "Place a Bet:";
            cin >> bet;
            cout << endl;
            if (bet > money) {
                cout << "You don't have $" << bet << "!" << endl;
            }
            else if (bet < 0) {
                cout << "You can't bet a negative amount of money!" << endl;
            }
        } while (bet > money || bet < 0);
        money -= bet;

        //Shuffle the deck
        dealt1 = false, dealt2 = false;
        cout << "Shuffling Deck..." << endl;
        DeckFunc::deckShffl(houseDeck);

        //Deal Player hand
        do {
            loc = DeckFunc::randDeckSlot();
            if (houseDeck[loc]->OoD == false) {
                yourHand[0] = houseDeck[loc];
                houseDeck[loc]->OoD = true;
                do {
                    loc = DeckFunc::randDeckSlot();
                    if (houseDeck[loc]->OoD == false) {
                        yourHand[1] = houseDeck[loc];
                        houseDeck[loc]->OoD = true;
                        dealt2 = true;
                        dealt1 = true;
                    }
                } while (dealt2 == false);
            }
        } while (dealt1 == false);
        dealt1 = false, dealt2 = false;

        //Deal Dealer hand
        do {
            loc = DeckFunc::randDeckSlot();
            if (houseDeck[loc]->OoD == false) {
                dealerHand[0] = houseDeck[loc];
                houseDeck[loc]->OoD = true;
                do {
                    loc = DeckFunc::randDeckSlot();
                    if (houseDeck[loc]->OoD == false) {
                        dealerHand[1] = houseDeck[loc];
                        houseDeck[loc]->OoD = true;
                        dealt2 = true;
                        dealt1 = true;
                    }
                } while (dealt2 == false);
            }
        } while (dealt1 == false);

        do {
            //Print out first hand and first-turn options
            cout << "Dealer has: a " << DeckFunc::printCard(dealerHand, 0) << " and a Unknown Card.";
            cout << endl << endl;
            cout << "You have: a " << DeckFunc::printCard(yourHand, 0) << " and a " << DeckFunc::printCard(yourHand, 1) <<"."
            << endl;
            cout << "Will you Hit, Stand or Double Down?(h/s/d)";
            cin >> advance;
            cout << endl;
            if (advance != 'h' && advance != 's' && advance != 'd' ) {
                cout << "Please enter a valid option!" << endl;
            }
        } while (advance != 'h' && advance != 's' && advance != 'd');

        if (advance == 'h' || advance == 's') {
            //Advance to the rest of the play
            x = 2;
            do {
                if (advance == 'h') {
                    //If Hit
                    //Draw card
                    dealt1 = false;
                    do {
                        loc = DeckFunc::randDeckSlot();
                        if (houseDeck[loc]->OoD == false) {
                            yourHand[x] = houseDeck[loc];
                            houseDeck[loc]->OoD = true;
                            dealt1 = true;
                        }
                    }while(dealt1 == false);
                    //Print player hand
                    cout << "You have: a ";
                    for (int y = 0; y <= x; y++) {
                        cout << DeckFunc::printCard(yourHand, y) << endl;
                    }
                    //check if > 21
                    playernum = DeckFunc::valueOfHand(yourHand, x+1);
                    if (playernum > 21) {
                        lose = true;
                    }
                    else {
                        //otherwise ask what player wants to do
                        do {
                            cout << "Dealer has: a " << DeckFunc::printCard(dealerHand, 0) << ".";
                            cout << endl << endl;
                            cout << "Will you Hit or Stand?(h/s)";
                            cin >> advance;
                            cout << endl;
                            if (advance != 'h' && advance != 's') {
                                cout << "Please enter a valid option!" << endl;
                            }
                        } while (advance != 'h' && advance != 's');
                    }
                }
                if (advance == 's') {
                    //If Stand
                    //Dealer draws their cards
                    dealernum = DeckFunc::dealerplay(dealerHand, houseDeck);
                    //Output dealer's hand
                    std::cout << "The dealer has: ";
                    x = 0;
                    while (dealerHand[x] != NULL) {
                        std::cout << printCard(dealerHand, x) << endl;
                        x++;
                    }
                    lose = true;
                }
                x++;
            } while (!lose);
        }

        else
            //Double down
        {
            winMult = 2.5;

            //deal 1 card to player
            dealt1 = false;
            do {
                loc = DeckFunc::randDeckSlot();
                if (houseDeck[loc]->OoD == false) {
                    yourHand[2] = houseDeck[loc];
                    houseDeck[loc]->OoD = true;
                    dealt1 = true;
                }
            }while(dealt1 == false);
            cout << "You have: a " << DeckFunc::printCard(yourHand, 0) << ", a " << DeckFunc::printCard(yourHand, 1) << ", and a " << DeckFunc::printCard(yourHand, 2) << endl;
            playernum = DeckFunc::valueOfHand(yourHand, 3);

            //check if player is over 21, otherwise play dealer's hand
            if (playernum > 21) {
                lose = true;
            }
            else
            {
                //Dealer draws their cards
                dealernum = DeckFunc::dealerplay(dealerHand, houseDeck);
                //Output dealer's hand
                std::cout << "The dealer has: ";
                x = 0;
                while (dealerHand[x] != NULL) {
                    std::cout << printCard(dealerHand, x) << endl;
                    x++;
                }
            }
        }
        //Move into last stage of the game

        //find out hand size
        x = 0;
        while (yourHand[x] != NULL) {
            x++;
        }
        DeckFunc::valueOfHand(yourHand, x);

        //check if Aces will change the winner
        pHandA = DeckFunc::Aces(yourHand);
        dHandA = DeckFunc::Aces(dealerHand);

        if (pHandA == true) {
            if (playernum + 10 <= 21)
            {
                playernum += 10;
            }
        }
        else if (dHandA == true) {
            if (dealernum + 10 <= 21)
            {
                dealernum += 10;
            }
        }

        //check who wins
        if (dealernum > 21) {
            lose = false;
        }
        else if (playernum > 21) {
            lose = true;
        }
        else if (dealernum == playernum)
        {
            lose = true;
        }
        else if (playernum - dealernum < 0)
        {
            lose = true;
        }
        else
        {
            lose = false;
        }

        if (!lose) {
            cout << "You Win!" << endl;
            money += winMult * bet;
            cout << "You now have: $" << money << endl;
        }
        else {
            cout << "You lose!" << endl;
            cout << "You now have: $" << money << endl;
        }

        //ask if play again
        do {
            cout << "Play again?(y/n)" << endl;
            cin >> advance;
            if (advance == 'n')
            {
                quit = true;
            }
            else if (advance == 'y' && money == 0) {
                money = 1000;
                cout << "Resetting money..." << endl << endl;
            }
            else if (advance == 'y')
            {
                cout << endl << endl;
            }
            else
            {
                cout << "Please enter a valid command!" << endl;
            }
        } while (advance != 'y' && advance != 'n');
        //Reset hands and decks
        for (x = 0; x < 52; x++) {
            houseDeck[x]->OoD = false;
        }
        for (x = 0; x < 26; x++) {
            yourHand[x] = NULL;
            dealerHand[x] = NULL;
        }
    } while (!quit);
}

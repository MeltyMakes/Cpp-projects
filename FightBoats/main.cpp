//
//  main.cpp
//  FightBoats
//
//  Created by Brendan Souksamlane on 2015-09-23.
//  Copyright © 2015 All rights reserved.
//

#include <iostream>
#include "Board.hpp"
#include "Functions.hpp"
#include "AIPlayer.hpp"
using namespace std;
int main() {
    Board P1, P2;                   //P1/P2's board
    bool placed = false;            //makes sure player places 1 of each boat into the board
    bool win = false;
    int row, column;                //row and column on the board
    int player = 1;                 //determine's who's turn it is
    char charColumn, direction;     //charColumn is the character equivilant of column taking in
    //coordinates (A1). Direction is a cardinal direction determininng boat
    //placement direction
    string stringRow;  //Used to prevent crashing if a letter is inputted as a row

    int target;                     //tracks whether the shot was a hit, miss or illegal
    int P1hitcounter[5];            //tracks ships hits for each player and type of ship. [0] being a
    int P2hitcounter[5];            //gunboat etc

    char advance;

    //initialize the hit counters to 0 hits for every boat
    initializeHitCounter(P1hitcounter);
    initializeHitCounter(P2hitcounter);
    //initialize boards to default values
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            P1.setState(x, y, 0);
            P1.setBoatType(x, y, 99);
        }
    }
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            P2.setState(x, y, 0);
            P2.setBoatType(x, y, 99);
        }
    }



    do {
        cout << "***************************************************************" << endl
             << "                          FightBoats" << endl
             << "***************************************************************" << endl;
        cout << endl << endl << endl
        << "SinglePlayer or Multiplayer?(S/M)";
        cin >> advance;
        cout << endl;
        if (advance == 'S') {
            //Singleplayer
            //cout << "Select an AI difficulty (M/H)";
            //cin >> advance;
            //cout << endl;

            //Place Player 1's boats
            for (int x = 0; x < 5; x++)
            {
                do {
                    P1.printBoard();
                    cout << "Player 1, please select the first coordinates(eg. A1) for your " << translateShips(x);
                    cout << "." << endl;
                    cin >> charColumn >> stringRow;
                    column = translateCoordinatesC(charColumn);
                    row = translateCoordinatesR(stringRow);
                    if (column == 99 || row == 99) {
                        cout << "***Please enter valid coordinates!***" << endl;
                        placed = false;
                    }
                    else {
                        cout << "Enter a direction to place it (N/E/S/W)" << endl;
                        cin >> direction;


                        if (P1.placeBoat(row, column, x, direction) == 0) {
                            cout << endl << "***Please place your boat properly!***" << endl;
                            placed = false;
                        }
                        else {
                            placed = true;
                        }
                    }
                } while (!placed);
            }
            //Display board
            cout << endl << "Here is your board:" << endl;
            P1.printBoard();
            cout << "Press enter to continue: ";
            cin.get();
            cin.get();
            cout << endl << endl;

            placed = false;

            placeAIBoats(P2);

            do {
                //shoot

                if (player == 1) {
                    do {
                        do {
                            //print hidden player board
                            cout << "Your Board" << endl;
                            P1.printBoard();
                            cout << "Enemy Board" << endl;
                            P2.printHiddenBoard();
                            //ask for coordinates to shoot
                            cout << "Player 1, pick a coordinate to shoot:";
                            cin >> charColumn >> stringRow;
                            cout << endl;
                            column = translateCoordinatesC(charColumn);
                            row = translateCoordinatesR(stringRow);
                            if (column == 99 || row == 99) {
                                cout << "***Please enter valid coordinates!***" << endl;
                            }
                        } while (column == 99 || row == 99);
                        //Test target for shot
                        target = P2.shoot(row, column, P1hitcounter);

                        //tell the player what happened
                        if (target == 1) {
                            cout << "You hit!" << endl;
                        }
                        else if (target == 2) {
                            cout << "You missed!" << endl;
                        }
                        else if (target == 99) {
                            cout << "You can't shoot there!" << endl;
                        }
                    }while (target == 99);
                }
                else {
                    /*if (advance == 'M') {
                     target = AIMedium(P1, P2hitcounter);
                     }
                     else {*/
                    target = AIHard(P1, P2hitcounter);
                    //}
                    if (target == 1) {
                        cout << "AI hit!" << endl;
                    }
                    else if (target == 2) {
                        cout << "AI missed!" << endl;
                    }
                    else if (target == 99) {
                        cout << "ERROR" << endl;
                    }
                }
                //switch turns or stop the game if someone won
                if (player == 1) {
                    if (winCheck(P1hitcounter) == true) {
                        win = true;
                    }
                    else {
                        player = 2;
                    }
                }
                else {
                    if (winCheck(P2hitcounter) == true) {
                        win = true;
                    }
                    else {
                        player = 1;
                    }
                }

                cout << "Press enter to continue:" << endl;
                cin.get();
                cin.get();
                cout << endl << endl << endl;
            } while (!win);

            if (player == 1) {
                cout << "Player Wins!" << endl;
            }
            else {
                cout << "Computer Wins!" << endl;
                P1.printBoard();
            }
        }
        else if (advance == 'M') {
            //Multiplayer

            //Place Player 1's boats
            for (int x = 0; x < 5; x++)
            {
                do {
                    P1.printBoard();
                    cout << "Player 1, please select the first coordinates(eg. A1) for your " << translateShips(x);
                    cout << "." << endl;
                    cin >> charColumn >> stringRow;
                    column = translateCoordinatesC(charColumn);
                    row = translateCoordinatesR(stringRow);
                    if (column == 99 || row == 99) {
                        cout << "***Please enter valid coordinates!***" << endl;
                        placed = false;
                    }
                    else {
                        cout << "Enter a direction to place it (N/E/S/W)" << endl;
                        cin >> direction;

                        if (P1.placeBoat(row, column, x, direction) == 0) {
                            cout << endl << "***Please place your boat properly!***" << endl;
                            placed = false;
                        }
                        else {
                            placed = true;
                        }
                    }
                } while (!placed);
            }
            //Print board
            cout << endl << "Here is your board:" << endl;
            P1.printBoard();
            cout << "Press enter to continue: ";
            cin.get();
            cin.get();
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

            placed = false;
            //Place Player 2's boats
            for (int x = 0; x < 5; x++)
            {
                do {
                    P2.printBoard();
                    cout << "Player 2, please select the first coordinates(eg. A1) for your " << translateShips(x);
                    cout << "." << endl;
                    cin >> charColumn >> stringRow;
                    column = translateCoordinatesC(charColumn);
                    row = translateCoordinatesR(stringRow);
                    if (column == 99 || row == 99) {
                        cout << "***Please enter valid coordinates!***" << endl;
                        placed = false;
                    }
                    else {
                        cout << "Enter a direction to place it (N/E/S/W)" << endl;
                        cin >> direction;

                        if (P2.placeBoat(row, column, x, direction) == 0) {
                            cout << endl << "***Please place your boat properly!***" << endl;
                            placed = false;
                        }
                        else {
                            placed = true;
                        }
                    }
                } while (!placed);
            }
            //Print board
            cout << endl << "Here is your board:" << endl;
            P2.printBoard();
            cout << "Press enter to continue: ";
            cin.get();
            cin.get();
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

            //Begin guessing/shooting phase
            do {
                //shoot
                do {
                    do {
                        //print hidden player board
                        if (player == 1) {
                            cout << "Your Board" << endl;
                            P1.printBoard();
                            cout << "Enemy Board" << endl;
                            P2.printHiddenBoard();
                        }
                        else {
                            cout << "Your Board" << endl;
                            P2.printBoard();
                            cout << "Enemy Board" << endl;
                            P1.printHiddenBoard();
                        }
                        //ask for coordinates to shoot
                        cout << "Player " << player << ", pick a coordinate to shoot:";
                        cin >> charColumn >> stringRow;
                        cout << endl;
                        column = translateCoordinatesC(charColumn);
                        row = translateCoordinatesR(stringRow);
                        if (column == 99 || row == 99) {
                            cout << "***Please enter valid coordinates!***" << endl;
                        }
                    } while (column == 99 || row == 99);

                    //Test target for shot
                    if (player == 1) {
                        target = P2.shoot(row, column, P1hitcounter);
                    }
                    else {
                        target = P1.shoot(row, column, P2hitcounter);
                    }

                    //tell the player what happened
                    if (target == 1) {
                        cout << "You hit!" << endl;
                    }
                    else if (target == 2) {
                        cout << "You missed!" << endl;
                    }
                    else if (target == 99) {
                        cout << "You can't shoot there!" << endl;
                    }
                }
                while (target == 99);

                //switch turns or stop the game if someone won
                if (player == 1) {
                    if (winCheck(P1hitcounter) == true) {
                        win = true;
                    }
                    else {
                        player = 2;
                    }
                }
                else {
                    if (winCheck(P2hitcounter) == true) {
                        win = true;
                    }
                    else {
                        player = 1;
                    }
                }

                cout << "Press enter to continue:" << endl;
                cin.get();
                cin.get();
                cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            } while (!win);
            //If win
            if (player == 1) {
                cout << "Player 1 Wins!" << endl;
            }
            else {
                cout << "Player 2 Wins!" << endl;
            }
        }
        else {
            cout << "Please input 'S' or 'M'!" << endl;
        }
    } while (advance != 'S' || advance != 'M');
}

//
//  main.cpp
//  TicTacToe
//
//  Created by Brendan Souksamlane on 2016-05-27.
//  Copyright © 2016 All rights reserved.
//

#include <iostream>
#include <fstream>
#include "TicTacFunc.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    int board[3][3];            //3x3 board of integers; 1 is o, 2 is x, 0 is empty
    int place[2];               //Accepts user input for decisions when prompted
    int turn = 1;               //Keeps track of who's turn it is
    bool input;                 //For sanitized inputs
    char choice;                //For decisions
    string name;                //For file handling
    bool quit = false;          //To quit the game or not
    bool endgame = false;       //Check if the game is over via win or stalemate
    bool stalemate = false;     //If stalemate tell the players
    char *saveblock;            //Used as part of the savegame() and loadgame() functions to output a block into the file

    //Begin game introduction
    cout << "Welcome to tic tac toe!" << endl;
    do {
        //Determine if loading a game or creating a new game
        cout << "Do you have a saved game?(Y/N)";
        cin >> choice;
        if (choice == 'Y') {                                            //Load a save
            do {
                do {
                    cout << "Enter Save name:";
                    cin >> name;
                    if (!stringIsAlpha(name)) {                         //Catches non alpha names such as '.' and '$'
                        cout << "Please enter a name using only alphabetical characters!" << endl;
                    }
                } while (!stringIsAlpha(name));
            } while (!loadgame(name, saveblock, board, turn));         //Loads data directly into the variables, or loop again if couldn't load game
        }
        else if (choice == 'N') {
            //Create a blank board
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    board[a][b] = 0;
                }
            }
        }
        else {
            cout << "Please enter Y or N!" << endl;
        }
    } while (choice != 'Y' && choice != 'N');

    //Begin game instance
    do {
        do {
            drawboard(board);
            //Take Player input of coordinates
            cout << "Player " << turn << ", enter coordinates(row column): " << endl
            << "(Enter 9,9 to quit)" << endl;
            cin >> place[0] >> place[1];
            if (place[0] == 9 && place[1] == 9) {               //Coordinates of 9,9 are used as an escape value to quit game
                input = true;
                quit = true;
            }
            else if (place[0] > 3 || place[0] < 1 || place[1] > 3 || place[1] < 1 || board[place[0]-1][place[1]-1] != 0) {      //Checks for out of bounds values as well as if the space is occupied
                cout << "Incorrect input, try again." << endl;
                input = false;
            }
            else {                                              //Input is valid
                input = true;
                board[place[0]-1][place[1]-1] = turn; //Place an x or o depending on player's turn
            }
        } while (!input);

        if (quit) {
            do {
                cout << "Are you sure you want to quit? Progress will be saved.(Y/N)";          //Confirm user wants to quit
                cin >> choice;
                if (choice == 'Y') {
                    do {
                        do {
                            cout << "Enter Save name:";
                            cin >> name;
                            if (!stringIsAlpha(name)) {                 //Check that save name is alphabetical only
                                cout << "Please enter a name using only alphabetical characters!" << endl;
                            }
                        } while (!stringIsAlpha(name));
                    } while (!savegame(name, saveblock, board, turn));  //Save the game, or loop again if there was an error in saving game
                    delete saveblock;                                   //Close the pointer
                    return 0;                                           //End the game
                }
                else if (choice == 'N'){
                    quit = false;                                       //Reset quit so the player can contine playing
                }
                else {
                    cout << "Please enter Y or N!" << endl;
                }
            } while (choice != 'Y' && choice != 'N');
        }
        //Check for wins
        else {
            if (wincheck(board, turn) == 0) {       //Win scenario
                endgame = true;
            }
            else if (wincheck(board, turn) == 2){   //Stalemate scenario
                endgame = true;
                stalemate = true;
            }
            else {                                  //Nothing, thus turns switch
                switch (turn) {
                    case 1:
                        turn = 2;
                        break;

                    case 2:
                        turn = 1;
                        break;
                }
            }
        }
    } while (!endgame);

    //Game has ended somehow, declare results
    if (stalemate) {
        drawboard(board);
        cout << "Tie!" << endl;
    }
    else if (endgame) {
        drawboard(board);
        cout << "Player " << turn << " wins!" << endl;
    }

    delete saveblock;       //Close pointer
    return 0;               //End game
}


//
//  TicTacFunc.cpp
//  TicTacToe
//
//  Created by Brendan Souksamlane on 2016-05-27.
//  Copyright © 2016 All rights reserved.
//

#include "TicTacFunc.hpp"
#include <iostream>
#include <fstream>

using namespace std;

char XorO(int value) {
    /*Function takes in a value and returns x, o, or space depending on character
     a value of 1 corresponds to Player 1(O), 2 corresponds to Player 2(X), 0 corresponds to an empty space
     */
    if (value == 1) {
        return 'o';
    }
    else if (value == 2){
        return 'x';
    }
    else {
        return ' ';
    }
}

void drawboard(int board[3][3]) {
    /* Function draws the game board using Xs and Os as well as spaces.
     Dividers are added as well to make viewing the board easier.
     */
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            cout << XorO(board[a][b]);      //Print symbol to board
            if (b != 2) {
                cout << " | ";              //Put a divider after every column but the third one
            }
            else if (b == 2) {
                cout << endl;
            }
        }
        if (a != 2) {
            cout << "---------" << endl;    //Put a divider after every row but the third one
        }
    }
}

bool savegame(string filename, char * memblock, int board[3][3], int &player) {
    /* Function saves the game to a user-defined textfile name.
     Returns an error if such a file could not be created.
     If a file is found, stores the values of the board and the player's turn into the save file
     */
    ofstream file ((filename + ".txt"), ios::binary);              //Create an out file stream
    if (file.is_open())
    {
        int i = 0;
        memblock = new char [10];               //Allocate a pointer of characters of size 10, as the file will always be 10 characters long

        cout << "File saved sucessfully" << endl;

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                memblock[i] = board[a][b];      //Store the symbols on the board into the first 9 characters
                i++;
            }
        }

        memblock[9] = player;                   //Save the turn into the 10th slot

        file.write(memblock, 10);               //Write it to the file

        return true;
    }
    else {
        cout << "Unable to create file" << endl;
        return false;
    }
}

bool loadgame(string filename, char * memblock, int board[3][3], int &player) {
    /* Function loads the game from a user-defined textfile name.
     Returns an error if such a file could not be found.
     If a file is found, it directly applies the board and the player's turn to the main function's variables.
     */

    ifstream file ((filename + ".txt"), ios::in|ios::binary|ios::beg);         //Open an in file stream with the cursor at the beginning of the file
    if (file.is_open())
    {
        int i = 0;
        memblock = new char [10];       //Allocate a pointer of characters of size 10, as the file will always be 10 characters long
        file.read (memblock, 10);       //Read all 10 characters into memblock from the ifstream
        file.close();

        cout << "File loaded sucessfully" << endl;

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                board[a][b] = memblock[i];      //Store the first 9 characters in the board
                i++;
            }
        }

        player = memblock[9];                   //Store the 10th character in the player turn variable

        return true;
    }
    else {
        cout << "Unable to open file" << endl;
        return false;
    }
}

int wincheck(int board[3][3], int turn) {
    /*A function that checks whether the game is won.
     It takes the board and the current player's turn, and counts the number of symbols in each row/column/diagonal
     if there are three symbols in one of those, there is a win and we return 0.
     Otherwise, we check for a stalemate, and return 2 if one is found.
     If none of the above are found, no wins have happened and we return 1.
     */
    int test = 0;
    int a, b;
    bool stalemate = true;

    //Check rows
    for (b = 0; b < 3; b++) {
        for (a = 0; a < 3; a++) {
            if (board[b][a] == turn) {
                test++;
            }
        }
        //If we counted 3 of whatever symbol in the row, we return true
        if (test == 3) {
            return 0;
        }
        else {
            test = 0;
        }
    }

    //Check Columns
    test = 0;
    for (b = 0; b < 3; b++) {
        for (a = 0; a < 3; a++) {
            if (board[a][b] == turn) {
                test++;
            }
        }
        //If we counted 3 of whatever symbol in the column, we return true
        if (test == 3) {
            return 0;
        }
        else {
            test = 0;
        }
    }

    //Check Diagonals 1,1; 2,2; 3,3
    test = 0;
    for (a = 0; a < 3; a++) {
        if (board[a][a] == turn) {
            test++;
        }
    }
    //If we counted 3 of whatever symbol in the diagonal, we return true
    if (test == 3) {
        return 0;
    }


    //Check diagonals 3,1; 2,2; 1,3
    test = 0;
    b = 0;
    for (a = 2; a >= 0; a--) {
        if (board[a][b] == turn) {
            test++;
        }
        b++;
    }
    //If we counted 3 of whatever symbol in the diagonal, we return true
    if (test == 3) {
        return 0;
    }

    //Check for a stalemate
    for (b = 0; b < 3; b++) {
        for (a = 0; a < 3; a++) {
            if (board[b][a] == 0) {     //If the board has any empty spaces, we cannot have a stalemate
                stalemate = false;      //(Code will not predict stalemates, only call them out when they happen)
            }
        }
    }
    if (stalemate) {
        return 2;
    }

    //If none of the above are triggered, return false
    return 1;
}


bool stringIsAlpha (string item) {
    //Function checks if a string is composed of alphabetical characters and returns true or false based on that
    for (int i = 0; i < item.length(); i++) {
        if (!isalpha(item.at(i))) {
            return false;
        }
    }
    return true;
}


//
//  FightBoatsFunc.cpp
//  FightBoats
//
//  Created by Brendan Souksamlane on 2015-09-25.
//  Copyright © 2015 All rights reserved.
//

#include "Board.hpp"

int Board::getState(int row, int column) {
    //returns the state of the location
    return state[row][column];
}
int Board::getBoatType(int row, int column) {
    return boatType[row][column];
}
void Board::setState(int row, int column, int value) {
    state[row][column] = value;
}
void Board::setBoatType(int row, int column, int value) {
    boatType[row][column] = value;
}

int Board::placeBoat(int row, int column, int boatKind, char direction) {
    //Takes a row, column and direction and places boat there. Row and column must be parsed for arrays.
    //Returns 0 if failed
    int check = 0;      //Checks that the boat is not going to go off of the board
    if (row >= 10 || column >= 10 || row < 0 || column <0) {
        //Illegal locations
        return 0;
    }
    else if (state[row][column] == 0)
        //If there is an empty space
    {
        switch (boatKind) {
                //Figure out the length of the boat to be placed
            case 0:
                check = 2;
                break;
            case 1:
                check = 3;
                break;
            case 2:
                check = 3;
                break;
            case 3:
                check = 4;
                break;
            case 4:
                check = 5;
                break;
            default:
                break;
        }
        int row1 = row;         //used to test if the locations you place the boat are occupied
        int column1 = column;
        switch (direction) {
                //If the boat will go off the board by being placed in that direction, returns 0
                //Otherwise places boat and sets state to occupied(1)
            case 'N':
                for (int x = 0; x < check; x++) {
                    if (state[row1][column1] != 0) {
                        return 0;
                    }
                    row1--;
                }
                if ((row - check) + 1 < 0) {
                    return 0;
                }
                else {
                    for (int x = 0; x < check; x++) {
                        state[row][column] = 1;
                        boatType[row][column] = boatKind;
                        row--;
                    }
                }
                break;
            case 'E':
                for (int x = 0; x < check; x++) {
                    if (state[row1][column1] != 0) {
                        return 0;
                    }
                    column1++;
                }
                if (column + check > 10) {
                    return 0;
                }
                else {
                    for (int x = 0; x < check; x++) {
                        state[row][column] = 1;
                        boatType[row][column] = boatKind;
                        column++;
                    }
                }
                break;
            case 'S':
                for (int x = 0; x < check; x++) {
                    if (state[row1][column1] != 0) {
                        return 0;
                    }
                    row1++;
                }
                if (row + check > 10) {
                    return 0;
                }
                else {
                    for (int x = 0; x < check; x++) {
                        state[row][column] = 1;
                        boatType[row][column] = boatKind;
                        row++;
                    }
                }
                break;
            case 'W':
                for (int x = 0; x < check; x++) {
                    if (state[row1][column1] != 0) {
                        return 0;
                    }
                    column1--;
                }
                if ((column - check) + 1 < 0) {
                    return 0;
                }
                else {
                    for (int x = 0; x < check; x++) {
                        state[row][column] = 1;
                        boatType[row][column] = boatKind;
                        column--;
                    }
                }
                break;
            default:
                return 0;
                break;
        }
        return 1;
    }
    //catch-all in case
    return 0;
}

void Board::printBoard() {
    cout << "     A   B   C   D   E   F   G   H   I   J" << endl;
    for (int x = 0; x < 10; x++) {
        cout << " ------------------------------------------" << endl;
        cout << (x+1);
        if ((x+1) != 10) {
            cout << " ";
        }
        for (int y = 0; y < 10; y++) {
            cout << " | ";
            switch (state[x][y]) {
                case 0:
                    cout << " ";
                    break;
                case 1://Boat
                    switch (boatType[x][y]) {
                        case 0:
                            cout << "G";
                            break;
                        case 1:
                            cout << "Y";
                            break;
                        case 2:
                            cout << "D";
                            break;
                        case 3:
                            cout << "F";
                            break;
                        case 4:
                            cout << "W";
                            break;
                        default:
                            break;
                    }
                    break;
                case 2://Miss
                    cout << "X";
                    break;
                case 3://Hit boat
                    switch (boatType[x][y]) {
                        case 0:
                            cout << "g";
                            break;
                        case 1:
                            cout << "y";
                            break;
                        case 2:
                            cout << "d";
                            break;
                        case 3:
                            cout << "f";
                            break;
                        case 4:
                            cout << "w";
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    cout << " ";
                    break;
            }
        }
        cout << " | " << endl;
    }
    cout << "  ------------------------------------------" << endl;
}

void Board::printHiddenBoard() {
    //Prints the board but only hit and miss spots. Boats are indistinguishable from empty cells
    cout << "     A   B   C   D   E   F   G   H   I   J" << endl;
    for (int x = 0; x < 10; x++) {
        cout << " ------------------------------------------" << endl;
        cout << (x+1);
        if ((x+1) != 10) {
            cout << " ";
        }
        for (int y = 0; y < 10; y++) {
            cout << " | ";
            switch (state[x][y]) {
                case 0:
                    cout << " ";
                    break;
                case 1://hides the boats
                    cout << " ";
                    break;
                case 2:
                    cout << "X";
                    break;
                case 3:
                    switch (boatType[x][y]) {
                        case 0:
                            cout << "G";
                            break;
                        case 1:
                            cout << "Y";
                            break;
                        case 2:
                            cout << "D";
                            break;
                        case 3:
                            cout << "F";
                            break;
                        case 4:
                            cout << "W";
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    cout << " ";
                    break;
            }
        }
        cout << " | " << endl;
    }
    cout << "  ------------------------------------------" << endl;
}

int Board::shoot(int row, int column, int hitcounter[]) {
    //Shoots the location and returns 1 on hit, 2 on miss or 99 on illegal target, TAKES ACTUAL LOCATIONS
    if (row >= 10 || row < 0 || column >= 10 || column < 0) {
        return 99;
    }
    else if (state[row][column] == 0) {
        state[row][column] = 2;
        return 2;
    }
    else if (state[row][column] == 2 || state[row][column] == 3) {
        return 99;
    }
    else if (state[row][column] == 1) {
        int x = boatType[row][column];
        hitcounter[x]++;
        state[row][column] = 3;
        return 1;
    }
    return 99;
};

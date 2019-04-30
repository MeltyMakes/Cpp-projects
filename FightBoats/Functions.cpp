//
//  Functions.cpp
//  FightBoats
//
//  Created by Brendan Souksamlane on 2015-10-05.
//  Copyright © 2015 All rights reserved.
//

#include "Functions.hpp"
#include <iostream>

int translateCoordinatesC(char column) {
    //Turns letter into ACTUAL array location (ie A=0, J=9)
    switch (column) {
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
        case 'E':
            return 4;
            break;
        case 'F':
            return 5;
            break;
        case 'G':
            return 6;
            break;
        case 'H':
            return 7;
            break;
        case 'I':
            return 8;
            break;
        case 'J':
            return 9;
            break;
        default:
            //Error
            return 99;
            break;
    }
}

int translateCoordinatesR(string row) {
    //turns row string into a number; if letter is inputted returns 99 for error
    if (row == "1") {
        return 0;
    }
    else if (row == "2") {
        return 1;
    }
    else if (row == "3") {
        return 2;
    }
    else if (row == "4") {
        return 3;
    }
    else if (row == "5") {
        return 4;
    }
    else if (row == "6") {
        return 5;
    }
    else if (row == "7") {
        return 6;
    }
    else if (row == "8") {
        return 7;
    }
    else if (row == "9") {
        return 8;
    }
    else if (row == "10") {
        return 9;
    }
    else {
        return 99;
    }
}

string translateShips(int shipType) {
    //takes the int identifier of the boat and returns it's full name
    switch (shipType) {
        case 0:
            return "Gunboat (length 2)";
            break;
        case 1:
            return "Yacht (length 3)";
            break;
        case 2:
            return "Destroyer (length 3)";
            break;
        case 3:
            return "FightBoat (length 4)";
            break;
        case 4:
            return "Warship (length 5)";
            break;
        default:
            return "ERROR";
            break;
    }
}

bool winCheck(int hitcounter[]) {
    //counts the hits and if all boats were hit enough times, returns true
    int check = 0;
    for (int x = 0; x < 5; x++) {
        switch (x) {
            case 0:
                if (hitcounter[x] == 2) {
                    check++;
                }
                break;
            case 1:
                if (hitcounter[x] == 3) {
                    check++;
                }
                break;
            case 2:
                if (hitcounter[x] == 3) {
                    check++;
                }
                break;
            case 3:
                if (hitcounter[x] == 4) {
                    check++;
                }
                break;
            case 4:
                if (hitcounter[x] == 5) {
                    check++;
                }
                break;
            default:
                break;
        }
    }
    if (check == 5) {
        return true;
    }
    else {
        return false;
    }
};

void initializeHitCounter(int hitcounter[]) {
    //sets all boat hit counts to 0
    for (int x = 0; x < 5; x++) {
        hitcounter[x] = 0;
    }
}

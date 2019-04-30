//
//  FightBoatsFunc.hpp
//  FightBoats
//
//  Created by Brendan Souksamlane on 2015-09-25.
//  Copyright © 2015 All rights reserved.
//

#ifndef FightBoatsFunc_hpp
#define FightBoatsFunc_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Board {
public:
    int getState(int row, int column);
    int getBoatType(int row, int column);
    void setState(int row, int column, int value);
    void setBoatType(int row, int column, int value);
    int placeBoat(int row, int column, int boatKind, char direction);
    void printBoard();
    void printHiddenBoard();
    int shoot(int row, int column, int hitcounter[]);
private:
    int state[10][10];
    int boatType[10][10];
};
#endif /* FightBoatsFunc_hpp */

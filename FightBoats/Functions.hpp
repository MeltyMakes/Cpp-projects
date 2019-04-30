//
//  Functions.hpp
//  FightBoats
//
//  Created by Brendan Souksamlane on 2015-10-05.
//  Copyright © 2015 All rights reserved.
//

#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

int translateCoordinatesC(char column);
int translateCoordinatesR(string row);
string translateShips(int shipType);
bool winCheck(int hitcounter[]);
void initializeHitCounter(int hitcounter[]);

#endif /* Functions_hpp */

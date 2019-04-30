//
//  AIPlayer.hpp
//  FightBoats
//
//  Created by Brendan Souksamlane on 2015-10-05.
//  Copyright © 2015 All rights reserved.
//

#ifndef AIPlayer_hpp
#define AIPlayer_hpp

#include <stdio.h>
#include "Board.hpp"
int AIEasy();
//int AIMedium(Board &PlayerBoard, int hitcounter[]);
int AIHard(Board &Playerboard, int hitcounter[]);
void placeAIBoats (Board &AIBoard);
//void calcHProb(int boat, Board PlayerBoard, int ProbabilityMap[10][10]);
#endif /* AIPlayer_hpp */

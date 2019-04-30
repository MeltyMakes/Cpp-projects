//
//  TicTacFunc.hpp
//  TicTacToe
//
//  Created by Brendan Souksamlane on 2016-05-27.
//  Copyright © 2016 All rights reserved.
//

#ifndef TicTacFunc_hpp
#define TicTacFunc_hpp

#include <stdio.h>
#include <string>
#include <cstdlib>
void drawboard(int board[3][3]);
int wincheck(int board[3][3], int turn);
bool savegame(std::string filename, char * memblock, int board[3][3], int &player);
bool loadgame(std::string filename, char * memblock, int board[3][3], int &player);
bool stringIsAlpha (std::string item);
#endif /* TicTacFunc_hpp */

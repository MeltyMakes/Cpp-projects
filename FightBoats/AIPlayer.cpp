//
//  AIPlayer.cpp
//  FightBoats
//
//  Created by Brendan Souksamlane on 2015-10-05.
//  Copyright © 2015 All rights reserved.
//

#include "AIPlayer.hpp"
#include "Board.hpp"

/*
int AIMedium(Board &PlayerBoard, int hitcounter[]) {
    //Probability density, returns result of shooting
    int map[10][10];
    int compare = 0;        //used to find the highest probability number
    int length = 0;         //Tracks boat length
    int shootData;          //tracks result of shoot
    int boattype;           //used to check whether hunt mode should end
    int x, y;
    int a = 0, b = 0;               //Stores coordinates of highest probability number
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            map[x][y] = 0;
        }
    }
   // if (hunt) {
        //Caclulate the probability for the longest ship in play
        if (hitcounter[4] != 5) {
            length = 5;
        }
        else if (hitcounter[3] != 4) {
            length = 4;
        }
        else if (hitcounter[2] != 3) {
            length = 3;
        }
        else if (hitcounter[1] != 3) {
            length = 3;
        }
        else if (hitcounter[0] != 2) {
            length = 2;
        }
        calcHProb(length, PlayerBoard, map);
   // }

    //Find the highest probability spot and store coordinates in a,b
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            if (map[x][y] > compare) {
                compare = map[x][y];
                a = x;
                b = y;
            }
        }
    }
    //Shoot it
    shootData = PlayerBoard.shoot(a, b, hitcounter);
    if (shootData == 1) {
        //If hit, check if any ships were sunk
        if (hunt) {
            hunt = false;
        }
        else {
            boattype = PlayerBoard.getBoatType(a, b);
            switch (boattype) {
                case 0:
                    length = 2;
                    break;
                case 1:
                    length = 3;
                    break;
                case 2:
                    length = 3;
                    break;
                case 3:
                    length = 4;
                    break;
                case 4:
                    length = 5;
                    break;
                default:
                    break;
            }
            if (hitcounter[boattype] == length) {
                //if the boat type's hits = it's actual length ie it has been sunk
                hunt = true;
            }
        }

    return shootData;
};*/
/*
void calcHProb(int boat, Board PlayerBoard, int ProbabilityMap[10][10]) {
    //Creates a probability map and stores it in ProbabilityMap. Adds 1 to every valid spot for a boat
    //runs over spots multipile times, end result is that the most run over are most likely and larger #s
    int row, column;
    int a, b;
    int sum = -1; //used to undo overcounting
    bool valid = true;//checks if spaces are vaild for the boat to exist in
    //Create a probability map
    for (row = 0; row < 10; row++) {
        for (column = 0; column < 10; column++) {
            if ((row - boat) + 1 >= 0) {
                //North
                b = row;
                for (a = boat; a > 0; a--) {
                    if(PlayerBoard.getState(b, column) == 3 || PlayerBoard.getState(b, column) == 2) {
                        valid = false;
                    }
                    b--;
                }
                if (valid) {
                    b = row;
                    for (a = boat; a > 0; a--) {
                        ProbabilityMap[b][column]++;
                        b--;
                    }
                    sum++;
                }
            }
            valid = true;
            if ((column + boat) <= 10) {
                //East
                b = column;
                for (a = boat; a > 0; a--) {
                    if(PlayerBoard.getState(row, b) == 3 || PlayerBoard.getState(row, b) == 2) {
                        valid = false;
                    }
                    b++;
                }
                if (valid) {
                    b = column;
                    for (a = boat; a > 0; a--) {
                        ProbabilityMap[row][b]++;
                        b++;
                    }
                    sum++;
                }
            }
            valid = true;
            if ((row + boat) <= 10) {
                //South
                b = row;
                for (a = boat; a > 0; a--) {
                    if(PlayerBoard.getState(b, column) == 3 || PlayerBoard.getState(b, column) == 2) {
                        valid = false;
                    }
                    b++;
                }
                if (valid) {
                    b = row;
                    for (a = boat; a > 0; a--) {
                        ProbabilityMap[b][column]++;
                        b++;
                    }
                    sum++;
                }
            }
            valid = true;
            if ((column - boat) + 1 >= 0) {
                //West
                b = column;
                for (a = boat; a > 0; a--) {
                    if(PlayerBoard.getState(row, b) == 3 || PlayerBoard.getState(row, b) == 2) {
                        valid = false;
                    }
                    b--;
                }
                if (valid) {
                    b = column;
                    for (a = boat; a > 0; a--) {
                        ProbabilityMap[row][b]++;
                        b--;
                    }
                    sum++;
                }
            }
            if (sum != -1) {
                ProbabilityMap[row][column] -= sum; //undo any double counts on the space being inspected
            }
            sum = -1;
        }
    }
}*/

int AIHard(Board &Playerboard, int hitcounter[]) {
    //Shoots boats one by one, returns result of shooting
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (Playerboard.getState(x, y) == 1) {
                return (Playerboard.shoot(x, y, hitcounter));
            }
        }
    }
    return 99; //error
}
void placeAIBoats (Board &AIBoard) {
    //Takes a row, column and direction and places boat there. Row and column must be parsed for arrays.
    //Returns 0 if failed
    int row, column, direction, boatKind;
    bool fail, check1;
    int check = 0;//Checks that the boat is not going to go off of the board
    for (boatKind = 0; boatKind < 5; boatKind++) {
        srand((unsigned)time(0));
        do {
            row = rand() % 10;
            column = rand() % 10;
            direction = rand() % 4;
            fail = true;
            check1 = false;
            if (AIBoard.getState(row, column) == 0)
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
                    case 0://North
                        for (int x = 0; x < check; x++) {
                            if (AIBoard.getState(row1, column1) != 0) {
                                check1 = true;
                            }
                            row1--;
                        }
                        if ((row - check) + 1 < 0 || check1 == true) {
                            fail = true;
                        }
                        else {
                            for (int x = 0; x < check; x++) {
                                AIBoard.setState(row, column, 1);
                                AIBoard.setBoatType(row, column, boatKind);
                                row--;
                            }
                            fail = false;
                        }
                        break;
                    case 1://East
                        for (int x = 0; x < check; x++) {
                            if (AIBoard.getState(row1, column1) != 0) {
                                check1 = true;
                            }
                            column1++;
                        }
                        if (column + check > 10 || check1 == true) {
                            fail = true;
                        }
                        else {
                            for (int x = 0; x < check; x++) {
                                AIBoard.setState(row, column, 1);
                                AIBoard.setBoatType(row, column, boatKind);
                                column++;
                            }
                            fail = false;
                        }
                        break;
                    case 2://South
                        for (int x = 0; x < check; x++) {
                            if (AIBoard.getState(row1, column1) != 0) {
                                check1 = true;
                            }
                            row1++;
                        }
                        if (row + check > 10 || check1 == true) {
                            fail = true;
                        }
                        else {
                            for (int x = 0; x < check; x++) {
                                AIBoard.setState(row, column, 1);
                                AIBoard.setBoatType(row, column, boatKind);
                                row++;
                            }
                            fail = false;
                        }
                        break;
                    case 3://West
                        for (int x = 0; x < check; x++) {
                            if (AIBoard.getState(row1, column1) != 0) {
                                check1 = true;
                            }
                            column1--;
                        }
                        if ((column - check) + 1 < 0 || check1 == true) {
                            fail = true;
                        }
                        else {
                            for (int x = 0; x < check; x++) {
                                AIBoard.setState(row, column, 1);
                                AIBoard.setBoatType(row, column, boatKind);
                                column--;
                            }
                            fail = false;
                        }
                        break;
                    default:
                        fail = true;
                        break;
                }
            }
        }
        while (fail);
    }
}

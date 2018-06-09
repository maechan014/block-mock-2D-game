#ifndef BOARD_H
#define BOARD_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

#include "Shapes.h"
#include "Levels.h"
#include "Player.h"

#define INDEX 10
#define BLOCK 10

using namespace std;

/** This class stores the blocks that are already stacked at the top of the board.
It is responsible for displaying and updating the playing board. **/

class Board{
public:
    Board();
    Board(int);
    ~Board();

    Shapes shape;
    Levels level;
    bool isEmpty();
    void init();
    void displayBoard();
    void displayVisual();
    void displayMatrix_2();
    void displayMatrix();             // console purpose, not included in UI
    void generateVisual(int);
    void updateBoard(float, float);

    int totalBlocks;                // stores the number of blocks present in the board
    int blockStatus;
    vector<vector<int> > board;

    int getTotalBlocks();
    int getBlockNumber(float);
    int getIndexNumber(float);
    float getPositionX(int);
    float getPositionY(int);

private:
};

#endif // BOARD_H

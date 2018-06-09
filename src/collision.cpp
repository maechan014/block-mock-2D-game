#include "Collision.h"

Collision::Collision(){

}


Collision::~Collision(){

}


bool Collision::checkBorderCollision(float player, int borderType){
    if (borderType == 1){                   // right border (white line)
        return (player + 0.1 > -.02);
    } else if (borderType == 2){            // left border or boundary
        return (player < -1);
    } else if (borderType == 3){            // upper border or boundary
        return (player > 1);
    }
  return false;
}

/** @return true if collision is detected between board's blocks and new block **/
bool Collision::checkBlockCollision(float posX, float posY, vector<vector<int> > board){
  Board b;
  int blockAbove, blockCurrent, index, block;
      if (posY > 0.01){
        //cout << "current board[" << b.getIndexNumber(posY) << "][" << b.getBlockNumber(posX) << "] = " << board[b.getIndexNumber(posY)][b.getBlockNumber(posX)] << '\n';
        index = b.getIndexNumber(posY);
        block = b.getBlockNumber(posX);
        blockCurrent = board[index][block];
        blockAbove = board[index-1][block];

        if(blockAbove != 2 && !(blockCurrent == 1 && checkBlockAbove(blockAbove))){
          return false;
        } else if (blockAbove == 2 || (blockCurrent == 1 && checkBlockAbove(blockAbove))){
          return true;
        }
      } else {
        return false;
      }
    return false;
}

bool Collision::checkBlockAbove(int block){
  return (block == 0 || block == 3);
}

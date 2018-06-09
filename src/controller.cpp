#include "Controller.h"
#include <iostream>

#define RIGHTBORDER 1
#define LEFTBORDER  2
#define UPPERBORDER 3

using namespace std;

Controller::Controller(){
    rightkeyPressed = false;
    leftkeyPressed = false;
    upkeyPressed = false;
    enterkeyPressed = false;
    isPlaying = true;
    isMatched = true;
    level = 1;
}

Controller::~Controller(){

}

void Controller::newLevel(int level){
}


void Controller::initController(){
    rightkeyPressed = false;
    leftkeyPressed = false;
    upkeyPressed = false;
}

void Controller::play(){
  if(isPlaying){
    if(!isMatched){
      Text::renderText("Game Over!", -0.18,0,1,1,1,1);
    }
    background.renderBorder();
    b.displayBoard();
    //b.displayMatrix();
    //cout << "Render text" << endl;

    if(player.isNewBlock){
        player.isNewBlock = false;
        initController();
        player.initPlayer();
        player.renderBlock();
    } else {
        player.renderBlock();
    }
  } else {
    Text::renderText("Game Over!", -0.18,0,1,1,1,1);
  }
}

void Controller::generateBlock(float posX, float posY){
  b.updateBoard(posX, posY);
  player.isNewBlock = true;
  cout << "Generate new block..." << '\n' << '\n';
}

bool Controller::checkPlayingBoard(int i, int j){
  int leftBoard = b.board[i][j];
  int rightBoard = b.board[i][j+10];
  int leftBoardAbove, rightBoardAbove;

  cout << "index: " << i << endl;
  if (leftBoard <= rightBoard){
    if(i-1 > -1){
      rightBoardAbove = b.board[i-1][j+10];
      leftBoardAbove = b.board[i-1][j];

      cout << "leftBoard: " << leftBoard << " ; "<< "rightBoard: " << rightBoard << '\n';
      cout << "leftAbove: " << leftBoardAbove << " ; "<< "rightAbove: " << rightBoardAbove << '\n';
      if ((leftBoard == 2 && rightBoard == 3 && (i+1 < 10) && b.board[i+1][j] != 0) ||
         (leftBoard == 1 && leftBoardAbove == 3 && rightBoardAbove == 2) ||
         (leftBoardAbove < rightBoardAbove)){
        cout << "Blocks doesn't match!" << '\n';
      return false;
      }
    }
    cout << "Blocks Match!" << '\n';
    return true;
  } else if (leftBoard == 3 && rightBoard == 1){
    cout << "Blocks Match!" << '\n';
    return true;
  } else {
    cout << "Blocks doesn't match!" << '\n';
    return false;
  }
}

void Controller::movePlayer(){
  float posY = player.getPlayerPosY();
  float posX = player.getPlayerPosX();
  int index = b.getIndexNumber(posY);
  int block = b.getBlockNumber(posX);

  if (rightkeyPressed && !upkeyPressed){
    if(!collision.checkBorderCollision(posX, RIGHTBORDER)){
      player.setPlayerPosX(posX + 0.1);
    }
    rightkeyPressed = false;
  } else if (leftkeyPressed && !upkeyPressed){
      if(!collision.checkBorderCollision(posX, LEFTBORDER)){
        player.setPlayerPosX(posX - 0.1);
      }
    leftkeyPressed = false;
  } else if (upkeyPressed){
    if(!collision.checkBorderCollision(posY, UPPERBORDER)){
      if(!collision.checkBlockCollision(posX, posY, b.board)){
        player.setPlayerPosY(posY + 0.1);
      } else {
        upkeyPressed = false;
        generateBlock(posX, posY);
        if (!(checkPlayingBoard(index, block))){
          isMatched = false;
        }
      }
    } else {
      upkeyPressed = false;
      generateBlock(posX, posY);
      if (!(checkPlayingBoard(index, block))){
        isMatched = false;
      }
    }
  } else if (enterkeyPressed && !upkeyPressed){
      if(posY > 0.01){      // disables enter as long as the block haven't reached the boundary yet
        int blockAbove, blockCurrent;

        blockCurrent = b.board[index][block];
        if (index != 0){
          blockAbove = b.board[index-1][block];
          if(blockAbove != 0 && blockAbove != 2 && blockCurrent != 1){
            b.board[b.getIndexNumber(posY)-1][b.getBlockNumber(posX)] = blockAbove + 2;
          }
        }
        enterkeyPressed = false;
        generateBlock(posX, posY);
        if (!(checkPlayingBoard(index, block))){
          isMatched = false;
        }
      }
  }
  glClear(GL_COLOR_BUFFER_BIT);
  play();
  glutSwapBuffers();

}

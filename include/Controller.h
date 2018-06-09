#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

#include "Levels.h"
#include "Player.h"
#include "Board.h"
#include "Text.h"
#include "Background.h"

class Controller{
public:
  Controller();
  ~Controller();

  int level;

  Board b;
  Levels l;
  Player player;
  Background background;
  Collision collision;

  void play();
  void movePlayer();
  void newLevel(int);
  void initController();
  void generateBlock(float, float);
  bool checkPlayingBoard(int, int);

  bool enterkeyPressed;
  bool rightkeyPressed;
  bool leftkeyPressed;
  bool upkeyPressed;
  bool isPlaying;
  bool isMatched;

private:

};

#endif // CONTROLLER_H

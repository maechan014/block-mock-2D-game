#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

#include "Collision.h"
#include "Shapes.h"

using namespace std;

class Player{
public:
    Player();
    ~Player();

    void renderBlock();         // renders the player's new cube
    void initPlayer();

    float getPlayerPosX();
    float getPlayerPosY();

    void setPlayerPosition(float, float);
    void setPlayerPosX(float);
    void setPlayerPosY(float);
    bool isNewBlock;

private:
    float posX;
    float posY;

};

#endif // PLAYER_H


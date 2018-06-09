#include "Player.h"

Player::Player(){
    posX = -.6;
    posY = -.8;
    isNewBlock = false;
}

Player::~Player(){

}
void Player::initPlayer(){
    posX = -.6;
    posY = -.8;
    isNewBlock = false;
}

void Player::renderBlock(){
    glColor3f(1.0,1.0,1.0);
    Shapes::drawBlock(getPlayerPosX(), getPlayerPosY());
}


float Player::getPlayerPosX(){
    return posX;
}

float Player::getPlayerPosY(){
    return posY;
}

void Player::setPlayerPosition(float posX, float posY){
    setPlayerPosX(posX);
    setPlayerPosY(posY);

}

void Player::setPlayerPosX(float posX){
    this->posX = posX;
}

void Player::setPlayerPosY(float posY){
    this->posY = posY;
}



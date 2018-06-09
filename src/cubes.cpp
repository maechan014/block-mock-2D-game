#include "Cubes.h"

/**
Renders the initial block of cube at the very start
**/

Cubes::Cubes(){
    posX = -.6;
    posY = -.8;
    createCube = false;
}

Cubes::~Cubes(){

}


void Cubes::renderCube(){
    glColor3f(1.0,1.0,1.0);
    Shapes::drawBlock(getCubePosX(), getCubePosY());

}

void Cubes::setCubePosition(float x, float y){
    setCubePosX(posX);
    setCubePosY(posY);
}

void Cubes::setCubePosX(float posX){
    this->posX = posX;
}

void Cubes::setCubePosY(float posY){
    this->posY = posY;
}

float Cubes::getCubePosX(){
    return posX;
}

float Cubes::getCubePosY(){
    return posY;
}


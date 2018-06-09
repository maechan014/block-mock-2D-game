#ifndef CUBES_H
#define CUBES_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

#include "Collision.h"
#include "Shapes.h"

class Cubes{
public:
    Cubes();
    ~Cubes();

    void renderCube();
    void setCubePosY(float);
    void setCubePosX(float);
    void setCubePosition(float, float);
    float getCubePosX();
    float getCubePosY();
    bool createCube;


private:
    float posX;
    float posY;
};
#endif // CUBES_H

#ifndef COLLISION_H
#define COLLISION_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

#include "Background.h"
#include "Board.h"

using namespace std;

class Collision{
public:
    Collision();
    ~Collision();

    bool checkBorderCollision(float,int);
    bool checkBlockCollision(float, float, vector<vector<int> >);
    bool checkBlockAbove(int);


private:

};

#endif // COLLISION_H

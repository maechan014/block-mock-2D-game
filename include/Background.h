#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

#include "Shapes.h"

class Background{
public:
    Background();
    ~Background();

    void renderbg();
    void renderBorder();

};

#endif // BACKGROUND_H

#ifndef SHAPES_H
#define SHAPES_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

class Shapes{
public:
    Shapes();
    ~Shapes();

    static void drawBlock(float, float);
    static void drawBoard(float, float);
    static void drawVisual(float, float);
    static void drawBackground();
    static void drawBorder();
    static void drawRuler();

};

#endif // SHAPES_H

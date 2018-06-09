#ifndef VISUAL_H
#define VISUAL_H
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Shapes.h"

using namespace std;

class Visual{
public:
    Visual();
    ~Visual();

    int index;
    int block;
    float getX(int);
    float getY(int);

    void init();
    void generateVisual(int, int);
    void displayVisual();
    void randomizeShape();
    void displayVisualMatrix();
    vector<vector<int> > visualMatrix;

private:
  float x;
  float y;
};

#endif // VISUAL_H

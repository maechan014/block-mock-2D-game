#include "Shapes.h"

using namespace std;

Shapes::Shapes(){

}

Shapes::~Shapes(){

}


void Shapes::drawBoard(float x, float y){
  glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x, y-(0.1));
        glVertex2f(x+(0.1), y-(0.1));
        glVertex2f(x+(0.1), y);
    glEnd();
  glPopMatrix();

}

void Shapes::drawVisual(float x, float y){
  glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x, y-(0.1));
        glVertex2f(x+(0.1), y-(0.1));
        glVertex2f(x+(0.1), y);
    glEnd();
  glPopMatrix();

}



void Shapes::drawBlock(float x, float y){
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex2f(x, y);                   // -.6 for x and -.8 for y as initial position for blocks
            glVertex2f(x, y-(0.1));
            glVertex2f(x+(0.1), y-(0.1));
            glVertex2f(x+(0.1), y);
        glEnd();

        glColor3f(1.0,.567,0.1922);
        glBegin(GL_POLYGON);
            glVertex2f(x+.001, y-.001);
            glVertex2f(x+.001, (y+.001)-(0.1));
            glVertex2f(x-.001+(0.1), (y+.001)-(0.1));
            glVertex2f(x-.001+(0.1), y-.001);
        glEnd();
    glPopMatrix();
}

void Shapes::drawBorder(){
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex2f(0, 1);                   // -.02, 10
            glVertex2f(0, -1);
            glVertex2f(.02, -1);
            glVertex2f(.02, 1);
        glEnd();
    glPopMatrix();
}

void Shapes::drawRuler(){
  glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex2f(-1, 0);
            glVertex2f(-.9, 0);
            glVertex2f(-.9, .1);
            glVertex2f(-1, .1);
        glEnd();
    glPopMatrix();
}

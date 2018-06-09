#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <time.h>
#include <iostream>

#include "Controller.h"

using namespace std;

Controller control;
Board board;

static void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  control.background.renderBorder();
  control.b.generateVisual(1);
  //control.b.displayMatrix();
  control.b.displayBoard();
  control.player.renderBlock();
  glutSwapBuffers();
}

void specialKey (unsigned char key, int x, int y){
  switch(key){
  case 13:
    control.upkeyPressed = false;
    control.enterkeyPressed = true;
    control.movePlayer();
    break;
  }
}

void moveFunction(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            if (!control.upkeyPressed){
              control.rightkeyPressed = true;
              control.movePlayer();
            } else {
              control.rightkeyPressed = false;
            }
            break;
        case GLUT_KEY_LEFT:
            if (!control.upkeyPressed){
              control.leftkeyPressed = true;
              control.movePlayer();
            } else {
              control.leftkeyPressed = false;
            }
            break;
        case GLUT_KEY_UP:
            control.upkeyPressed = true;
            control.movePlayer();
            break;
        // space bar = 32

    }
}

int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
  glutInitWindowSize(640,500);
  glutInitWindowPosition(10,10);
  glutCreateWindow("Shaper");

  glEnable(GLUT_MULTISAMPLE);
  glutDisplayFunc(display);
  glutSpecialFunc(moveFunction);
  glutKeyboardFunc(specialKey);

  glutMainLoop();

	return 0;
}


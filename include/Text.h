#ifndef TEXT_H
#define TEXT_H

#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Text{
  public:
    Text();
    ~Text();

    static void renderText(string, float, float, float, float, float, float);

  private:
};

#endif // TEXT_H


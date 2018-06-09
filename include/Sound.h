#ifndef SOUND_H
#define SOUND_H

#include <windows.h>
#include <GL/glut.h>

class Sound{
  public:
    Sound();
    ~Sound();

    static void playMain();
    static void playBlip();
    static void playPress();
};

#endif // SOUND_H


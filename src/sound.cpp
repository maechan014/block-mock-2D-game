#include "sound.h"

Sound::Sound(){
}

Sound::~Sound(){
}

void Sound::playMain(){
    PlaySound("", NULL,  SND_FILENAME | SND_ASYNC);
}

void Sound::playBlip(){
     PlaySound("", NULL,  SND_FILENAME | SND_ASYNC);
}

void Sound::playPress(){
    PlaySound("", NULL,  SND_FILENAME | SND_ASYNC );
}




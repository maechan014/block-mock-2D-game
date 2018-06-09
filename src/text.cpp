#include "Text.h"

Text::Text(){
}

Text::~Text(){
}

void Text::renderText(string str, float px, float py, float r, float g, float b, float alpha){
    int l = str.size(), i;
    glPushMatrix();
        glColor4f(r, g, b ,alpha);
        glRasterPos3f(px, py, 0);

        for(i = 0; i < l; i++){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
        }

    glPopMatrix();
}


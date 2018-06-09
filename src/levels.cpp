#include "Levels.h"

Levels::Levels(){
  index = 3;
  block = 15;

}

Levels::~Levels(){

}

void Levels::setLevel(int level){
  if(level == 1){
    index = 3;
    block = 15;   //
  } else if (level == 2){
    index = 3;
    block = 16;
  } else if (level == 3){
    index = 3;
    block = 17;
  } else if (level == 4){
    index = 4;
    block = 17;
  } else if (level == 5){
    index = 4;
    block = 18;
  } else if (level == 6){
    index = 4;
    block = 19;
  }
}

int Levels::getIndex(){
  return index;
}

int Levels::getBlock(){
  return block;
}

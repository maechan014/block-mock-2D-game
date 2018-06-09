#include "Visual.h"

#define V_BLOCK 10
#define V_INDEX 10


Visual::Visual(){
  visualMatrix.resize(10,vector<int>(10, 0));
  int number;
  for(int j = 0; j < V_INDEX; j++){
    for(int i = 0; i <  V_BLOCK; i++){
      number = rand()%3;
      visualMatrix[j][i] = number;
    }
  }
}

Visual::~Visual(){

}

void Visual:: init(){
}

void Visual::generateVisual(int index, int block){
  int number;
  for(int j = 0; j < index; j++){
    for(int i = 0; i <  block; i++){
      number = rand()%3;
      visualMatrix[j][i] = number;
    }
  }
}

float Visual::getY(int index){
 return (1-(index*0.1));
}

float Visual::getX(int block){
 return ((block*0.1));
}

void Visual::displayVisualMatrix(){
  cout << "Show visual..." << '\n';
  for(int j = 0; j < V_INDEX; j++){
    for(int i = 0; i < V_BLOCK; i++){
      cout << "[" << visualMatrix[j][i] << "] ";
    }
   cout << '\n';
  }
  cout << endl;
}


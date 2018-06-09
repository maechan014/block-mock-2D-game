#include "Board.h"

Board::Board(){
  totalBlocks = 0;
   board.resize(10, vector<int>(20, 0));
   for(int j = 0; j < 10; j++){
    for(int i = 0; i < 20; i++){
      board[j][i] = 0;
    }
  }
}

Board::~Board(){
}

void Board::init(){
}

int Board::getIndexNumber(float y){
  int i, index;
  i =  y * -10;
  index = (i + 10);

  return index;
}

int Board::getBlockNumber(float x){
  int b, block;
  b = x * 10;
  block = (b + 10);
  return block;
}

/** updates the board every time blocks are added on the stack **/
void Board::updateBoard(float x, float y){
  int index, block, val;
  block = getBlockNumber(x);
  index = getIndexNumber(y);

  val = board[index][block] + 1;
  totalBlocks += 1;
  board[index][block] = val;
  displayMatrix();
  cout << "X and Y: " << x << ", " << y << endl;
  cout << "Total Blocks #: " << totalBlocks << endl;
  cout << "board[" << index << "][" << block << "] = " << board[index][block] << endl << endl;
}

/** displays the overall status of the board **/
void Board::displayBoard(){
  for(int j = 0; j < INDEX; j++){
    for(int i = 0; i < 20; i++){
      if(board[j][i] == 1 || board[j][i] == 3){
        glColor3f(1.0,.567,0.1922);                 //orange
        shape.drawBoard(getPositionX(i), getPositionY(j));
      } else if (board[j][i] == 2){
        glColor3f(0.54667,0.567,0.1922);         // loam green
        Shapes::drawBoard(getPositionX(i), getPositionY(j));
      }
    }
  }
}

void Board::generateVisual(int l){
  int number;
  level.setLevel(l);

  for(int j = 0; j < level.getIndex(); j++){
    for(int i = 10; i < level.getBlock(); i++){
      number = rand()%3;
      board[j][i] = number;
    }
  }
}

/** JUST TO SHOW THE BOARD MATRIX **/
void Board::displayMatrix(){
  cout << "Board Matrix:" << endl;
  for(int j = 0; j < INDEX; j++){
    for(int i = 0; i < 20; i++){
      cout << "[" << board[j][i] << "] ";
    }
   cout << '\n';
  }
  cout << '\n';
}

void Board::displayMatrix_2(){
  cout << "Visual Matrix:" << endl;
  for(int j = 0; j < 3; j++){
    for(int i = 10; i < 15; i++){
      cout << "[" << board[j][i] << "] ";
    }
   cout << '\n';
  }
  cout << '\n';
}

bool Board::isEmpty(){
    return totalBlocks == 0;
}

/** GETTERS **/
int Board::getTotalBlocks(){
  return totalBlocks;
}

float Board::getPositionY(int index){
 return (1-(index*0.1));
}

float Board::getPositionX(int block){
 return (-1+(block*0.1));
}



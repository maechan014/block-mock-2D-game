#ifndef LEVELS_H
#define LEVELS_H
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Levels{
public:
    Levels();
    ~Levels();

    void setLevel(int);
    int getIndex();
    int getBlock();

private:
  int index;
  int block;
};

#endif // LEVELS_H

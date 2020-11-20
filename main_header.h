#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#include "killer_whale.h"
#include "fish.h"
#include "penguin.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <unistd.h>

using namespace std;

const int MAX = 17;

class sea
{
  private:
    char m_waters[MAX][MAX];
    short m_sea_size;
    void clear();
    void populate(penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
  public:
    sea(penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize, const short grid_size=MAX);
    //Desc: 
    //Pre: 
    //Post: 
    short getSize() const;
    char getWaters(const int i, const int j) const;
    void updateWaters(penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
    friend ostream & operator << (ostream &out, const sea &sea);
};

#endif

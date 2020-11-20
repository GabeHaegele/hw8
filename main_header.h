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
    //Desc: constructor for sea class
    //Pre: 
    //Post: 
    sea(penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize, const short grid_size=MAX);
    //Desc: getSize() gets the size of the sea object
    //Pre: 
    //Post: returns the size of the sea
    short getSize() const;
    //Desc: getWaters() gets the char at a coordinate
    //Pre: (i,j) is a valid coord in the sea
    //Post: returns the char at (i, j)
    char getWaters(const int i, const int j) const;
    //Desc: updateWaters() updates the sea object
    //Pre: all arrays have data and the sizes are the amount of objects in their respective array
    //Post: 
    void updateWaters(penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
    //Desc: operator<<() overloads the << operator
    //Pre: sea is an object with data
    //Post: returns an ostream object to print out
    friend ostream & operator << (ostream &out, const sea &sea);
};

#endif

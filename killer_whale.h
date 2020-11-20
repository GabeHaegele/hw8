#ifndef KILLER_WHALE_H
#define KILLER_WHALE_H

#include "main_header.h"

class fish;
class sea;
class penguin;

class killer_whale
{
  private:
    int m_x;
    int m_y;
    int m_kills;
  public:
    //Desc: killer_whale() is the constructor
    //Pre: 
    //Post: 
    killer_whale();
    //Desc: setXY() sets the xy pos
    //Pre: (x,y) is a valid coord
    //Post: 
    void setXY(const int x, const int y);
    //Desc: getX() gets the x pos
    //Pre: 
    //Post: returns the x position
    int getX() const;
    //Desc: getY() gets the y pos
    //Pre: 
    //Post: returns the y position
    int getY() const;
    //Desc: getKills() gets the amounts of kills the whale has
    //Pre: 
    //Post: returns the whale's kills
    int getKills() const;
    //Desc: mov() moves the object in the sea
    //Pre: sea has data, all arrays have data and the sizes are the amount of objects in their respective array
    //Post: 
    void mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
};
#endif

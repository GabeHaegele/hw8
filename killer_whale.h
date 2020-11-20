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
    killer_whale();
    void move();
    void setXY(const int x, const int y);
    int getX() const;
    int getY() const;
    int getKills() const;
    void mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
};
#endif

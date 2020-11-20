#ifndef FISH_H
#define FISH_H

class killer_whale;
class sea;
class penguin;

class fish
{
  private:
    int m_food;
    int m_x;
    int m_y;
    bool m_alive;
  public:
    fish();
    void move();
    void setXY(const int x, const int y);
    int getX() const;
    int getY() const;
    int getFood() const;
    void setAlive(const bool status);
    bool getStatus() const;
    void spawn(sea &sea);
    void mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
};
#endif

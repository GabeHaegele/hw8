#ifndef PENGUIN_H
#define PENGUIN_H

class killer_whale;
class sea;
class fish;

class penguin
{
  private:
    int m_health;
    int m_x;
    int m_y;
    bool m_alive;
  public:
    penguin();
    void mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
    void setXY(const int x, const int y);
    int getX() const;
    int getY() const;
    int getHealth() const;
    void setHealth(const int newHealth);
    bool getStatus() const;
    void setAlive(const bool status);
    void spawn(sea &sea);
};
#endif

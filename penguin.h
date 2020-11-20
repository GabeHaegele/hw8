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
    //desc: Creates a default penguin
    //pre:
    //post: A default penguin was created
    penguin();
    //desc: Moves a penguin. Movement is determined by multiple factors such as whales and fish in sight.
    //pre: All arrays have data and amounts are the size of data in each array
    //post: 
    void mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
    //desc: Sets the coordinate position of the penguin
    //pre: x and y are on the sea grid
    //post: 
    void setXY(const int x, const int y);
    //desc: Gets member variable x
    //pre: 
    //post: x was returned
    int getX() const;
    //desc: Gets member variable y
    //pre:
    //post: y was returned
    int getY() const;
    //desc: Gets member variable health
    //pre:
    //post: health was returned
    int getHealth() const;
    //desc: Sets member variable health
    //pre:
    //post:
    void setHealth(const int newHealth);
    //desc: Gets member variable status
    //pre:
    //post: status was returned
    bool getStatus() const;
    //desc: Sets the penguin as alive or dead
    //pre:
    //post: The penguin's status was set
    void setAlive(const bool status);
    //desc: Spawns a penguin on the sea grid
    //pre:
    //post:
    void spawn(sea &sea);
};
#endif

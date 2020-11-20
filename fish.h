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
    //desc: Creates a default fish
    //pre:
    //post: a fish was created
    fish();
    //desc: Sets coordinate position of the fish
    //pre: x and y are valid coordinates on the grid unless fish is gonezo
    //post:
    void setXY(const int x, const int y);
    //desc: Gets x postion of fish
    //pre:
    //post: x position was returned
    int getX() const;
    //desc: Gets y postion of fish
    //pre:
    //post: y position was returned
    int getY() const;
    //desc: Gets food amount of the fish
    //pre:
    //post: Food amount was returned
    int getFood() const;
    //desc: Sets fish dead or alive 
    //pre:
    //post: Fish was set to dead or alive
    void setAlive(const bool status);
    //desc: gets status of fish
    //pre:
    //post: status of fish was returned
    bool getStatus() const;
    //desc: Spawns a fish somewhere on the sea grid
    //pre:
    //post:
    void spawn(sea &sea);
    //desc: Moves the fish randomly
    //pre:
    //post:
    void mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize);
};
#endif

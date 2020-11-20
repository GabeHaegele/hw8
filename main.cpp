#include "main_header.h"

const int MAX_FISH=200;
const int MAX_PENGUIN=50;
const int MAX_WHALE=2;
const int NUM_FISH=35;
const int NUM_PENGUIN=20;
const int NUM_WHALE=2;
const int SEA_SIZE=17;
const int FISH_SPAWN_RATE=11;

int main()
{
  srand(10);

  int index;
  int cycle=0;

  cout << "Hello world!" << endl;

  fish fishies[MAX_FISH];

  penguin pengies[MAX_PENGUIN];

  killer_whale whalies[MAX_WHALE];

  sea testWaters(pengies, NUM_PENGUIN, fishies, NUM_FISH, whalies, NUM_WHALE, SEA_SIZE);

  cout<<testWaters;
  cout<<"\n\n\n";

  bool atLeastOneAlive = true;
  bool spawn=false;
  while(atLeastOneAlive && cycle<10000)
  {
    cout<<"Cycle: "<<cycle<<endl;
    for(int i=0; i<NUM_FISH; i++)
    {
      fishies[i].mov(testWaters, pengies, NUM_PENGUIN, fishies, NUM_FISH, whalies, NUM_WHALE);
    }
    //cout<<"fishie on me"<<endl;
    for(int i=0; i<NUM_PENGUIN; i++)
    {
      pengies[i].mov(testWaters, pengies, NUM_PENGUIN, fishies, NUM_FISH, whalies, NUM_WHALE);
    }

    for(int i=0; i<NUM_PENGUIN; i++)
    {
      if(pengies[i].getHealth()>70)
      {
        pengies[i].setHealth(70);
        while(index<MAX_PENGUIN && !spawn)
        {
          if(!pengies[index].getStatus())
          {
            spawn=true;
            pengies[index].spawn(testWaters);
          }
          index++;
        }
        spawn=false;
        index=0;
      }
    }

    for(int i=0; i<FISH_SPAWN_RATE; i++)
    {
      spawn=false;
      while(index<MAX_FISH && !spawn)
      {
        if(!fishies[index].getStatus())
        {
          spawn=true;
          fishies[index].spawn(testWaters);
        }
        index++;
      }
      index=0;
    }

    //cout<<"Pengood"<<endl;
    for(int i=0; i<NUM_WHALE; i++)
    {
      whalies[i].mov(testWaters, pengies, NUM_PENGUIN, fishies, NUM_FISH, whalies, NUM_WHALE);
    }
    //cout<<"whale then"<<endl;
    index=0;
    atLeastOneAlive=false;
    while(index<NUM_PENGUIN && !atLeastOneAlive)
    {
      if(pengies[index].getStatus())
      {
        if(pengies[index].getX()>testWaters.getSize() || pengies[index].getY()>testWaters.getSize())
        {
          pengies[index].setAlive(false);
        } else
        {
          atLeastOneAlive=true;
          //cout<<"I'm alive! ("<<pengies[index].getX()<<", "<<pengies[index].getY()<<")."<<endl;
        }
      }
      //cout<<"Penguin "<<index<<" is "<<pengies[index].getStatus()<<" at ("<<pengies[index].getX()<<", "<<pengies[index].getY()<<")."<<endl;
      index++;
    }
    cycle++;
    usleep(200000);
    cout<<testWaters<<endl;
  }
  if(!atLeastOneAlive)
  {
    cout<<"all ded"<<endl;
  }

  for(int i=0; i<NUM_WHALE; i++)
  {
    cout<<"Whale "<<i<<" got "<<whalies[i].getKills()<<" kills."<<endl;
  }

  cout<<testWaters;

  return 0;
}

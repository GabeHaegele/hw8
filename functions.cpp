#include "main_header.h"

void sea::clear()
{
  for(int i=0; i<m_sea_size; i++)
  {
    for(int j=0; j<m_sea_size; j++)
    {
      m_waters[i][j]='~';
    }
  }
  return;
}

void sea::populate(penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize)
{
  int fPlaced=0;
  int pPlaced=0;
  int wPlaced=0;
  bool placed=false;
  while(fPlaced<fSize || pPlaced<pSize || wPlaced<wSize)
  {
    for(int i=0; i<m_sea_size; i++)
    {
      for(int j=0; j<m_sea_size; j++)
      {
        if(m_waters[i][j]=='~')
        {
          placed=false;
          if(fPlaced<fSize)
          {
            if((rand()%100)<10)
            {
              m_waters[i][j]='F';
              fArr[fPlaced].setXY(i,j);
              fArr[fPlaced].setAlive(true);
              fPlaced++;
              placed=true;
            }
          }
          if(pPlaced<pSize && !placed)
          {
            if((rand()%100)<10)
            {
              m_waters[i][j]='P';
              pArr[pPlaced].setXY(i,j);
              pArr[pPlaced].setAlive(true);
              pPlaced++;
              placed=true;
            }
          }
          if(wPlaced<wSize && !placed)
          {
            if((rand()%100)<2)
            {
              m_waters[i][j]='K';
              wArr[wPlaced].setXY(i,j);
              wPlaced++;
            }
          }
        }
      }
    }
  }
}

sea::sea(penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize, const short grid_size)
{
  m_sea_size=grid_size;
  clear();
  populate(pArr, pSize, fArr, fSize, wArr, wSize);
}

ostream & operator << (ostream &out, const sea &sea)
{
  out<<left<<"   ";
  for(int i=0; i<sea.m_sea_size; i++)
  {
    out<<setw(2)<<i<<" ";//Top row of numbers
  }
  out<<endl;

  for(int i=0; i<sea.m_sea_size; i++)
  {
    out<<setw(2)<<i<<" ";//Left column of numbers
    for(int j=0; j<sea.m_sea_size; j++)
    {
      out<<sea.m_waters[i][j]<<"  ";
    }
    out<<endl;
  }
  return out;
}

short sea::getSize() const
{
  return m_sea_size;
}

char sea::getWaters(const int i, const int j) const
{
  return m_waters[i][j];
}

void sea::updateWaters(penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize)
{
  clear();
  for(int i=0; i<fSize; i++)
  {
    if(fArr[i].getX()!=-1)
    {
      m_waters[fArr[i].getX()][fArr[i].getY()]='F';
      /**
      if(m_waters[fArr[i].getX()][fArr[i].getY()]=='~')
      {
        m_waters[fArr[i].getX()][fArr[i].getY()]='F';
      } else if(m_waters[fArr[i].getX()][fArr[i].getY()]=='K' || m_waters[fArr[i].getX()][fArr[i].getY()]=='P')
      {
        fArr[i].setAlive(false);
        fArr[i].setXY(-1, -1);
      }
      **/
    }
  }
  for(int i=0; i<pSize; i++)
  {
    if(pArr[i].getX()!=-1)
    {
      m_waters[pArr[i].getX()][pArr[i].getY()]='P';
    }
  }
  for(int i=0; i<wSize; i++)
  {
    if(wArr[i].getX()!=-1)
    {
      m_waters[wArr[i].getX()][wArr[i].getY()]='K';
    }
  }
}

//fish

fish::fish()
{
  m_food=(rand()%10)+1;
  m_x=-1;
  m_y=-1;
  m_alive=false;
}

int fish::getFood() const
{
  return m_food;
}

void fish::setAlive(const bool status)
{
  m_alive=status;
}

void fish::setXY(const int x, const int y)
{
  m_x=x;
  m_y=y;
}

int fish::getX() const
{
  return m_x;
}

int fish::getY() const
{
  return m_y;
}

void fish::mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize)
{
  int randomMove=rand()%8+1;
  switch(randomMove)
  {
    case 1:
      if(sea.getWaters(m_x+1, m_y)!='~')
      {
        randomMove=2;
      } else
      {
        m_x+=1;
      }
      break;
    case 2:
      if(sea.getWaters(m_x+1, m_y+1)!='~')
      {
        randomMove=3;
      } else
      {
        m_x+=1;
        m_y+=1;
      }
      break;
    case 3:
      if(sea.getWaters(m_x, m_y+1)!='~')
      {
        randomMove=4;
      } else
      {
        m_y+=1;
      }
      break;
    case 4:
      if(sea.getWaters(m_x-1, m_y+1)!='~')
      {
        randomMove=5;
      } else
      {
        m_y+=1;
        m_x-=1;
      }
      break;
    case 5:
      if(sea.getWaters(m_x-1, m_y)!='~')
      {
        randomMove=6;
      } else
      {
        m_x-=1;
      }
      break;
    case 6:
      if(sea.getWaters(m_x-1, m_y-1)!='~')
      {
        randomMove=7;
      } else
      {
        m_x-=1;
        m_y-=1;
      }
      break;
    case 7:
      if(sea.getWaters(m_x, m_y-1)!='~')
      {
        randomMove=8;
      } else
      {
        m_y-=1;
      }
      break;
    case 8:
      if(sea.getWaters(m_x+1, m_y-1)!='~')
      {
      } else
      {
        m_x+=1;
        m_y-=1;
      }
      break;
  }
  switch(randomMove)
  {
    case 8:
      if(sea.getWaters(m_x+1, m_y)!='~')
      {
        randomMove=7;
      } else
      {
        m_x+=1;
      }
      break;
    case 7:
      if(sea.getWaters(m_x+1, m_y+1)!='~')
      {
        randomMove=6;
      } else
      {
        m_x+=1;
        m_y+=1;
      }
      break;
    case 6:
      if(sea.getWaters(m_x, m_y+1)!='~')
      {
        randomMove=5;
      } else
      {
        m_y+=1;
      }
      break;
    case 5:
      if(sea.getWaters(m_x-1, m_y+1)!='~')
      {
        randomMove=4;
      } else
      {
        m_y+=1;
        m_x-=1;
      }
      break;
    case 4:
      if(sea.getWaters(m_x-1, m_y)!='~')
      {
        randomMove=3;
      } else
      {
        m_x-=1;
      }
      break;
    case 3:
      if(sea.getWaters(m_x-1, m_y-1)!='~')
      {
        randomMove=2;
      } else
      {
        m_x-=1;
        m_y-=1;
      }
      break;
    case 2:
      if(sea.getWaters(m_x, m_y-1)!='~')
      {
        randomMove=1;
      } else
      {
        m_y-=1;
      }
      break;
    case 1:
      if(sea.getWaters(m_x+1, m_y-1)!='~')
      {
      } else
      {
        m_x+=1;
        m_y-=1;
      }
      break;
  }
}

void fish::spawn(sea &sea)
{
  int randomX=rand()%sea.getSize();
  int randomY=rand()%sea.getSize();
  bool flip = false;
  while(sea.getWaters(randomX, randomY)!='~')
  {
    if(flip)
    {
      if(randomX==sea.getSize())
      {
        randomX=0;
      } else
      {
        randomX++;
      }
    } else
    {
      if(randomY==sea.getSize())
      {
        randomY=0;
      } else
      {
        randomY++;
      }
    }
  }
  m_alive=true;
  setXY(randomX,randomY);
  //cout<<"\nNew fish spawned at ("<<randomX<<", "<<randomY<<")."<<endl;
}

bool fish::getStatus() const
{
  return m_alive;
}

//penguin

penguin::penguin()
{
  m_health=(rand()%21)+60;
  m_x=-1;
  m_y=-1;
  m_alive=false;
}

void penguin::mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize)
{
  int optimalFishX=1000;
  int optimalFishY=1000;
  int scariestWhaleX=1000;
  int scariestWhaleY=1000;
  int randomMove=0;
  int moves=0;
  if(!(m_x==-1 || m_y==-1) && m_alive && m_health>0)
  {
    bool ate = false;
    if(m_health>80)
    {
      moves=5;
      //cout<<"me move 5"<<endl;
    } else if(m_health>60)
    {
      moves=4;
      //cout<<"me move 4"<<endl;
    } else if(m_health>40)
    {
      moves=3;
      //cout<<"me move 3"<<endl;
    } else if(m_health>20)
    {
      moves=2;
      //cout<<"me move 2"<<endl;
    } else if(m_health>0)
    {
      moves=1;
      //cout<<"me move 1"<<endl;
    }
    while(moves>0 && ate==false && m_alive && m_health>0)
    {
      for(int i=0; i<fSize; i++)
      {
        if(sqrt((m_x-fArr[i].getX())*(m_x-fArr[i].getX())+(m_y-fArr[i].getY())*(m_y-fArr[i].getY()))<sqrt((m_x-optimalFishX)*(m_x-optimalFishX)+(m_y-optimalFishY)*(m_y-optimalFishY)) && sqrt((m_x-fArr[i].getX())*(m_x-fArr[i].getX())+(m_y-fArr[i].getY())*(m_y-fArr[i].getY()))<8.0)
        {
          optimalFishX=fArr[i].getX();
          optimalFishY=fArr[i].getY();
        }
      }

      for(int i=0; i<wSize; i++)
      {
        if(sqrt((m_x-wArr[i].getX())*(m_x-wArr[i].getX())+(m_y-wArr[i].getY())*(m_y-wArr[i].getY()))<sqrt((m_x-scariestWhaleX)*(m_x-scariestWhaleX)+(m_y-scariestWhaleY)*(m_y-scariestWhaleY)) && sqrt((m_x-wArr[i].getX())*(m_x-wArr[i].getX())+(m_y-wArr[i].getY())*(m_y-wArr[i].getY()))<8.0)
        {
          scariestWhaleX=wArr[i].getX();
          scariestWhaleY=wArr[i].getY();
        }
      }

      //cout<<"Im comin for u fishie aT ("<<optimalFishX<<", "<<optimalFishY<<")."<<endl;
      if(optimalFishX==1000 && scariestWhaleX==1000)
      {
        randomMove=rand()%8+1;
        //cout<<"Fugit, random for dinner #"<<randomMove<<"."<<endl;
        switch(randomMove)
        {
          case 1:
            if(sea.getWaters(m_x+1, m_y)=='~')
            {
              m_x+=1;
            } else
            {
              randomMove++;
            }
            break;
          case 2:
            if(sea.getWaters(m_x+1, m_y+1)=='~')
            {
              m_x+=1;
              m_y+=1;
            } else
            {
              randomMove++;
            }
            break;
          case 3:
            if(sea.getWaters(m_x, m_y+1)=='~')
            {
              m_y+=1;
            } else
            {
              randomMove++;
            }
            break;
          case 4:
            if(sea.getWaters(m_x-1, m_y+1)=='~')
            {
              m_y+=1;
              m_x-=1;
            } else
            {
              randomMove++;
            }
            break;
          case 5:
            if(sea.getWaters(m_x-1, m_y)=='~')
            {
              m_x-=1;
            } else
            {
              randomMove++;
            }
            break;
          case 6:
            if(sea.getWaters(m_x-1, m_y-1)=='~')
            {
              m_x-=1;
              m_y-=1;
            } else
            {
              randomMove++;
            }
            break;
          case 7:
            if(sea.getWaters(m_x, m_y-1)=='~')
            {
              m_y-=1;
            } else
            {
              randomMove++;
            }
            break;
          case 8:
            if(sea.getWaters(m_x+1, m_y-1)=='~')
            {
              m_x+=1;
              m_y-=1;
            } else
            {
              randomMove++;
            }
            break;
        }
        switch(randomMove)
        {
          case 8:
            if(sea.getWaters(m_x+1, m_y)=='~')
            {
              m_x+=1;
            } else
            {
              randomMove--;
            }
            break;
          case 7:
            if(sea.getWaters(m_x+1, m_y+1)=='~')
            {
              m_x+=1;
              m_y+=1;
            } else
            {
              randomMove--;
            }
            break;
          case 6:
            if(sea.getWaters(m_x, m_y+1)=='~')
            {
              m_y+=1;
            } else
            {
              randomMove--;
            }
            break;
          case 5:
            if(sea.getWaters(m_x-1, m_y+1)=='~')
            {
              m_y+=1;
              m_x-=1;
            } else
            {
              randomMove--;
            }
            break;
          case 4:
            if(sea.getWaters(m_x-1, m_y)=='~')
            {
              m_x-=1;
            } else
            {
              randomMove--;
            }
            break;
          case 3:
            if(sea.getWaters(m_x-1, m_y-1)=='~')
            {
              m_x-=1;
              m_y-=1;
            } else
            {
              randomMove--;
            }
            break;
          case 2:
            if(sea.getWaters(m_x, m_y-1)=='~')
            {
              m_y-=1;
            } else
            {
              randomMove--;
            }
            break;
          case 1:
            if(sea.getWaters(m_x+1, m_y-1)=='~')
            {
              m_x+=1;
              m_y-=1;
            } else
            {
              randomMove--;
            }
            break;
        }
      } else
      {
        if(optimalFishX!=1000)
        {
          if(optimalFishX>m_x && m_x<sea.getSize() && (sea.getWaters(m_x+1, m_y)=='~' || sea.getWaters(m_x+1, m_y)=='F'))
          {
            //cout<<"i move right--hungry"<<endl;
            m_x+=1;
          } else if(optimalFishX!=m_x && m_x>0 && (sea.getWaters(m_x-1, m_y)=='~' || sea.getWaters(m_x-1, m_y)=='F'))
          {
            //cout<<"i move left--hungry"<<endl;
            m_x-=1;
          }

          if(optimalFishY>m_y && m_y<sea.getSize() && (sea.getWaters(m_x, m_y+1)=='~' || sea.getWaters(m_x, m_y+1)=='F'))
          {
            //cout<<"i move right--hungry"<<endl;
            m_y+=1;
          } else if(optimalFishY!=m_y && m_y>0 && (sea.getWaters(m_x, m_y-1)=='~' || sea.getWaters(m_x, m_y-1)=='F'))
          {
            //cout<<"i move down--hungry"<<endl;
            m_y-=1;
          }
        } else if(scariestWhaleX!=1000)
        {
          if(scariestWhaleX>m_x && m_x>0 && (sea.getWaters(m_x-1, m_y)=='~' || sea.getWaters(m_x-1, m_y)=='F'))
          {
            //cout<<"i move left--scary"<<endl;
            m_x-=1;
          } else if(scariestWhaleX!=m_x && m_x<sea.getSize() && (sea.getWaters(m_x+1, m_y)=='~' || sea.getWaters(m_x+1, m_y)=='F'))
          {
            //cout<<"i move right--scary"<<endl;
            m_x+=1;
          }

          if(scariestWhaleY>m_y && m_y>0 && (sea.getWaters(m_x, m_y-1)=='~' || sea.getWaters(m_x, m_y-1)=='F'))
          {
            //<<"i move down--scary"<<endl;
            m_y-=1;
          } else if(scariestWhaleY!=m_y && m_y<sea.getSize() && (sea.getWaters(m_x, m_y+1)=='~' || sea.getWaters(m_x, m_y+1)=='F'))
          {
            //cout<<"i move up--scary"<<endl;
            m_y+=1;
          }
        }
      }
      moves--;
      m_health--;
      for(int i=0; i<fSize; i++)
      {
        if(fArr[i].getX()==m_x && fArr[i].getY()==m_y)
        {
          ate=true;
          fArr[i].setAlive(false);
          m_health+=fArr[i].getFood();
          //cout<<"\nMM yubmy fish food: "<<fArr[i].getFood()<<" health: "<<m_health<<endl;
        }
      }
      //for(int i=0; i<wSize; i++)
      //{
      //  if(wArr[i].getX()==m_x && wArr[i].getY()==m_y)
      //  {
      //    m_alive=false;
       //   m_x=-1;
       //   m_y=-1;
       //   //cout<<"i ded"<<endl;
      //  }
      //}
      sea.updateWaters(pArr, pSize, fArr, fSize, wArr, wSize);
    }

  }
}

void penguin::spawn(sea &sea)
{
  int randomX=rand()%sea.getSize();
  int randomY=rand()%sea.getSize();
  bool flip = false;
  while(sea.getWaters(randomX, randomY)!='~')
  {
    if(flip)
    {
      if(randomX==sea.getSize())
      {
        randomX=0;
      } else
      {
        randomX++;
      }
    } else
    {
      if(randomY==sea.getSize())
      {
        randomY=0;
      } else
      {
        randomY++;
      }
    }
  }
  m_alive=true;
  setXY(randomX,randomY);
  //cout<<"\nNew penguin spawned at ("<<randomX<<", "<<randomY<<")."<<endl;
}

int penguin::getHealth() const
{
  return m_health;
}

void penguin::setHealth(const int newHealth)
{
  m_health=newHealth;
}

void penguin::setAlive(const bool status)
{
  m_alive=status;
}

void penguin::setXY(const int x, const int y)
{
  m_x=x;
  m_y=y;
}

int penguin::getX() const
{
  return m_x;
}

int penguin::getY() const
{
  return m_y;
}

bool penguin::getStatus() const
{
  return m_alive;
}

//whale

killer_whale::killer_whale()
{
  m_x=-1;
  m_y=-1;
  m_kills=0;
}

void killer_whale::setXY(const int x, const int y)
{
  m_x=x;
  m_y=y;
}

int killer_whale::getX() const
{
  return m_x;
}

int killer_whale::getY() const
{
  return m_y;
}

int killer_whale::getKills() const
{
  return m_kills;
}

void killer_whale::mov(sea &sea, penguin pArr[], const int pSize, fish fArr[], const int fSize, killer_whale wArr[], const int wSize)
{
  int optimalX=1000;
  int optimalY=1000;
  int moves=3;
  bool ate=false;
  while(!ate && moves>0)
  {
    optimalX=1000;
    optimalY=1000;

    for(int i=0; i<pSize; i++)
    {
      if(sqrt((m_x-pArr[i].getX())*(m_x-pArr[i].getX())+(m_y-pArr[i].getY())*(m_y-pArr[i].getY()))<sqrt((m_x-optimalX)*(m_x-optimalX)+(m_y-optimalY)*(m_y-optimalY)))
      {
        if(pArr[i].getStatus())
        {
          optimalX=pArr[i].getX();
          optimalY=pArr[i].getY();
        }
      }
    }
    if(optimalX>sea.getSize() || optimalX<0)
    {
      optimalX=sea.getSize()/2;
    }
    if(optimalY>sea.getSize() || optimalY<0)
    {
      optimalY=sea.getSize()/2;
    }

    //cout<<"WHALE: tracking ("<<optimalX<<", "<<optimalY<<")"<<endl;

    if(optimalX>m_x && sea.getWaters(m_x+1, m_y)!='K')
    {
      m_x+=1;
    } else if(optimalX!=m_x && sea.getWaters(m_x-1, m_y)!='K')
    {
      m_x-=1;
    }
    if(optimalY>m_y && sea.getWaters(m_x, m_y+1)!='K')
    {
      m_y+=1;
    } else if(optimalY!=m_y && sea.getWaters(m_x, m_y-1)!='K')
    {
      m_y-=1;
    }
    for(int i=0; i<pSize; i++)
    {
      if(m_x==pArr[i].getX() && m_y==pArr[i].getY())
      {
        ate=true;
        pArr[i].setAlive(false);
        pArr[i].setXY(-1,-1);
        m_kills++;
        //cout<<"GOTCHA BIH"<<endl;
      }
    }
    for(int i=0; i<fSize; i++)
    {
      if(m_x==fArr[i].getX() && m_y==fArr[i].getY())
      {
        fArr[i].setAlive(false);
        fArr[i].setXY(-1,-1);
      }
    }
    moves--;
  }
  sea.updateWaters(pArr, pSize, fArr, fSize, wArr, wSize);
}

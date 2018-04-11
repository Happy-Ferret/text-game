#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <iostream>
#include <deque>
#include <string>
using namespace std;
namespace CHAR
{
  int level = 1;
  int xp = 0;
  int maxhp = 100;
  int hp = maxhp;
  string name = "BOB";
  void leveling ()
  {
    if (xp >= 100)
      level++;
    maxhp = maxhp + 7;
    hp = maxhp;
    xp = 0;
  }
}
#endif

#ifndef SAVE_H_
#define SAVE_H_
#include <fstream>
#include <sstream>
#include "character.h"
using namespace std;
void
load ()
{
  string dummy;
  ifstream load ("stats.save");
  getline(load, CHAR::name);
  load>>CHAR::xp;
  getline(load, dummy);
  load>>CHAR::level;
  getline(load, dummy);
  load>>CHAR::maxhp;
  getline(load, dummy);
  load>>CHAR::hp;
  //getline(load, dummy);
  //load>>CHAR::level;
}

void
save ()
{
  ofstream save ("stats.save");
  save << CHAR::name<<endl;
  save << CHAR::xp<<endl;
  save << CHAR::level<<endl;
  save << CHAR::maxhp<<endl;
  save << CHAR::hp<<endl;
}
#endif

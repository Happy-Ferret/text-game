#ifndef SAVE_H_
#define SAVE_H_
#include <fstream>
#include "character.h"
using namespace std;
void
load ()
{
  ifstream name ("name.save");
  name >> CHAR::name;
  ifstream xp ("xp.save");
  xp >> CHAR::xp;
  ifstream maxhp ("maxhp.save");
  maxhp >> CHAR::maxhp;
  ifstream hp ("hp.save");
  hp >> CHAR::name;
  ifstream level ("level.save");
  hp >> CHAR::level;
}

void
save ()
{
  ofstream name ("name.save");
  name << CHAR::name;
  ofstream xp ("xp.save");
  xp << CHAR::xp;
  ofstream maxhp ("maxhp.save");
  maxhp << CHAR::maxhp;
  ofstream hp ("hp.save");
  hp << CHAR::hp;
  ifstream level ("level.save");
  hp << CHAR::level;
}
#endif

#ifndef PRINTALL_H_
#define PRINTALL_H_
void
baseitems ()
{
  item::additem ("fist", 1);
  item::additem ("axe", 1);
  item::additem ("simple-helmet", 2);
  item::additem ("simple-armor", 2);
}

int
printall ()
{
  for (int i = 1; i <= 6; i++)
    item::printitems (i);
  save ();
  load ();
  CHAR::xp = 101;
  CHAR::leveling ();
  std::cout << CHAR::name << std::endl;
  std::cout << CHAR::xp << std::endl;
  std::cout << CHAR::level << std::endl;
  std::cout << CHAR::hp << std::endl;
  std::cout << CHAR::maxhp << std::endl;
  return 0;
}
#endif

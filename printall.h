#ifndef PRINTALL_H_
#define PRINTALL_H_
void
baseitems ()
{
  item::additem ("fist", 1,5,"What do you think it is?\n Its just a fist\n");
  item::additem ("axe", 1,12,"Use it to chop down trees, or people's heads, your choice\n");
  item::additem ("simple helmet", 2,3,"Put it on your head, it'll work until you get something else\n");
  item::additem ("simple armor", 2,5,"Simple armor that prevents someone from stabbing you with a twig\n");
}

int
printall ()
{
  item::printitems (6);
  save ();
  load ();
  CHAR::leveling ();
  std::cout << CHAR::name << std::endl;
  std::cout << CHAR::xp << std::endl;
  std::cout << CHAR::level << std::endl;
  std::cout << CHAR::hp << std::endl;
  std::cout << CHAR::maxhp << std::endl;
  return 0;
}
#endif

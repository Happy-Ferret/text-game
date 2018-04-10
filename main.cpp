#include <iostream>
#include <deque>
#include "inventory.h"
int main()
{
    /*
    1=weapon
    2=armor
    3=magic
    4=quest
    5=other
    6=all
    */
    item::additem("fist",1);
    item::additem("axe",1);
    item::additem("simple-helmet",2);
    item::additem("simple-armor",2);
    for(int i=1;i<=6;i++)
    item::printitems(i);
    return 0;
}
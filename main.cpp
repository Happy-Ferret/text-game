#include <iostream>
#include <deque>
#include <string>
#include "save.h"
#include "inventory.h"
#include "character.h"
#include "printall.h"
using namespace item;
void SearchItems()
{
  bool bob=true;
    std::string name;
    while(bob)
    {
    std::cout << "Type in the name of an item to view its stats or say \"exit\"" << std::endl;
  std::getline (std::cin,name);
  if(!name.compare("exit"))
  {
    bob=false;
  }
  for(int i=0;i<weapon.inventory.size();i++)
  {
      if (name.compare(weapon.inventory[i])== 0)
      {
        std::cout<<weapon.inventory[i]<<std::endl;
        std::cout<<"Damage = "<<weapon.dam[i]<<std::endl;
        std::cout<<weapon.info[i]<<std::endl;
         bob=false;
      }
  }
  for(int i=0;i<armor.inventory.size();i++)
  {
      if (name.compare(armor.inventory[i])== 0)
      {
        std::cout<<armor.inventory[i]<<std::endl;
        std::cout<<"Protection = "<<armor.dam[i]<<std::endl;
        std::cout<<armor.info[i]<<std::endl; 
         bob=false;
      }
  }
  for(int i=0;i<magic.inventory.size();i++)
  {
      if (name.compare(magic.inventory[i])== 0)
      {
        std::cout<<magic.inventory[i]<<std::endl;
        //std::cout<<"Damage="<<item::weapon.dam[i]<<std::endl;
        std::cout<<magic.info[i]<<std::endl;
         bob=false;
      }
    //std::cout << "\nThats not the name of an item!!\n\n" << std::endl;
    
  }
  
      
    }
}
int
main ()
{
  baseitems();
  item::additem("wand",3,0,"Use it to cast spells or something like that.\n");
  save();
  load();
  printall();
 SearchItems();
 save();
  return 0;
}


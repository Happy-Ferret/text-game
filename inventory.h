#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <iostream>
#include <deque>
#include <string>
namespace item 
{
    struct it
    {
    std::deque<std::string>inventory;
    }magic,weapon,armor,quest,other;
    std::deque<std::string>items;
    void additem(std::string newitem,int type)
    {
        
        items.push_back(newitem);
        if(type==1)
        weapon.inventory.push_back(newitem);
        else if(type==2)
        armor.inventory.push_back(newitem);
        else if(type==3)
        magic.inventory.push_back(newitem);
        else if(type==4)
        other.inventory.push_back(newitem);
    }
    void printitems(int type)
    {
        if(type==1)
        {
        std::cout << "Your weapons :" << std::endl;
        for(int i=0;i<weapon.inventory.size();i++)
        std::cout << weapon.inventory[i] <<" ";
        std::cout << std::endl;
        }
        else if(type==2)
        {
        std::cout << "Your armor pieces :" << std::endl;
        for(int i=0;i<armor.inventory.size();i++)
        std::cout << armor.inventory[i]<<" ";
        std::cout  << std::endl;
        }
        else if(type==3)
        {
        std::cout << "Your magic items :" << std::endl;
        for(int i=0;i<magic.inventory.size();i++)
        std::cout << magic.inventory[i]<<" ";
        std::cout  << std::endl;
        }
        else if(type==4){
        std::cout << "Your quest items :" << std::endl;
        for(int i=0;i<quest.inventory.size();i++)
        std::cout << quest.inventory[i]<<" ";
        std::cout  << std::endl;
        }
        else if(type==5)
        {
        std::cout << "Your other items:" << std::endl;
        for(int i=0;i<other.inventory.size();i++)
        std::cout << other.inventory[i] << std::endl;
        }
        else if(type==6)
        {
        std::cout << "Your items:" << std::endl;
        for(int i=0;i<items.size();i++)
        std::cout << items[i]<<"; ";
        }
    }
    
}
#endif
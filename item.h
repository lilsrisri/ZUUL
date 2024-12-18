//
// Created by Sriram Subramanian on 11/13/24.
//

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

class Item{
public:
    Item(const char* name_arg, Room* location_arg); //for items, it needs a name and a location
    const char* getName(); //makes the name public
    Room* getLocation(); //gets the location of the item
    void setLocation(Room* room);
private:
    const char* name;
    Room* location;

};

#endif //ITEM_H

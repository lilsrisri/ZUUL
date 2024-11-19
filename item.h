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
    Item(const char* name_arg, Room* location_arg);
    const char* getName();
    Room* getLocation();
private:
    const char* name;
    Room* location;

};

#endif //ITEM_H

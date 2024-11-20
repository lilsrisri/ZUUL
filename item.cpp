//
// Created by Sriram Subramanian on 11/18/24.
//


#include "item.h"

Item::Item(const char* name_arg, Room* location_arg) {
    name = name_arg;
    location = location_arg;
}

const char* Item::getName() {
    return name;
}
Room* Item::getLocation() {
    return location;
}

void Item::setLocation(Room* room) {
    location = room;
}
//
// Created by Sriram Subramanian on 11/17/24.
//

#include "room.h"


using namespace std;

Room::Room(const char* name_arg) {
    name = name_arg;

}
const char* Room::getName(){
    return name;
}
void Room::setNorth(Room* room) {
    north = room;
}
void Room::setEast(Room* room) {
    east = room;
}
void Room::setSouth(Room* room) {
    south = room;
}
void Room::setWest(Room* room) {
    west = room;
}



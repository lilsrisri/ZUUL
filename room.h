//
// Created by Sriram Subramanian on 11/13/24.
//

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


class Room {
public:
    Room(const char* name_arg);
    void setNorth(Room* room); //sets each direction
    void setEast(Room* room);
    void setSouth(Room* room);
    void setWest(Room* room);
    const char* getName(); //making the name for public use
    Room* getNorth();  //making the directions for public use
    Room* getEast();
    Room* getSouth();
    Room* getWest();
private:
    const char* name;
    // vector<int> exits;
    //vector<Item*> items;
    Room* north = nullptr;
    Room* east = nullptr;
    Room* south = nullptr;
    Room* west = nullptr;
};

#endif //ROOM_H



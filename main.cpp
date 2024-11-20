#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
#include <vector>



using namespace std;

void initializeGame(vector<Room*>& rooms, vector<Item*>& items) { //Function to initialize rooms
    //Creating all the rooms
    Room* parkingLot =  new Room("Parking Lot"); rooms.push_back(parkingLot);
    Room* mainHall = new Room("Main Hall"); rooms.push_back(mainHall);
    Room* fishBowl = new Room("Fish Bowl"); rooms.push_back(fishBowl);
    Room* historyClass = new Room("History Class"); rooms.push_back(historyClass);
    Room* cafeteria = new Room("Cafeteria"); rooms.push_back(cafeteria);
    Room* englishClass = new Room("English Class"); rooms.push_back(englishClass);
    Room* spanishClass = new Room("Spanish Class"); rooms.push_back(spanishClass);
    Room* japaneseClass = new Room("Japanese Class"); rooms.push_back(japaneseClass);
    Room* frenchClass = new Room("French Class"); rooms.push_back(frenchClass);
    Room* computerLab = new Room("Computer Lab"); rooms.push_back(computerLab);
    Room* mathClass = new Room("Math Class"); rooms.push_back(mathClass);
    Room* scienceClass = new Room("Science Class"); rooms.push_back(scienceClass);
    Room* healthClass = new Room("Health Class"); rooms.push_back(healthClass);
    Room* lockerRoom = new Room("Locker Room"); rooms.push_back(lockerRoom);
    Room* gym = new Room("Gym"); rooms.push_back(gym);


    parkingLot->setNorth(mainHall); //North of the parking lot is mainhall
    mainHall->setSouth(parkingLot); //South of mainhall is the parking lot
    mainHall->setNorth(fishBowl); //North of mainhall is fishbowl
    fishBowl->setSouth(mainHall); //South of fishbowl is mainhall
    fishBowl->setWest(historyClass); //West of fishbowl is history class
    historyClass->setEast(fishBowl); //East of history class is fishbowl
    historyClass->setWest(cafeteria); //West of history class is cafeteria
    historyClass->setNorth(englishClass); //North of history class is english class
    cafeteria->setEast(historyClass); //east of cafeteria is history class
    cafeteria->setNorth(spanishClass); //north of cafeteria is spanish class
    spanishClass->setSouth(cafeteria); //south of spanish class is cafeteria
    spanishClass->setEast(englishClass); //east of spanish class is english class
    spanishClass->setNorth(frenchClass); //north of spanish class is French class
    englishClass->setSouth(historyClass); //south of english class is history class
    englishClass->setWest(spanishClass); //west of english class is spanish class
    englishClass->setNorth(japaneseClass); //north of english class is japanese class
    japaneseClass->setSouth(englishClass); //south of japanese class is english class
    japaneseClass->setWest(frenchClass); //west of japanese class is french class
    japaneseClass->setNorth(mathClass); //north of japanese class is math class
    frenchClass->setSouth(spanishClass); //south of french class is spanish class
    frenchClass->setEast(japaneseClass); //east of french class is japanese class
    frenchClass->setNorth(computerLab); //north of french class is the computer lab
    computerLab->setSouth(frenchClass); //south of computer lab is french class
    computerLab->setEast(mathClass); //east of computer lab is math class
    mathClass->setWest(computerLab); //West of math class is computer lab
    mathClass->setSouth(japaneseClass); //south of math class is japanese class
    mathClass->setEast(scienceClass); //east of math class is science class
    scienceClass->setWest(mathClass); //west of science class is math class
    scienceClass->setEast(healthClass); //east of science class is health class
    healthClass->setWest(scienceClass); //west of health class is science class
    healthClass->setSouth(lockerRoom); //south of health class is locker room
    lockerRoom->setNorth(healthClass); //north of locker room is health class
    lockerRoom->setSouth(gym); //south of locker room is the gym
    gym->setNorth(lockerRoom); //north of gym is locker room


    Item* car = new Item("Car", parkingLot); items.push_back(car); //Car is in parking lot
    Item* noteBook = new Item("NoteBook", fishBowl); items.push_back(noteBook); //Notebook is in the fishbowl
    Item* milk = new Item("Milk", cafeteria); items.push_back(milk); //Milk is in cafeteria
    Item* key = new Item("Key", cafeteria); items.push_back(key); //Key is in cafeteria
    Item* dictionary = new Item("Dictionary", frenchClass); items.push_back(dictionary); //Dictionary is in french class
    Item* sriram = new Item("Sriram", computerLab); items.push_back(sriram); //Sriram is in computerlab
    Item* goggles = new Item("Goggles", scienceClass); items.push_back(goggles); //Goggles is in science class
    Item* bandAid = new Item("BandAid", healthClass); items.push_back(bandAid); //Notebook is in fishbowl

}

Room* play(Room* currentRoom, vector<Room*>& allRooms, vector<Item*>& allItems);
Item* findItem(vector<Item*>& allItems, const char* name, Room* currentRoom);

void finishGame(vector<Room*>& allRooms, vector<Item*>& allItems) {
    for (int i = 0; i < allRooms.size(); ++i) {
        delete allRooms[i];
    }
    for (int i = 0; i < allItems.size(); ++i) {
        delete allItems[i];
    }
}

int main() {
    vector<Room*> allRooms;
    vector<Item*> allItems;
    initializeGame(allRooms, allItems);
    Room* currentRoom = allRooms[1]; //Rooms of 1 is mainhall
    /*for (int i = 0; i < allRooms.size(); ++i) {
        cout << allRooms[i]->getName() << endl;
    }
    for (int i = 0; i < allItems.size(); ++i) {
        cout << "Item '" << allItems[i]->getName() << "' is in room '" << allItems[i]->getLocation()->getName() << "'!\n";
    } */
    cout << "Welcome to Sriram's Zuul Game. Here is how you will play.\n";
    cout << "When prompted to make a move, you have 4 action words to choose from. GO, PICK, DROP, QUIT.\n";
    cout << "GO requires a direction (GO NORTH, GO EAST), and you will move in that direction to a different room.\n";
    cout << "PICK requires an item (PICK notebook, PICK sriram), and you will pick up the specified item IF it is in the room you are in.\n";
    cout << "DROP is similar to PICK, it requires an item, and you will drop that specified item IF it is in your inventory.\n";
    while (currentRoom != allRooms[14]) { //While the current room is not the gym (the win conditino)
        currentRoom = play(currentRoom, allRooms, allItems);
    }

    finishGame(allRooms, allItems); //Deletes all rooms and items to avoid memory leak
    cout << "Congratulations on winning!\n";
    return 0;
}

void printItems(Room* target, vector<Item*>& allItems) {
    bool found = false;
    for (int i = 0; i < allItems.size(); ++i) {
        if (allItems[i]->getLocation() == target) {
            found = true;
            if (target == nullptr) {
                cout << "YOU HAVE: " << allItems[i]->getName() << endl;
            }
            else {
                cout << "THIS ROOM HAS: " << allItems[i]->getName() << endl;
            }
        }
    }
    if (!found) {
        if (target == nullptr) {
            cout << "YOU HAVE NO ITEMS.\n";
        }
        else {
            cout << "THIS ROOM HAS NO ITEMS." << endl;
        }
    }
}

Item* findItem(vector<Item*>& allItems, const char* name, Room* currentRoom) {
    for (int i = 0; i < allItems.size(); ++i) {
        if (strcasecmp(allItems[i]->getName(), name) == 0 && allItems[i]->getLocation() == currentRoom) {
            return allItems[i];
        }
    }
    return nullptr;
}

void printExits(Room* target) {
    if (target->getNorth() != nullptr) {
        cout << "To the north is: " << target->getNorth()->getName() << endl;
    }
    if (target->getEast() != nullptr) {
        cout << "To the east is: " << target->getEast()->getName() << endl;
    }
    if (target->getSouth() != nullptr) {
        cout << "To the south is: " << target->getSouth()->getName() << endl;
    }
    if (target->getWest() != nullptr) {
        cout << "To the west is: " << target->getWest()->getName() << endl;
    }
}

Room* play(Room* currentRoom, vector<Room*>& allRooms, vector<Item*>& allItems) {
    cout << "You are in: " << currentRoom->getName() << endl;
    printItems(currentRoom,allItems);
    printItems(nullptr, allItems);
    printExits(currentRoom);
    char action[100], target[100];
    cout << "Make a move: ";
    cin >> action;
    if (strcasecmp(action, "GO") == 0) {
        cin >> target;
        if (strcasecmp(target, "NORTH") == 0 && currentRoom->getNorth() != nullptr) {
            return currentRoom->getNorth();
        }
        else if (strcasecmp(target, "EAST") == 0 && currentRoom->getEast() != nullptr) {
            return currentRoom->getEast();
        }
        else if (strcasecmp(target, "SOUTH") == 0 && currentRoom->getSouth() != nullptr) {
            if (currentRoom == allRooms[13]) {
                Item* item = findItem(allItems, "key", nullptr);
                if (item == nullptr) {
                    cout << "You do not have the key. Go get it then come back!" << endl;
                    return currentRoom;
                }
                else {
                    cout << "Your key unlocks the door, go right in" << endl;
                }
            }
            return currentRoom->getSouth();
        }
        else if (strcasecmp(target, "WEST") == 0 && currentRoom->getWest() != nullptr) {
            return currentRoom->getWest();
        }
        else {
            cout << "Invalid direction. Try again.\n";
        }
    }
    else if (strcasecmp(action, "PICK") == 0) {
        cin >> target;
        Item* item = findItem(allItems, target, currentRoom);
        if (item == nullptr) {
            cout << "Invalid item or not in this room. Try again." << endl;
        }
        else {
            item->setLocation(nullptr);
        }
    }
    else if (strcasecmp(action, "DROP") == 0) {
        cin >> target;
        Item* item = findItem(allItems, target, nullptr);
        if (item == nullptr) {
            cout << "Invalid item, or you don't have that. Try again." << endl;
        }
        else {
            item->setLocation(currentRoom);
        }
    }
    else if (strcasecmp(action, "QUIT") == 0) {
        finishGame(allRooms, allItems);
        exit(0);
    }
    else {
        cout << "Invalid input or input. Try again." << endl;
    }

    return currentRoom;
}


    /*
                    PSEUDOCODE
    print all exits/directions of the current room, and all the items
    cin >> <action> <target>
    if action == GO, {
        if target == north, return currentRoom->getNorth,
        else if target == east, return currentRoom->getEast
        else if target == south, return currentRoom->getSouth
        else if target == west, return currentRoom->getWest }
     else if action == PICK, {
        item = findItem(target)
        item->location = nullPTR,
        return currentRoom
    }
    else if action == DROP {
        item = findItem(target)
        item->location = currentRoom
        return currentRoom
    }
    else if action == QUIT{
        cout << "Thanks for trying"
        finishGame(allRooms, allItems); This will delete all rooms and items to avoid memory leaks
        exit();
        }
    */


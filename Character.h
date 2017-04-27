//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_CHARACTER_H
#define WUMPUS_CHARACTER_H
class Map; //Need to declare it here in order to be able to use it in Character, implemented in Map.h and Map.cpp
class Room; //Need to declare it here in order to be able to use it in Character, implemented in Room.h and Room.cpp

#include "Map.h"

class Character {
protected:
    bool canMove;
    Map* currentMap;
    Room* currentRoom;
public:
    Character(bool canMove, Map* currentMap, Room* currentRoom);
    void moveTo(Room *nextRoom);
};


#endif //WUMPUS_CHARACTER_H

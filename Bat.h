//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_BATS_H
#define WUMPUS_BATS_H


#include "Character.h"

class Bat : Character{
private:
    Room* roomToMoveTo;
public:
    Bat(Map* currentMap, Room* currentRoom, Room* roomToMoveTo):Character(false,currentMap,currentRoom){
        this->roomToMoveTo = roomToMoveTo;
    };
};


#endif //WUMPUS_BATS_H

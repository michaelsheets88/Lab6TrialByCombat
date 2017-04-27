//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_WUMPUS_H
#define WUMPUS_WUMPUS_H


#include "Character.h"

class Wumpus: Character {
public:
    bool kill();
    void wakeUp();

    Wumpus(Map* currentMap, Room*currentRoom):Character(false,currentMap,currentRoom){

    };
};


#endif //WUMPUS_WUMPUS_H

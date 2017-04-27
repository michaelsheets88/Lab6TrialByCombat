//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_HUNTER_H
#define WUMPUS_HUNTER_H


#include "InventoryItem.h"
#include "Room.h"
#include "Character.h"

class Hunter: public Character {
private:
    static const int NUMBER_OF_ITEMS = 2;
    InventoryItem inventory[NUMBER_OF_ITEMS];
public:
    void pickUp();
    bool shootArrow(Room *targetRoom);

    Hunter(): Character(true){

    };
};


#endif //WUMPUS_HUNTER_H

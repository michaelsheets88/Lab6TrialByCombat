//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_HUNTER_H
#define WUMPUS_HUNTER_H


#include "InventoryItem.cpp"
#include "Character.h"

class Child: public Character {
private:
    static const int NUMBER_OF_ITEMS = 2;
    InventoryItem *inventory[NUMBER_OF_ITEMS];
    
public:
    void pickUp();
    Child(): Character(true, goodGuyName){};
};


#endif //WUMPUS_HUNTER_H

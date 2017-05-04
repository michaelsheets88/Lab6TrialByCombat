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
    bool hasTrap = true;

public:
    void pickUp();
    Child(): Character(true, goodGuyName){};
    InventoryItem getCandy();
    InventoryItem getDiapers();
    void addCandy(int amount);
    void addDiaper(int amount);
    bool loseDiaper();
    bool useTrap();

};


#endif //WUMPUS_HUNTER_H

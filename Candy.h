//
// Created by sheetsmj on 4/13/2017.
// Software Dev. 3 Lab 6
//

#ifndef WUMPUS_GOLD_H
#define WUMPUS_GOLD_H

#include "InventoryItem.h"

class Candy: public InventoryItem {
public:
    Candy(int initialAmount) : InventoryItem(initialAmount, true, false, false){}
};

#endif //WUMPUS_GOLD_H

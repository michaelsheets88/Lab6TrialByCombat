//
// Created by sheetsmj on 4/13/2017.
// Software Dev. 3 Lab 6
//

#ifndef WUMPUS_TRAP_H
#define WUMPUS_TRAP_H

#include "InventoryItem.h"
#include "Room.h"

const static int trapLimit = 1;

class Legos : public InventoryItem {
public:
    Legos(): InventoryItem(trapLimit, false, false, true){}
};

#endif //WUMPUS_TRAP_H

//
// Created by sheetsmj on 4/27/2017.
//

#ifndef WUMPUS_TRAP_H
#define WUMPUS_TRAP_H


#include "InventoryItem.h"
const static int trapLimit = 1;

class Trap  : public InventoryItem {
public:
    Trap() : InventoryItem(trapLimit){};
};


#endif //WUMPUS_TRAP_H

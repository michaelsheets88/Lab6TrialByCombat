//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_ARROW_H
#define WUMPUS_ARROW_H

#include "InventoryItem.h"

class DirtyDiaper: public InventoryItem {
public:
    DirtyDiaper(int initialAmount) :  InventoryItem(initialAmount, false, true, false) {}
};

#endif //WUMPUS_ARROW_H

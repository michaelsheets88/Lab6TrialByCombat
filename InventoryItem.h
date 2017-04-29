//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_INVENTORYITEM_H
#define WUMPUS_INVENTORYITEM_H

#include <iostream>

using namespace std;
class InventoryItem {
public:
    bool isTasty;
    bool isStinky;
    bool isDangerous;
    int amount;
    InventoryItem(int initialAmount,bool tasty, bool stinky, bool dangerous) : amount(initialAmount), isTasty(tasty), isStinky(stinky), isDangerous(dangerous){};
    InventoryItem() : amount(0), isTasty(false), isStinky(false), isDangerous(false){};
};

#endif //WUMPUS_INVENTORYITEM_H

//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_INVENTORYITEM_H
#define WUMPUS_INVENTORYITEM_H

class InventoryItem {
public:
    int amount;
    InventoryItem(int initialAmount) : amount(initialAmount){};
    InventoryItem();
};

#endif //WUMPUS_INVENTORYITEM_H

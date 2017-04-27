//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_ROOM_H
#define WUMPUS_ROOM_H


#include <vector>
#include "InventoryItem.h"
#include "Character.h"


class Room {
public:
    void printEntranceText();
    bool hasCharacter();
    bool hasBats();
    bool hasWumpus();
    bool hasHunter();
    bool hasItem();
    InventoryItem* getItems();
    void setItem(InventoryItem *roomItem);
    void setItem();
    bool moveCharacterTo(Character *mover);

    Room();

private:
    InventoryItem *itemInRoom;
    std::vector<Character*> currentCharacters;
};


#endif //WUMPUS_ROOM_H

//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_ROOM_H
#define WUMPUS_ROOM_H


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
private:
    InventoryItem *itemInRoom;
    vector<Character*> currentCharacters;
    Room Room();
};


#endif //WUMPUS_ROOM_H

//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_ROOM_H
#define WUMPUS_ROOM_H


class Room {
public:
    void printEntranceText();
    bool hasBats();
    bool hasWumpus();
    bool hasHunter();
    InventoryItem* getItems();
    void setItem(InventoryItem *roomItem);
    bool moveCharacterTo(Character *mover);
private:
    vector<Character*> currentCharacters;
    Room Room();
};


#endif //WUMPUS_ROOM_H

//
// Created by sheetsmj on 4/13/2017.
//

#include "Room.h"

Room::Room() {
    itemInRoom = nullptr;
    currentCharacters.clear();
}

void Room::setItem() {
    itemInRoom = nullptr;
}

void Room::setItem(InventoryItem *roomItem) {
    itemInRoom = roomItem;
}

bool Room::hasItem(){
    return itemInRoom != nullptr;
}

bool Room::hasCharacter() {
    return !currentCharacters.empty();
}

bool Room::moveCharacterTo(Character* mover){
    currentCharacters.push_back(mover);
}

bool Room::moveCharacterFrom(Character *mover) {
    // Remove mover from currentCharacters
}


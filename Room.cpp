//
// Created by sheetsmj on 4/13/2017.
//

#include "Room.h"

Room::Room() {
    itemInRoom = new InventoryItem();
    currentCharacters.clear();
}

void Room::setItem() {
    itemInRoom = new InventoryItem();
}

void Room::setItem(InventoryItem *roomItem) {
    itemInRoom = roomItem;
}

bool Room::hasItem(){
    return itemInRoom->amount > 0;
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


char Room::getDisplay() {
    if(hasCharacter()){
        if(currentCharacters.front()->name == goodGuyName){
            return PLAYER;
        }else if(currentCharacters.front()->name == badGuyName){
            return DAD;
        }else if(currentCharacters.front()->name == airVent){
            return AIRVENT;
        }
    }else if(hasItem()){
        if(itemInRoom->isTasty){
            return CANDY;
        }else if(itemInRoom->isStinky){
            return DIAPER;
        }else if(itemInRoom->isDangerous){
            return LEGOTRAP;
        }
    } else {
        return EMPTYROOM;
    }
}

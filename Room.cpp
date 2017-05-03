//
// Created by sheetsmj on 4/13/2017.
//

#include <algorithm>
#include "Room.h"

/**
 * Constructor for an empty room.
 */
Room::Room(int row, int col): roomCol(col), roomRow(row){
    itemInRoom = new InventoryItem();
    currentCharacters.clear();
}

/**
 * Constructor for an empty room.
 */
Room::Room() {
    itemInRoom = new InventoryItem();
    roomCol = 100;
    roomRow = 100;
    currentCharacters.clear();
}

/**
 * Set the item in the room to nothing (empty inventory item)
 */
void Room::setItem() {
    itemInRoom = new InventoryItem();
}

/**
 * Set the item in the room to something cool
 * @param roomItem The item to set in the room.
 */
void Room::setItem(InventoryItem *roomItem) {
    itemInRoom = roomItem;
}

bool Room::hasCharacter() {
    return currentCharacters.size() > 1;    //steve....
}

/**
 * Checks to see if there is an actual item to pick up in the room.
 * @return True if there is an item
 */
bool Room::hasItem(){
    return itemInRoom->amount > 0;
}

/**
 * Character moves into the room.
 * Place the characters name into list of characters currently in the room.
 * (This is because the dad is not effected by the air vents and can exist in both)
 * @param mover     The character moving in
 */
void Room::moveCharacterTo(Character* mover){
    currentCharacters.push_back(mover->name);
}

/**
 * Remove the character from the
 * @param mover
 * @return
 */
bool Room::moveCharacterFrom(Character *mover) {
    // Remove mover from currentCharacters
}

bool Room::hasPlayer() {
    bool found = false;
    for(int i = 0; i < currentCharacters.size(); i++){
        if(currentCharacters.at(i) == goodGuyName){
            found = true;
        }
    }
    return found;
}

bool Room::hasDad() {
    bool found = false;
    for(int i = 0; i < currentCharacters.size(); i++){
        if(currentCharacters.at(i) == badGuyName){
            found = true;
        }
    }
    return found;
}

bool Room::hasAirVent(){
    bool found = false;
    for(int i = 0; i < currentCharacters.size(); i++){
        if(currentCharacters.at(i) == airVent){
            found = true;
        }
    }
    return found;
}

//  Character status is more important that the items, except the TRAP
char Room::getDisplay() {
    if(hasCharacter()){
        if(hasPlayer()){
            return PLAYER;
        }else if(hasDad()){
            return DAD;
        }else if(hasAirVent()){
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

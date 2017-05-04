//
// Created by sheetsmj on 4/13/2017.
//

#include <cstdlib>
#include "Map.h"
#include "Candy.h"
#include "DirtyDiaper.h"
#include "Legos.h"

bool Map::canMoveTo(int row, int col) {
    return !(row >= mapRows || row < 0 || col < 0 || col >= mapColumns);
}

bool Map::isDadAlive() {
    return dadAlive;
}

bool Map::isPlayerAlive() {
    return playerAlive;
}

Room* Map::findRandomEmptyRoom() {
    int r = rand() % mapRows;
    int c = rand() % mapColumns;
    while((roomAt(r, c)->hasItem()) || (roomAt(r, c)->hasCharacter())){
        r = rand() % mapRows;
        c = rand() % mapColumns;
    }
    return roomAt(r, c);
}

void Map::populateCandy() {
    // Add 10 candy to empty rooms
    for(int g = 0; g < 20; g++){
        findRandomEmptyRoom()->setItem(new Candy(1));
    }
}

void Map::populateDiapers() {
    // Add 10 arrows to empty rooms
    for(int a = 0; a < maxDiapers; a++){
        findRandomEmptyRoom()->setItem(new DirtyDiaper(rand() % 3));
    }
}

// Add 3 vents to empty rooms
void Map::populateVents() {
    for(int v = 0; v < maxVents; v++){
        int r = rand() % mapRows;
        int c = rand() % mapColumns;
        while((roomAt(r, c)->hasItem()) || (roomAt(r, c)->hasCharacter())){
            r = rand() % mapRows;
            c = rand() % mapColumns;
        }
        moveCharacterTo(new AirVent(r, c), findRandomEmptyRoom());
    }
}

void Map::populatePlayer() {
    moveCharacterTo(player, findRandomEmptyRoom());
}

void Map::populateDad() {
    moveCharacterTo(dad, findRandomEmptyRoom());
}

Room* Map::roomAt(int row, int column) {
    return rooms[row][column];
}

/**
 * The father makes an "attack" before moving into the new room.
 * The playerAlive boolean is set to false. Because kill.
 * @param newRoom   Room being moved into
 */
void Map::dadAttacksTheRoomHeIsEntering(Room *newRoom) {
    if(newRoom->hasPlayer()){
        playerAlive = false;
    }
}

/**
 * The room the player is moving to has a dad or a vent in it.
 * @param child         The player
 * @param newRoom       The room with the bad stuff.
 * @return true if vent (game continues), false if dad (game ending)
 */
void Map::handleChildHazard(Character* child, Room* newRoom){
    if(newRoom->hasDad()){
        playerAlive = false;
    }else{
        AirVent* vent = newRoom->roomsAirVent;
        cout << "Secret air vent tunnel!" << endl;
        moveCharacterTo(child, roomAt(vent->rowToMoveTo, vent->colToMoveTo));
    }
}


/**
 * The dad attacks the room he is moving into(possibly ending the game)
 * The child just moves into the room unless there is a vent that changes where theyre going, or dad catches them
 * The air vent is simply placed in the room at initialization
 * @param mover     The character being moved into the room
 * @param newRoom   The room being moved into
 * @return          True - dad and player alive, keep playing.   False - game over one way or the other.
 */
bool Map::moveCharacterTo(Character *mover, Room *newRoom){
    if(mover->name == badGuyName){
        dadAttacksTheRoomHeIsEntering(newRoom);
        mover->setCurrentRoom(newRoom->getRoomRow(), newRoom->getRoomCol());
    } else if(mover->name == goodGuyName){
        if(newRoom->getItems()->isTasty){
            player->addCandy(newRoom->getItems()->amount);
        } else if (newRoom->getItems()->isStinky)
        if(newRoom->hasDad() || newRoom->hasAirVent()){
            handleChildHazard(mover, newRoom);
        }

        newRoom->moveCharacterTo(mover);
        getRoomStatus(newRoom);
        mover->setCurrentRoom(newRoom->getRoomRow(), newRoom->getRoomCol());
    } else if(mover->name == airVent){
        newRoom->moveCharacterTo(mover);
    }
    return isDadAlive() && isPlayerAlive();
}

/**
 * Prints out the map and locations of stuff
 */
void Map::printMapState() {
    cout << BORDER << endl;
    for(int r = 0; r < mapRows; r++){
        cout << EDGE;
        for(int c = 0; c < mapColumns; c++){
            cout << roomAt(r, c)->getDisplay();
        }
        cout << EDGE << endl;
    }
    cout << BORDER << endl;
}

string Map::getRoomStatus(Room *currentRoom) {
    int column = currentRoom->getRoomCol();
    int row = currentRoom->getRoomRow();
    string status = "You enter a room and hear:";
    bool dadNear = false;
    bool airNear = false;
    if(roomAt(row+1, column)->hasDad() || roomAt(row-1, column)->hasDad() || roomAt(row, column+1)->hasDad() || roomAt(row, column-1)->hasDad()){
        if(dad->canMove){
            status += " snoring";
        }else{
            status += " rustling";
        }
        dadNear = true;
    }
    if(roomAt(row+1, column)->hasAirVent() || roomAt(row-1, column)->hasAirVent() || roomAt(row, column+1)->hasAirVent() || roomAt(row, column-1)->hasAirVent()){
        if(dadNear){
            status += ", and";
        }
        status += " whooshing air.";
        airNear = true;
    }
    if(dadNear && !airNear){
        status += ".";
    }
    return status;
}

bool Map::throwDiaperInto(Room* room){
    if(room->hasDad()){
        dadAlive = false;
        return true;
    }else{
        return false;
    }
}

/**
 * The one, the only MAP CONSTRUCTOR!!!  ::Cheers from the crowd::
 */
Map::Map() {
    for(int r = 0; r < mapRows; r++){
        for(int c = 0; c < mapColumns; c++){
            rooms[r][c] = new Room(r, c);
        }
    }
    player = new Child();
    dad = new Dad();
    populatePlayer();
    populateVents();
    populateCandy();
    populateDiapers();
    populateDad();
    dadAlive = true;
    playerAlive = true;
}

void Map::setTrap(Room* trapRoom) {
    trapRoom->setItem(new Legos());
}
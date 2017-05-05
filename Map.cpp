//
// Created by sheetsmj on 4/13/2017.
// Software Dev. 3 Lab 6
//

#include <cstdlib>
#include <time.h>
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
        AirVent *vent = new AirVent(0, 0);
        Room *room = findRandomEmptyRoom();
        int ventRow = room->getRoomRow();
        int ventCol = room->getRoomCol();
        moveCharacterTo(vent, room);
        room = findRandomEmptyRoom();
        vent->colToMoveTo = room->getRoomCol();
        vent->rowToMoveTo = room->getRoomRow();
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
void Map::dadAttacksTheRoomHeIsEntering(Dad *dad, Room *newRoom) {
    if(newRoom->hasPlayer()){
        playerAlive = false;
    }else if(newRoom->hasSetTrap()){
        dadAlive = false;
    }else{
        roomAt(dad->getRow(), dad->getColumn())->moveCharacterFrom(dad);
        newRoom->moveCharacterTo(dad);
        dad->setCurrentRoom(newRoom->getRoomRow(), newRoom->getRoomCol());
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
        cout << "Secret air vent tunnel!" << endl;
        int destRow = newRoom->roomsAirVent->rowToMoveTo;
        int destCol = newRoom->roomsAirVent->colToMoveTo;
        Room *room =  roomAt(destRow, destCol);
        moveCharacterTo(child, room);
    }
}

void Map::moveChildSafely(Character* child, Room* newRoom){
    InventoryItem *item = newRoom->getItems();
    if(item->isTasty){
        player->addCandy(item->amount);
    } else if (item->isStinky) {
        player->addDiaper(item->amount);
    }
    roomAt(child->getRow(), child->getColumn())->moveCharacterFrom(child);
    newRoom->moveCharacterTo(child);
    cout << giantSpace << "Your current inventory: " << player->getCandy() << " candy, and "<< player->getDiapers() << " diapers." << endl << getRoomStatus(newRoom, (Child*) child) << endl;
    child->setCurrentRoom(newRoom->getRoomRow(), newRoom->getRoomCol());
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
        dadAttacksTheRoomHeIsEntering((Dad*) mover, newRoom);
    } else if(mover->name == goodGuyName){
        if(newRoom->hasDad() || newRoom->hasAirVent()){
            handleChildHazard(mover, newRoom);
        }else{
            moveChildSafely((Child*) mover, newRoom);
        }
    } else if(mover->name == airVent){
        newRoom->moveCharacterTo(mover);
        mover->setCurrentRoom(newRoom->getRoomRow(), newRoom->getRoomCol());
    }
    return isDadAlive() && isPlayerAlive();
}

/**
 * Prints out the map and locations of stuff
 */
void Map::printMapState() {
    cout << HELP_MENU << endl << BORDER << endl;
    for(int r = 0; r < mapRows; r++){
        cout << EDGE;
        for(int c = 0; c < mapColumns; c++){
            cout << roomAt(r, c)->getDisplay();
        }
        cout << EDGE << endl;
    }
    cout << BORDER << endl;
}

bool Map::playerCheck(int row, int col) {
    if((row+1 >= 0 && row+1 < mapRows) && (roomAt(row + 1, col)->hasPlayer())){
        return true;
    }
    if((row-1 >= 0 && row-1 < mapRows) && (roomAt(row - 1, col)->hasPlayer())){
        return true;
    }
    if((col+1 >= 0 && col+1 < mapColumns) && (roomAt(row, col+1)->hasPlayer())){
        return true;
    }
    return (col - 1 >= 0 && col - 1 < mapColumns) && (roomAt(row, col - 1)->hasPlayer());
}

bool Map::ventCheck(int row, int col) {
    if((row+1 >= 0 && row+1 < mapRows) && (roomAt(row + 1, col)->hasAirVent())){
        return true;
    }
    if((row-1 >= 0 && row-1 < mapRows) && (roomAt(row - 1, col)->hasAirVent())){
        return true;
    }
    if((col+1 >= 0 && col+1 < mapColumns) && (roomAt(row, col+1)->hasAirVent())){
        return true;
    }
    return (col - 1 >= 0 && col - 1 < mapColumns) && (roomAt(row, col - 1)->hasAirVent());
}

bool Map::dadCheck(int row, int col) {
    if((row+1 >= 0 && row+1 < mapRows) && (roomAt(row + 1, col)->hasDad())){
        return true;
    }
    if((row-1 >= 0 && row-1 < mapRows) && (roomAt(row - 1, col)->hasDad())){
        return true;
    }
    if((col+1 >= 0 && col+1 < mapColumns) && (roomAt(row, col+1)->hasDad())){
        return true;
    }
    return (col - 1 >= 0 && col - 1 < mapColumns) && (roomAt(row, col - 1)->hasDad());
}

string Map::getRoomStatus(Room *currentRoom, Child *player) {
    string status = "You enter a room and hear:";
    bool dadNear = false;
    bool airNear = false;

    if (dadCheck(currentRoom->getRoomRow(), currentRoom->getRoomCol())){
        if(dad->canMove){
            status += " snoring";
        }else{
            status += " rustling";
        }
        dadNear = true;
    }
    if(ventCheck(currentRoom->getRoomRow(), currentRoom->getRoomCol())){
        if(dadNear){
            status += ", and";
        }
        status += " whooshing air.";
        airNear = true;
    }
    if(dadNear && !airNear){
        status += ".";
    }else if(!dadNear && !airNear){
        status += " nothing.";
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
    srand(time(NULL));
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

void Map::moveDad() {
    if(isDadAlive() and dad->canMove){
        switch(rand() % 5){
            case 1:
                if(canMoveTo(dad->getRow()+1, dad->getColumn())){
                    moveCharacterTo(dad, roomAt(dad->getRow()+1, dad->getColumn()));
                }
                break;
            case 2:
                if(canMoveTo(dad->getRow()-1, dad->getColumn())){
                    moveCharacterTo(dad, roomAt(dad->getRow()-1, dad->getColumn()));
                }
                break;
            case 3:
                if(canMoveTo(dad->getRow()+1, dad->getColumn()+1)){
                    moveCharacterTo(dad, roomAt(dad->getRow(), dad->getColumn()+1));
                }
                break;
            case 4:
                if(canMoveTo(dad->getRow(), dad->getColumn()-1)){
                    moveCharacterTo(dad, roomAt(dad->getRow(), dad->getColumn()-1));
                }
                break;
            case 5:
                dad->canMove = false;
        }
    }
}
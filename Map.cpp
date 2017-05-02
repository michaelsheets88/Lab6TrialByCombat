//
// Created by sheetsmj on 4/13/2017.
//

#include <cstdlib>
#include "Room.h"
#include "Map.h"
#include "Candy.h"
#include "DirtyDiaper.h"
#include "AirVent.h"
#include "Dad.h"

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
    moveCharacterTo(new Child(), findRandomEmptyRoom());
}

void Map::populateDad() {
    moveCharacterTo(new Dad(), findRandomEmptyRoom());
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
bool Map::handleChildHazard(Character* child, Room* newRoom){
    if(newRoom->hasDad()){
        playerAlive = false;
        return false;
    }else{
        AirVent* vent = newRoom->roomsAirVent;
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
    } else if(mover->name == goodGuyName){
        if(newRoom->hasDad() || newRoom->hasAirVent()){
            return handleChildHazard(mover, newRoom);
        }
        newRoom->moveCharacterTo(mover);
    } else if(mover->name == airVent){
        newRoom->moveCharacterTo(mover);
    }else{
        return isDadAlive() && isPlayerAlive();
    }
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

/**
 * The one, the only MAP CONSTRUCTOR!!!  ::Cheers from the crowd::
 */
Map::Map(){
    for(int r = 0; r < mapRows; r++){
        for(int c = 0; c < mapColumns; c++){
            rooms[r][c] = new Room();
        }
    }
    populatePlayer();
    populateVents();
    populateCandy();
    populateDiapers();
    populateDad();
    dadAlive = true;
    playerAlive = true;
}
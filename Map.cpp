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
        moveCharacterTo(new AirVent(findRandomEmptyRoom()), findRandomEmptyRoom());
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

bool Map::moveCharacterTo(Character *mover, Room *newRoom){
    if(mover->name == badGuyName){
        return newRoom->moveCharacterTo(mover);
    } else if(mover->name == goodGuyName){
        return newRoom->moveCharacterTo(mover);
    } else if(mover->name == airVent){
        return newRoom->moveCharacterTo(mover);
    }else{
        return false;
    }
}

void Map::printMapState() {
    for(int r = 0; r < mapRows; r++){
        for(int c = 0; c < mapColumns; c++){
            cout << roomAt(r, c)->getDisplay();
        }
        cout << endl;
    }
}

// This is the map constructor
// It will create a map of many rooms, then
// populate bats, items, player, and wumpus.
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
}
//
// Created by sheetsmj on 4/13/2017.
//


#include <cstdlib>
#include "Map.h"
#include "Candy.h"
#include "DirtyDaiper.h"
#include "AirVent.h"
#include "Dad.h"
#include "Legos.h"

Room* Map::findRandomEmptyRoom() {
    int r = rand() % mapRows;
    int c = rand() % mapColumns;
    while(roomAt(r, c)->hasItem() || roomAt(r, c)->hasCharacter()){
        r = rand() % mapRows;
        c = rand() % mapColumns;
    }
    return roomAt(r, c);
}

void Map::populateGold() {
    // Add 10 gold to empty rooms
    for(int g = 0; g < maxGold; g++){
        findRandomEmptyRoom()->setItem(new Candy(1));
    }
}

void Map::populateArrows() {
    // Add 10 arrows to empty rooms
    for(int a = 0; a < maxArrow; a++){
        findRandomEmptyRoom()->setItem(new DirtyDaiper(rand() % 3));
    }
}

// Add Trap to empty room
void Map::populateTrap(){
    findRandomEmptyRoom()->setItem(new Trap());
}

// Add 3 bats to empty rooms
void Map::populateBats() {
    for(int b = 0; b < maxBats; b++){
        new AirVent(findRandomEmptyRoom());
    }
}

void Map::populateHunter() {
    moveCharacterTo(new Child(), new Room());
}

void Map::populateWumpus() {
    new Dad();
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
    populateHunter();
    populateGold();
    populateBats();
    populateArrows();
    populateTrap();
    populateWumpus();
}

Room* Map::roomAt(int row, int column) {
    return rooms[row][column];
}

bool Map::moveCharacterTo(Character *mover, Room *newRoom){
    if(mover->name == badGuyName){
//        Do bad stuff
        newRoom->moveCharacterTo(mover);

    } else if(mover->name == goodGuyName){
//        Do heroic stuff
        newRoom->moveCharacterTo(mover);

    } else if(mover->name == batName){
        newRoom->moveCharacterTo(mover);

//        Do bat things( nananananananananananna )
    }
}

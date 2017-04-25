//
// Created by sheetsmj on 4/13/2017.
//

#include "Map.h"
Room* Map::findRandomEmptyRoom() {
    int r = rand() % mapRows;
    int c = rand() % mapColumns;
    while(roomAt(r, c).hasItem() || roomAt(r, c).hasCharacter()){
        r = rand() % mapRows;
        c = rand() % mapColumns;
    }
    return roomAt(r, c);
}

void Map::populateGold() {
    // Add 10 gold to empty rooms
    for(int g = 0; g < maxGold; g++){
        roomAt(r, c).setItem(new Gold());
    }
}

void Map::populateArrows() {
    // Add 10 arrows to empty rooms
    for(int a = 0; a < maxArrow; a++){
        findRandomEmptyRoom.setItem(new Arrow(rand() % 3));
    }
}

// Add 3 bats to empty rooms
void Map::populateBats() {
    for(int b = 0; b < maxBats; b++){
        findEmptyRoom().moveCharacterTo(new Bat());
    }
}

void Map::populateHunter(Hunter* player) {
    findRandomEmptyRoom().moveCharacterTo(player);
}

void Map::populateWumpus() {
    findRandomEmptyRoom().moveCharacterTo(new Wumpus());
}


// This is the map constructor
// It will create a map of many rooms, then
// populate bats, items, player, and wumpus.
Map* Map(Hunter* playerCharacter){
    // Create map of empty rooms
    for(int r = 0; r < mapRows; r++){
        for(int c = 0; c < mapColumns; c++){
            roomAt(r, c) = new Room();
        }
    }
    populateGold();
    populateBats();
    populateArrows();
    populateWumpus();
    populateHunter(playerCharacter);
}

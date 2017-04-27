//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_MAP_H
#define WUMPUS_MAP_H

#include "Room.h"
#include "Hunter.h"

const static int mapColumns = 6;
const static int mapRows = 6;
const static int maxGold = 10;
const static int maxArrow = 10;
const static int maxBats = 3;

class Map {
public:
    bool canMoveTo(Room* proposedRoom);
    bool moveCharacterTo(Character *mover, Room *newRoom);
    void printMapState();
    Room* roomAt(int row, int column);
    Room* currentPlayerRoom;
    Room* currentWumpusRoom;
    Map();
private:
    Room* rooms[mapRows][mapColumns];
    Room* findRandomEmptyRoom();
    void populateBats();
    void populateArrows();
    void populateGold();
    void populateTrap();
    void populateWumpus();
    void populateHunter();

};

#endif //WUMPUS_MAP_H

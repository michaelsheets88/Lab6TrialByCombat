//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_MAP_H
#define WUMPUS_MAP_H

#include "Hunter.h"

const static int mapColumns = 6;
const static int mapRows = 6;
const static int maxGold = 10;
const static int maxArrow = 10;
const static int maxBats = 3;

class Map {
public:
    bool canMoveTo(Room* proposedRoom);
    void printMapState();
    Room* roomAt(int row, int column);
    Map* map(Hunter* playerCharacter);
    Map();
private:
    Room* rooms[mapRows][mapColumns];
    //Helper methods
    Room* findRandomEmptyRoom();
    void populateBats();
    void populateArrows();
    void populateGold();
    void populateWumpus();
    void populateHunter(Hunter* player);

};

#endif //WUMPUS_MAP_H

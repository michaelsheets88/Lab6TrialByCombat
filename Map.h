//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_MAP_H
#define WUMPUS_MAP_H

const static int mapColumns = 6;
const static int mapRows = 6;

class Map {
public:
    bool canMoveTo(Room* proposedRoom);
    void printMapState();
    Room* roomAt(int row, int column);
private:
    Room rooms[mapRows][mapColumns];
};


#endif //WUMPUS_MAP_H

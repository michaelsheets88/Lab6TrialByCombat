//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_MAP_H
#define WUMPUS_MAP_H

#include "Room.h"
#include "Child.h"
#include "AirVent.h"
#include "Dad.h"

// Just some constants so we don't have numbers all up in our code.
const static int mapColumns = 6;
const static int mapRows = 6;
const static int maxCandy = 10;
const static int maxDiapers = 10;
const static int maxVents = 3;
const string BORDER = "+------+";
const string EDGE = "|";
const string giantSpace = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";


// This is a pretty beefy class that not only manages the rooms and their creation/inventory,
// but also acts as the controller for moving characters between rooms.
class Map {
public:
    Child* player;
    Dad* dad;
    void setTrap(Room* trapRoom);
    bool canMoveTo(int row, int col);                                   //Character checks if able to move before move can happen.
    bool moveCharacterTo(Character *mover, Room *newRoom);              //Move the character into the new room
    void printMapState();                                               //For debugging, print out whats going on
    string getRoomStatus(Room* currentRoom, Child* player);                            //Checks the rooms adjacent to the room the player just moved into
    Room* roomAt(int row, int column);                                  //Get the pointer for a room at a certain place in the map
    bool isPlayerAlive();                                               //A boolean for the main class to check to see if the player has died
    bool isDadAlive();                                                  //A boolean for the main class to check to see if the dad has been conquered
    bool throwDiaperInto(Room* room);
    Map();                                                              //Constructor
private:
    bool ventCheck(int row, int col);
    bool dadCheck(int row, int col);
    void moveChildSafely(Character* child, Room* newRoom);
    void handleChildHazard(Character* child, Room* newRoom);
    Room* rooms[mapRows][mapColumns];                                   //The 2D array of the rooms
    Room* findRandomEmptyRoom();                                        //Finds an random empty room for populating the map
    void dadAttacksTheRoomHeIsEntering(Dad *dad, Room* newRoom);        //Dad does an attack before he enters a new room
    void populateVents();                                               //Places bats in rooms
    void populateDiapers();                                             //Places arrows in rooms
    void populateCandy();                                               //Places gold in rooms
    void populateDad();                                                 //Places the wumpus in a room
    void populatePlayer();                                              //Places the player somewhere
    bool playerAlive;
    bool dadAlive;
};

#endif //WUMPUS_MAP_H

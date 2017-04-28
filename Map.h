//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_MAP_H
#define WUMPUS_MAP_H

#include "Room.h"
#include "Child.h"

// Just some constants so we don't have numbers all up in our code.
const static int mapColumns = 6;
const static int mapRows = 6;
const static int maxGold = 10;
const static int maxArrow = 10;
const static int maxBats = 3;

class Map {
public:
    bool canMoveTo(Room* proposedRoom);                     //Character checks if able to move before move can happen.
    bool moveCharacterTo(Character *mover, Room *newRoom);  //Move the character into the new room
    void printMapState();                                   //For debugging, print out whats going on
    void getAdjacentRoomStatus(Room* currentRoom);          //Checks the rooms adjacent to the room the player just moved into
    Room* roomAt(int row, int column);                      //Get the pointer for a room at a certain place in the map
    Room* getCurrentPlayerRoom();                           //Reference to the room the player is in
    Room* getCurrentWumpusRoom();                           //Reference to the room the wumpus is in
    void setCurrentPlayerRoom(Room* newPlayerRoom);         //Sets the player's current room
    void setCurrentWumpusRoom(Room* newWumpusRoom);         //Sets the wumpus's current room
    bool attackRoom(Character* attacker);                   //The wumpus attacks the room it's in, the player attacks with arrows
    Map();                                                  //Constructor
private:
    Room* rooms[mapRows][mapColumns];                       //The 2D array of the rooms
    Room* findRandomEmptyRoom();                            //Finds an random empty room for populating the map
    Room* currentPlayerRoom;                                //Reference to the room the player is in
    Room* currentWumpusRoom;                                //Reference to the room the wumpus is in
    void populateBats();                                    //Places bats in rooms
    void populateArrows();                                  //Places arrows in rooms
    void populateGold();                                    //Places gold in rooms
    void populateTrap();                                    //Places a trap in a room
    void populateWumpus();                                  //Places the wumpus in a room
    void populateHunter();                                  //Places the player somewhere
};

#endif //WUMPUS_MAP_H

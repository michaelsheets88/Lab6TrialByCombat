//
// Created by sheetsmj on 4/13/2017.
// Software Dev. 3 Lab 6
//

#ifndef WUMPUS_ROOM_H
#define WUMPUS_ROOM_H

#include "InventoryItem.h"
#include "Character.h"
#include "AirVent.h"
#include <vector>


//Display constants
const static char DAD = 'D';
const static char PLAYER = 'P';
const static char AIRVENT = 'A';
const static char DIAPER = 'S';
const static char CANDY = 'C';
const static char LEGOTRAP = 'X';
const static char EMPTYROOM = '*';
const static string HELP_MENU = "D - Dad\nP - Player\nA - Airvent\nS - (stinky) Diaper\nC - Candy\nX - Lego Trap\n* - Empty Room";

class Room {
public:
    int getRoomRow();
    int getRoomCol();
    bool hasCharacter();                            //Checks to see if the room has any Characters
    bool hasAirVent();                              //Checks to see if the room has an Air Vent
    bool hasDad();                                  //Checks the rooms for Dad
    bool hasPlayer();                               //Checks the room for the player
    bool hasSetTrap();                              //Checks the room for a set Trap!  Oooooh dangerous!!
    bool hasItem();                                 //Checks for inventory items to pick up (only hunter)
    InventoryItem* getItems();                      //Pick up them items! (Destruct them and adjust character inventory array)
    void setItem(InventoryItem *roomItem);          //Puts stuff in the room
    void setItem();                                 //Sets the room to empty(no items)
    char getDisplay();                              //Get the char to print out the map
    void moveCharacterTo(Character* mover);         //Sets the new room p with the character in it, put up items etc.
    bool moveCharacterFrom(Character* mover);       //Clears the character from the last room
    AirVent* roomsAirVent;                          //This is weird, but I need a spot to keep an air vent character, but cant leave it null.  So use a blank air vent constructor that does nothing, but now all rooms have an air vent named steve that cant move.
    Room(int row, int col);                         //Constructor with placement
    Room();                                         //Constructor
private:
    int roomRow;
    int roomCol;
    InventoryItem *itemInRoom;                      //The item in a room
    std::vector<string> currentCharacters;      //The characters in this room
};

#endif //WUMPUS_ROOM_H

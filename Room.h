//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_ROOM_H
#define WUMPUS_ROOM_H


#include <vector>
#include "InventoryItem.h"
#include "Character.h"

//Display constants
const static char DAD = 'D';
const static char PLAYER = 'P';
const static char AIRVENT = 'A';
const static char DIAPER = 'P';
const static char CANDY = 'C';
const static char LEGOTRAP = 'X';

class Room {
public:
    bool hasCharacter();                            //Checks to see if the room has any Characters
    bool hasAirVent();                              //Checks to see if the room has an Air Vent
    bool hasDad();                                  //Checks the rooms for Dad
    bool hasPlayer();                               //Checks the room for the player
    bool hasSetTrap();                              //Checks the room for a set Trap!  Oooooh dangerous!!
    bool hasItem();                                 //Checks for inventory items to pick up (only hunter)
    InventoryItem* getItems();                      //Pick up them items! (Destruct them and adjust character inventory array)
    void setItem(InventoryItem *roomItem);          //Puts stuff in the room
    void setItem();                                 //Sets the room to empty(no items)
    void setDisplay(char newDisplay);               //Change the display for this room.
    char getDisplay();                              //Get the char to print out the map
    bool moveCharacterTo(Character* mover);         //Sets the new room p with the character in it, put up items etc.
    bool moveCharacterFrom(Character* mover);       //Clears the character from the last room
    bool killEverythingInside();                    //Some attack from the kid or dad
    Room();                                         //Constructor
private:
    char display;                                   //For debugging, what to print out for a room
    InventoryItem *itemInRoom;                      //The item in a room
    std::vector<Character*> currentCharacters;      //The characters in this room
};

#endif //WUMPUS_ROOM_H

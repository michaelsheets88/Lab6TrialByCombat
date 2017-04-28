//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_ROOM_H
#define WUMPUS_ROOM_H


#include <vector>
#include "InventoryItem.h"
#include "Character.h"

class Room {
public:
    bool hasCharacter();                            //Checks to see if the room has any Characters
    bool hasBats();                                 //Checks to see if the room has any bats
    bool hasWumpus();                               //Checks the rooms for Wumpus
    bool hasHunter();                               //Checks the room for the hunter
    bool hasSetTrap();                              //Checks the room for a set Trap!  Oooooh dangerous!!
    bool hasItem();                                 //Checks for inventory items to pick up (only hunter)
    InventoryItem* getItems();                      //Pick up them items! (Destruct them and adjust character inventory array)
    void setItem(InventoryItem *roomItem);          //Puts stuff in the room
    void setItem();                                 //Sets the room to empty(no items)
    bool moveCharacterTo(Character* mover);         //Sets the new room p with the character in it, put up items etc.
    bool moveCharacterFrom(Character* mover);       //Clears the character from the last room
    bool killEverythingInside();                    //Some attack from the hunter or wumpus
    Room();                                         //Constructor
private:
    InventoryItem *itemInRoom;                      //The item in a room
    std::vector<Character*> currentCharacters;      //The characters in this room
};

#endif //WUMPUS_ROOM_H

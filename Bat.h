//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_BATS_H
#define WUMPUS_BATS_H



#include "Room.h"

class Bat : public Character{
private:
    Room* roomToMoveTo;
public:
    Bat(Room* roomToMoveTo):Character(false){
        this->roomToMoveTo = roomToMoveTo;
    };
};


#endif //WUMPUS_BATS_H

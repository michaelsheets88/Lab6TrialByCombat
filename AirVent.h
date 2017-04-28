//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_BATS_H
#define WUMPUS_BATS_H



#include "Room.h"

class AirVent : public Character{
private:
    Room* roomToMoveTo;
public:
    AirVent(Room* roomToMoveTo):Character(false){
        this->roomToMoveTo = roomToMoveTo;
    };
};


#endif //WUMPUS_BATS_H

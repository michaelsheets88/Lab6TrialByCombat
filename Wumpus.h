//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_WUMPUS_H
#define WUMPUS_WUMPUS_H


#include "Character.h"

class Wumpus:public Character {
public:
    bool kill();
    void wakeUp();

    Wumpus():Character(false){

    };
};


#endif //WUMPUS_WUMPUS_H

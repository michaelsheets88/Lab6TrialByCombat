//
// Created by sheetsmj on 4/13/2017.
//

#include "Character.h"


void Character::setCurrentRoom(int r, int c) {
    this->row = r;
    this->col = c;
}

int Character::getRow(){
    return row;
}

int Character::getColumn(){
    return col;
}
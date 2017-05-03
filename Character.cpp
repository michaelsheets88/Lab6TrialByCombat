//
// Created by sheetsmj on 4/13/2017.
//

#include "Character.h"

Character::Character(bool canMove, string name) {
    this->canMove = canMove;
    this->name =name;
}

void Character::setPosition(int newRow, int newColumn) {
    this->row = newRow;
    this-col = newColumn;
}
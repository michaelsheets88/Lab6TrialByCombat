//
// Created by sheetsmj on 4/13/2017.
// Software Dev. 3 Lab 6
//

#include "Child.h"

int Child::getCandy(){
    return inventory[0];
}

int Child::getDiapers() {
    return inventory[1];
}

void Child::addCandy(int amount) {
    inventory[0]+=amount;
}

void Child::addDiaper(int amount) {
    inventory[1]+=amount;
}

bool Child::loseDiaper() {
    if(inventory[1]>0){
        inventory[1]-=1;
        return true;
    } else {
        return false;
    }
}

bool Child::useTrap() {
    if(hasTrap){
        hasTrap = false;
        return true;
    } else{
        return false;
    }
}
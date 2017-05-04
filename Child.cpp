//
// Created by sheetsmj on 4/13/2017.
//

#include "Child.h"

InventoryItem Child::getCandy(){
    return *inventory[0];
}

InventoryItem Child::getDiapers() {
    return *inventory[1];
}

void Child::addCandy(int amount) {
    inventory[0]->amount+=amount;
}

void Child::addDiaper(int amount) {
    inventory[1]->amount+=amount;
}

bool Child::loseDiaper() {
    if(inventory[1]->amount>0){
        inventory[1]->amount-=1;
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
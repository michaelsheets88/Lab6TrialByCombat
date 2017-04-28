//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_CHARACTER_H
#define WUMPUS_CHARACTER_H

#include <string>

using namespace std;

const static string badGuyName = "Dad";
const static string goodGuyName = "Child";
const static string airVent = "AirVent";

class Character {
protected:
    bool canMove;
public:
    string name;
    Character(bool canMove){};
};


#endif //WUMPUS_CHARACTER_H

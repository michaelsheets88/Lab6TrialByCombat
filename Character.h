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
const static string defaultName = "Steve";

class Character {
public:
    void setCurrentRoom(int r, int c);
    bool canMove;
    string name;
    Character(bool canMove, string name){};
    Character(): canMove(false), name(defaultName){};
};


#endif //WUMPUS_CHARACTER_H

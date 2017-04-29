//
// Created by sheetsmj on 4/13/2017.
//

#ifndef WUMPUS_BATS_H
#define WUMPUS_BATS_H


class AirVent : public Character{
public:
    int rowToMoveTo;
    int colToMoveTo;
    AirVent(int row, int col):Character(false, airVent), rowToMoveTo(row), colToMoveTo(col){};
    AirVent(): Character(){};
};


#endif //WUMPUS_BATS_H

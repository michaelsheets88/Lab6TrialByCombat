#include <iostream>
#include "Room.cpp"
#include "Map.cpp"
#include "InventoryItem.cpp"
#include "Candy.cpp"
#include "DirtyDiaper.cpp"

using namespace std;

void displayWelcomeMessage();
int gameLoop();
void highScoreSequence(int score);
void displayOpeningOptions();
bool handleOpeningInput();
void displayGameOptions(Map *theMap);
int handleGameInput(Map *);
void displayInstructions();
Map *setUpGame();
void displayErrorMessage(char input);
string determineInfoString(Map *theMap);
void displayEndMessage();
void movePlayerNorth(Map *theMap);
int gameCycle(Map *theMap);
void movePlayerWest(Map *theMap);
void movePlayerSouth(Map *theMap);
void movePlayerEast(Map *theMap);
void launchDiaper(Map *theMap);
void layTrap(Map *theMap);
int quit(Map *theMap);

void printWallMessage();

void throwDiaperDialog();

int const NOT_DONE = -2;
int const LOST = -1;
bool developerOption = false;

int main() {
    displayWelcomeMessage();
    int playerScore = gameLoop();
    if (playerScore > LOST) {
        highScoreSequence(0);
    }
    displayEndMessage();

}

void displayWelcomeMessage() {
    cout << "Welcome" << endl;
}

int gameLoop() {
    do {
        displayOpeningOptions();
    } while (handleOpeningInput());
    Map *map = setUpGame();
    int gameScore;
    do {

        displayGameOptions(map);
        gameScore = handleGameInput(map);
    } while (gameScore == NOT_DONE);
    return gameScore >= 0;
}

void highScoreSequence(int score) {
    cout << "High Score not yet implemented, but your score was " << score;
}

bool handleOpeningInput() {
    char input;
    cin >> input;
    switch (input) {
        case 'h':
            displayInstructions();
            return true;
        case 'd':
            developerOption = true;
            return false;
        case 's':
            return false;
        default:
            displayErrorMessage(input);
            return true;
    }
}


void displayOpeningOptions() {
    cout << "Would you like to (h)ear instructions, enter (d)eveloper mode, or (s)tart game?" << endl;
}

void displayErrorMessage(char input) {
    cout << "This game did not understand your input of " << input << ", please input a character inside parentheses"
         << endl;
}

void displayInstructions() {
    cout << "You are trying to escape Dad inside a house filled with candy and hazards.\n" <<
         "Use the commands presented to you to traverse through the house and\n" <<
         "find the Candy that Dad has been hoarding and avoid getting lost in the air vents,\n" <<
         "where you may lose some of your candy.\n" <<
         "Find Dad, hit him with a Dirty Diaper or set a deadly Lego trap\n" <<
         "and you win, escaping with your Candy.\n" <<
         "But if you wake him up by going into the same room as him and he finds \n " <<
         "you first, then your Candy, and your backside, are forfeit\n";
}

Map *setUpGame() {
    Map *map = new Map();

    if (developerOption) {
        cout << "I am sorry, but the Developer Option has not been implemented yet" << endl;
        //Will create map with developer option enabled to create set map
        map->printMapState();

    } else {
        cout << "Game implementation is still in process, my apologies" << endl;
        //Will create random map as per usual
    }
    return map;
}

int handleGameInput(Map *theMap) {
    char input;
    int score;
    cin >> input;
    switch (input) {
        case 'n':
        case 'N':
            movePlayerNorth(theMap);
            score = gameCycle(theMap);
            break;
        case 'W':
        case 'w':
            movePlayerWest(theMap);
            score = gameCycle(theMap);
            break;
        case 'S':
        case 's':
            movePlayerSouth(theMap);
            score = gameCycle(theMap);
            break;
        case 'E':
        case 'e':
            movePlayerEast(theMap);
            score = gameCycle(theMap);
            break;
        case 'l':
        case 'L':
            launchDiaper(theMap);
            score = gameCycle(theMap);
            break;
        case 'T':
        case 't':
            layTrap(theMap);
            score = gameCycle(theMap);
            break;
        case 'D':
        case 'd':
            score = gameCycle(theMap);
            break;
        case 'Q':
        case 'q':
            score = quit(theMap);
            break;
        default:
            displayErrorMessage(input);
            score = NOT_DONE;
            break;
    }
    return score;
}

int quit() {
    return 0;
}

void layTrap(Map *theMap) {
    theMap->getChildRoom()->setTrap();
    theMap->getChild()->
}

void launchDiaper(Map *theMap) {
    do {
        throwDiaperDialog();
    } while (handleDiaperInput());
}

void throwDiaperDialog() {
    cout << "In which direction would you like to launch your diaper?"<<endl;
    cout << "(N)orth, (S)outh, (E)ast (W)est"<<endl;
}

void movePlayerEast(Map *theMap) {
    int childLocation = theMap->getPlayerRoom();
    if(theMap->canMoveTo(theMap->getRoom(childLocation/theMap->WIDTH,(childLocation%theMap->WIDTH)+1))){
        theMap->moveCharacterTo(theMap->getPlayer,theMap->getRoom(childLocation/theMap->WIDTH,(childLocation%theMap->WIDTH)+1));
    } else {
        printWallMessage();
    }
}

void printWallMessage() {
    cout << "There is no door there." << endl;
}

void movePlayerSouth(Map *theMap) {
    int childLocation = theMap->getChildLocation();
    if(theMap->canMoveTo(theMap->getRoom(childLocation/theMap->WIDTH + 1,(childLocation%theMap->WIDTH)))){
        theMap->moveCharacterTo(theMap->getPlayer,theMap->getRoom(childLocation/theMap->WIDTH,(childLocation%theMap->WIDTH)+1));
    } else {
        printWallMessage();
    }
}

void movePlayerWest(Map *theMap) {
    int childLocation = theMap->getChildLocation();
    if(theMap->canMoveTo(theMap->getRoom(childLocation/theMap->mapRows,(childLocation%theMap->mapRows -1)))){
        theMap->moveCharacterTo(theMap->getPlayer,theMap->getRoom(childLocation/theMap->mapRows,(childLocation%theMap->WIDTH)+1));
    } else {
        printWallMessage();
    }
}

int gameCycle(Map *theMap) {
    if(theMap->isDadAlive())
}

void movePlayerNorth(Map *theMap) {
    int childLocation = theMap->getChildLocation();
    if(theMap->canMoveTo(theMap->getRoom(childLocation/theMap->mapRows - 1,(childLocation%theMap->mapRows )))){
        theMap->moveCharacterTo(theMap->getPlayer,theMap->getRoom(childLocation/theMap->mapRows,(childLocation%theMap->mapRows)+1));
    } else {
        printWallMessage();
    }
}

void displayGameOptions(Map *theMap) {
    cout << determineInfoString(theMap) << endl;
    cout << "Actions: (N)orth, (S)outh, (E)ast, (W)est, (L)aunch a diaper, Lay a (T)rap, (D)elay, (Q)uit" << endl;
}

string determineInfoString(Map *theMap) {
    return theMap->getAdjacentRoomStatus(theMap->getChildRoom);
}

void displayEndMessage() {

}

//  The way to access the rooms through the map:
//  theMap->moveCharacterTo(theMap->roomAt(ROW int, COLUMN int))
//  This returns true if successful, false if failure
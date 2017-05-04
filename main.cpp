#include <iostream>
#include "Room.cpp"
#include "Map.cpp"
#include "Character.cpp"
#include "Child.cpp"

using namespace std;

void displayWelcomeMessage();
int gameLoop();
void highScoreSequence(int newScore);
void displayOpeningOptions();
bool handleOpeningInput();
void displayGameOptions();
int handleGameInput(Map *);
void displayInstructions();
Map *setUpGame();
void displayErrorMessage(char input);
void displayEndMessage();
bool movePlayerNorth(Map *theMap);
bool movePlayerWest(Map *theMap);
bool movePlayerSouth(Map *theMap);
bool movePlayerEast(Map *theMap);
bool launchDiaper(Map *theMap);
void layTrap(Map *theMap);

void printWallMessage();

void throwDiaperDialog();

bool handleDiaperInput(Map *theMap);

int const NOT_DONE = -2;
int const LOST = -1;
bool developerOption = false;
vector<int> scores = {0};

int main() {
    displayWelcomeMessage();
    int playerScore = gameLoop();
    if (playerScore > LOST) {
        highScoreSequence(playerScore);
    }
    displayEndMessage();
    return 0;
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

        displayGameOptions();
        gameScore = handleGameInput(map);
    } while (gameScore == NOT_DONE);
    return gameScore >= 0;
}

void highScoreSequence(int newScore) {
    scores.push_back(newScore);
    cout<< "High Scores for this session:"<<endl;
    for(int eachScore : scores){
        cout << eachScore<<endl;
    }
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
    bool isNotDone = false;
    cin >> input;
    switch (input) {
        case 'n':
        case 'N':
            isNotDone = movePlayerNorth(theMap);
            break;
        case 'W':
        case 'w':
            isNotDone = movePlayerWest(theMap);
            break;
        case 'S':
        case 's':
            isNotDone = movePlayerSouth(theMap);
            break;
        case 'E':
        case 'e':
            isNotDone = movePlayerEast(theMap);
            break;
        case 'l':
        case 'L':
            if(theMap->player->loseDiaper()){
                isNotDone =  launchDiaper(theMap);
            } else {
                cout << "You are out of Diapers"<<endl;
            }
            break;
        case 'T':
        case 't':
            if(theMap->player->useTrap()){
                layTrap(theMap);
                isNotDone = true;
                break;
            }
        case 'D':
        case 'd':
            isNotDone = theMap->moveCharacterTo(theMap->player,theMap->roomAt(theMap->player->getRow(),theMap->player->getColumn()));
            break;
        case 'Q':
        case 'q':
            isNotDone = false;
            break;
        default:
            displayErrorMessage(input);
            isNotDone = true;
            break;
    }
    if(isNotDone){
        return NOT_DONE;
    } else {
        if (!theMap->isPlayerAlive()){
            return LOST;
        } else {
            return theMap->player->getCandy().amount;
        }
    }
}

void layTrap(Map *theMap) {
    theMap->setTrap(theMap->roomAt(theMap->player->getRow(),theMap->player->getColumn()));
}

bool launchDiaper(Map *theMap) {
    throwDiaperDialog();
    return handleDiaperInput(theMap);
}

bool handleDiaperInput(Map *theMap) {
    char input;

    bool isNotDone = true;
    bool erroring = true;
    while(erroring){
        cin >> input;
        switch (input){
            case 'n':
            case 'N':
                isNotDone = !theMap->throwDiaperInto(theMap->roomAt(theMap->player->getRow()-1,theMap->player->getColumn()));
                erroring = false;
                break;
            case 'W':
            case 'w':
                isNotDone = !theMap->throwDiaperInto(theMap->roomAt(theMap->player->getRow(),theMap->player->getColumn()-1));
                erroring = false;
                break;
            case 'S':
            case 's':
                isNotDone = !theMap->throwDiaperInto(theMap->roomAt(theMap->player->getRow()+1,theMap->player->getColumn()));
                erroring = false;
                break;
            case 'E':
            case 'e':
                isNotDone = !theMap->throwDiaperInto(theMap->roomAt(theMap->player->getRow(),theMap->player->getColumn()+1));
                erroring = false;
                break;
            default:
                displayErrorMessage(input);
                erroring = true;
                break;
        }
    }
    return isNotDone;

}

void throwDiaperDialog() {
    cout << "In which direction would you like to launch your diaper?"<<endl;
    cout << "(N)orth, (S)outh, (E)ast (W)est"<<endl;
}

bool movePlayerEast(Map *theMap) {
    if(theMap->canMoveTo(theMap->player->getRow(),theMap->player->getColumn()+1)){
        return theMap->moveCharacterTo(theMap->player,theMap->roomAt(theMap->player->getRow(),theMap->player->getColumn()+1));
    } else {
        printWallMessage();
        return true;
    }
}

void printWallMessage() {
    cout << "There is no door there." << endl;
}

bool movePlayerSouth(Map *theMap) {
    if(theMap->canMoveTo(theMap->player->getRow()+1,theMap->player->getColumn())){
        return theMap->moveCharacterTo(theMap->player,theMap->roomAt(theMap->player->getRow(),theMap->player->getColumn()+1));
    } else {
        printWallMessage();
        return true;
    }
}

bool movePlayerWest(Map *theMap) {
    if(theMap->canMoveTo(theMap->player->getRow(),theMap->player->getColumn()-1)){
        return theMap->moveCharacterTo(theMap->player,theMap->roomAt(theMap->player->getRow(),theMap->player->getColumn()+1));
    } else {
        printWallMessage();
        return true;
    }
}


bool movePlayerNorth(Map *theMap) {
    if(theMap->canMoveTo(theMap->player->getRow(),theMap->player->getColumn()+1)){
        return theMap->moveCharacterTo(theMap->player,theMap->roomAt(theMap->player->getRow(),theMap->player->getColumn()+1));
    } else {
        printWallMessage();
        return true;
    }
}

void displayGameOptions() {
    cout << "Actions: (N)orth, (S)outh, (E)ast, (W)est, (L)aunch a diaper, Lay a (T)rap, (D)elay, (Q)uit" << endl;
}

void displayEndMessage() {
    cout<<"We are sorry, but currently the game does not loop back into welcoming screen, we hope you enjoyed it, and if you want to play again, restart the program.";
}
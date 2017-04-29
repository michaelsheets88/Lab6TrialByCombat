#include <iostream>
#include "Map.cpp"

using namespace std;

void displayWelcomeMessage();

int gameLoop();

void highScoreSequence(int score);

void displayOpeningOptions();

bool handleOpeningInput();

void displayGameOptions();

int handleGameInput();

void displayInstructions();

void setUpGame();

void displayErrorMessage(char input);

string determineInfoString();

void displayEndMessage();

int const NOT_DONE = -2;
int const LOST = -1;
bool developerOption = false;

int main() {
    Map *map = new Map();
    map->printMapState();

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
    setUpGame();
    int gameScore;
    do {
        displayGameOptions();
        gameScore = handleGameInput();
    } while (gameScore == NOT_DONE);
    return gameScore >= 0;
}

void highScoreSequence(int score) {
    cout << "High Score not yet implemented, but your score was" << score;
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
    cout << "You are hunting a Dad inside a cave filled with gold and hazards.\n" <<
         "Use the commands presented to you to traverse through the cave and\n" <<
         "find the Candy the Dad has been hoarding and avoid Bats, who will\n" <<
         "will steal some of your gold if they find you.\n" <<
         "Find the Dad, shoot an arrow at him or set a deadly trap\n"<<
         "and you win, escaping with your gold.\n" <<
         "But if you wake him up by going into the same room as him and he finds \n "<<
         "you first, then your gold, and life, are forfeit\n";
}

void setUpGame() {
    if (developerOption) {
        cout << "I am sorry, but the Developer Option has not been implemented yet";
        //Will create map with developer option enabled to create set map
    } else {
        cout << "Game implementation is still in process, my apologies";
        //Will create random map as per usual
    }
}

int handleGameInput() {
    char input;
    cin >> input;
    switch (input)
        case 'n':
        case 'N':
            cout << "You Move North" << endl;
}

void displayGameOptions() {
    cout << determineInfoString() << endl;
    cout << "Actions: (N)orth, (S)outh, (E)ast (W)est, shoot (A)rrow, (W)ait, (Q)uit" << endl;
}

string determineInfoString() {
    return "Info will be provided when implemented";
}

void displayEndMessage(){

}


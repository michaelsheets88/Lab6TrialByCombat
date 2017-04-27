#include <iostream>
using namespace std;

void displayWelcomeMessage();
bool gameLoop();
void highScoreSequence();
void displayEndMessage();

int main() {
    displayWelcomeMessage();
    bool playerWon = gameLoop();
    if(playerWon){
        highScoreSequence();
    } else {
        displayEndMessage();
    }
}

void displayWelcomeMessage(){
    cout << "Welcome"<<endl;
}

void


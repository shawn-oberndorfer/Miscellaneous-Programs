#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

int currentRound[4] = {3, 4, 5, 7};
int livePerRound[4] = {1, 2, 3, 4};
int blankPerRound[4] = {2, 2, 2, 3};
string round1[3] = {"Blank", "Live", "Blank"};
string round2[4] = {"Blank", "Live", "Blank", "Live"};
string round3[5] = {"Live", "Blank", "Live", "Blank", "Live"};
string round4[7] = {"Blank", "Live", "Blank", "Live", "Blank", "Live", "Live"};
string items[5] = {"Handcuffs", "Handsaw", "Beer", "Magnifine Glass", "Cigarette"};

bool opponetTurnSkipped = false;

string BulletType(int);
bool turnOutcome(bool, int&, int&, int);
bool playerTurn();
bool opponetTurn();
void useItems( string&, string&, string&, string&, string&, string&, int&, int& );
void giveItems(string& , string& , string& , string& , string& , string& );
void gameOver(int, int);
int roll(int currentRound[], int);

int main(){
    srand(time(0));
    int roundNumber = 1;
    int playerHealth = 3;
    int opponentHealth = 3;
    int shotsFired;
    bool playersTurn;
    string playerItem1, playerItem2, playerItem3;
    string oppItem1, oppItem2, oppItem3;

    while(playerHealth > 0 && opponentHealth > 0 && roundNumber < 5){
        cout << "Round " << roundNumber << "!\n";
        cout << "Player Health: " << playerHealth << " | Opponent Health: " << opponentHealth << "\n";
        cout << "There are " << livePerRound[roundNumber - 1] << " live rounds and " << blankPerRound[roundNumber - 1] << " blank rounds in the chamber.\n\n";
        giveItems(playerItem1, playerItem2, playerItem3, oppItem1, oppItem2, oppItem3);
        shotsFired = 0;
        playersTurn = true;
        while(shotsFired < currentRound[roundNumber - 1]){
            playersTurn = turnOutcome(playersTurn, playerHealth, opponentHealth, roundNumber);
            shotsFired++;
            if(playerHealth <= 0 || opponentHealth <= 0) {
                break;
            }
        }
        roundNumber++;
    }
    gameOver(playerHealth, opponentHealth);
    return 0;
}

string BulletType(int roundNumber){
    int result;

    if(roundNumber == 1){
        do{    
            result = roll(currentRound, roundNumber);
        } while(round1[result] == " ");
        string shot = round1[result];
        round1[result] = " ";
        return shot;
    } else if(roundNumber == 2){
        do{    
            result = roll(currentRound, roundNumber);
        } while(round2[result] == " ");
        string shot = round2[result];
        round2[result] = " ";
        return shot;
    } else if(roundNumber == 3){
        do{    
            result = roll(currentRound, roundNumber);
        } while(round3[result] == " ");
        string shot = round3[result];
        round3[result] = " ";
        return shot;
    } else if(roundNumber == 4){
        do{    
            result = roll(currentRound, roundNumber);
        } while(round4[result] == " ");
        string shot = round4[result];
        round4[result] = " ";
        return shot;
    }
    return "Null";
}

bool playerTurn(){
    int playerChoice;
    cout << "Would would you like to shoot?\n 1. Yourself\n 2. Opponent\n";
    cin >> playerChoice;
    if(playerChoice == 1){
        return true;
    } else if(playerChoice == 2){
        return false;
    } else {
        cout << "Invalid choice. Please choose again.\n";
        return playerTurn();
    }
}

bool opponetTurn(){
    if(opponetTurnSkipped == true){
        opponetTurnSkipped = false;
        cout << "Your opponent's turn is skipped due to Handcuffs!\n\n";
    } else if(opponetTurnSkipped == false){
    
        int opponentChoice = rand() % 2 + 1;
        if(opponentChoice == 1){
            return true;
        } else if(opponentChoice == 2){
            return false;
        } else {
            return opponetTurn();
        }
    }
}

bool turnOutcome(bool playersTurn, int &playerHealth, int &opponentHealth, int roundNumber){
    bool playerShot;
    if(playersTurn == true){
        playerShot = playerTurn();
    } else if(playersTurn == false){
        playerShot = opponetTurn();
    }
    
    string shotType = BulletType(roundNumber);
    if(opponetTurnSkipped == true && playersTurn == false){
        playersTurn = true;
    } else if(playersTurn == true && playerShot == true){
        if(shotType == "Blank"){
            cout << "You shot yourself with a blank round!\n\n";
            playersTurn = true;
        } else if(shotType == "Live"){
            cout << "You shot yourself with a live round!\n\n";
            playerHealth--;
            playersTurn = false;
        }
    } else if(playersTurn == true && playerShot == false){
        if(shotType == "Blank"){
            cout << "You shot your opponent with a blank round!\n\n";
            playersTurn = false;
        } else if(shotType == "Live"){
            cout << "You shot your opponent with a live round!\n\n";
            opponentHealth--;
            playersTurn = false;
        }
    } else if(playersTurn == false && playerShot == true){
        this_thread::sleep_for(std::chrono::seconds(1));
        if(shotType == "Blank"){
            cout << "Your opponent shot you with a blank round!\n\n";
            playersTurn = true;
        } else if(shotType == "Live"){
            cout << "Your opponent shot you with a live round!\n\n";
            playerHealth--;
            playersTurn = true;
        }
    } else if(playersTurn == false && playerShot == false){
        this_thread::sleep_for(std::chrono::seconds(3));
        if(shotType == "Live"){
            cout << "Your opponent shot themselves with a live round!\n\n";
            opponentHealth--;
            playersTurn = true;
        } else if(shotType == "Blank"){
            cout << "Your opponent shot themselves with a blank round!\n\n";
            playersTurn = false;
        }
    }
    return playersTurn;
}

int roll(int currentRound[], int roundNumber){
    int shotFired;
    shotFired = (rand() % currentRound[roundNumber-1]);
    return shotFired;
}

void useItems(string& playerItem1, string& playerItem2, string& playerItem3, string& oppItem1, string& oppItem2, string& oppItem3, int &playerHealth, int &opponentHealth){
    int playerChoice;
    string usedItem;
    cout << "You have the following items:\n";
    cout << "1. " << playerItem1 << "\n";
    cout << "2. " << playerItem2 << "\n";
    cout << "3. " << playerItem3 << "\n";
    cin >> playerChoice;
    switch(playerChoice){
        case 1:
            usedItem = playerItem1;
            playerItem1 = "";
            break;
        case 2:
            usedItem = playerItem2;
            playerItem2 = "";
            break;
        case 3:
            usedItem = playerItem3;
            playerItem3 = "";
            break;
        default:
            cout << "Invalid choice. Please choose again.\n";
            useItems(playerItem1, playerItem2, playerItem3, oppItem1, oppItem2, oppItem3, playerHealth, opponentHealth);
            return;
    }
    if(usedItem == "Handcuffs"){
        cout << "You used Handcuffs. Your opponent's next turn is skipped.\n";
        opponetTurnSkipped = true;
    } else if(usedItem == "Handsaw"){
        cout << "You used Handsaw. The shotgun now deals 2 health points.\n";
        
    } else if(usedItem == "Beer"){
        cout << "You used Beer. Your opponent loses 1 health point.\n";
        
    } else if(usedItem == "Magnifine Glass"){
        cout << "You used Magnifine Glass. You can see if the next shot is a blank or live.\n";
        
    } else if(usedItem == "Cigarette"){
        cout << "You used Cigarette. You regain 1 health.\n";
        // Implement effect
    } else {
        cout << "No item used.\n";
    }
}
void giveItems(string& playerItem1, string& playerItem2, string& playerItem3, string& oppItem1, string& oppItem2, string& oppItem3){
    if(playerItem1 == ""){
        playerItem1 = items[rand() % 5];
        cout << "You received a " << playerItem1 << "!\n";
    }if(playerItem2 == ""){
        playerItem2 = items[rand() % 5];
        cout << "You received a " << playerItem2 << "!\n";
    }if(playerItem3 == ""){
        playerItem3 = items[rand() % 5];
        cout << "You received a " << playerItem3 << "!\n";
    }if(oppItem1 == ""){
        oppItem1 = items[rand() % 5];
        cout << "Your opponent received a " << oppItem1 << "!\n";
    }if(oppItem2 == ""){
        oppItem2 = items[rand() % 5];
        cout << "Your opponent received a " << oppItem2 << "!\n";
    }if(oppItem3 == ""){
        oppItem3 = items[rand() % 5];
        cout << "Your opponent received a " << oppItem3 << "!\n";
    }
}

void gameOver(int playerHealth, int opponentHealth){
    cout << "Game Over!\n";
    if(playerHealth = 0){
        cout << "You have been defeated!\n";
    } else if(opponentHealth <= 0){
        cout << "You are victorious!\n";
    } else {
        cout << "The game ended in a draw!\n";
    }
    cout << "Thanks for playing!\n";
}
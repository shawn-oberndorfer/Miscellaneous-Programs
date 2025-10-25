/* 
Shawn Oberndorfer
Craps Simulator
Start Date 9/22/2025
Last Worked On 9/22/2025
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int roll();
int moneyTotal();
int preRollBet();
int firstRollResults();
int pointRollResults();
int winCondition();
int gameOver();

int roll1;
int roll2;
int point;
int betNumber;
int sum;
int winConditionNum;
int winConditionCheck;
double betAmount;
double totalMoney;
bool gameEnd;
bool moneyConfirm;
string blankSpace;
char moneyConfirm2;

int main()
{
   srand(time(0));
   moneyTotal();
   preRollBet();
   firstRollResults();
   
   if(gameEnd == true){
    winCondition();
    gameOver();
   }
   else{
    pointRollResults();
    winCondition();
    gameOver();
   }
    return 0;
}

int roll(){
    int myRoll;
    myRoll = (rand() % 6) + 1;
    return myRoll;
}
int moneyTotal(){
    do{
        cout << "How much money do you have?" << endl;
        cin >> totalMoney;
        cout << "Confirm you have $" << totalMoney << ". (Y/N)" << endl;
        cin >> moneyConfirm2;
        moneyConfirm2 = toupper(moneyConfirm2);
        if(moneyConfirm2 == 'Y'){
            moneyConfirm = true;
        } else{
            moneyConfirm = false;
        }
    }while(moneyConfirm == false);
    return 0;
}
int preRollBet(){
    cout << "What bet would you like to place?" << endl;
    cout << "1. Pass Line" << endl;
    cout << "2. Don't Pass Line" << endl;
    cin >> betNumber;
    if(betNumber == 1){
        winConditionNum = 1;
    } 
    else if(betNumber == 2){
        winConditionNum = 2;
    }
    cout << "How much money would you like to bet?" << endl;
    cin >> betAmount;
    return 0;
}
int firstRollResults(){
    roll1 = roll();
    roll2 = roll();
    sum = roll1 + roll2;

    cout << "ROLL: " << sum << endl;

    if (sum == 7 || sum == 11){
        winConditionCheck = 1;
        gameEnd = true;
    }
    else if(sum == 2 || sum == 3 || sum == 12){
        winConditionCheck = 2;
        gameEnd = true;
    } 
    else if(sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10){
        point = sum;
        cout << "The point is: " << point << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Hit 'enter' to roll again." << endl;
        cin.get();
        gameEnd = false;
    }

    return 0;
}
int pointRollResults(){
    do{
        roll1 = roll();
        roll2 = roll();
        sum = roll1 + roll2;

        cout << "ROLL: " << sum << endl;
        if(sum == point){
            winConditionCheck = 1;
            gameEnd = true;
        } else if(sum == 7){
            winConditionCheck = 2;
            gameEnd = true;
        }else{
            cout << "Roll again." << endl;
            cin.ignore();
            gameEnd = false;
        }

    }while(gameEnd == false);

    return 0;
}
int winCondition(){
    if(winConditionNum == winConditionCheck){
        cout << "Congrats You Win!" << endl;
        totalMoney = totalMoney + betAmount;
        cout << "You now have $" << totalMoney << "." << endl;
    }
    else{
        cout << "Sorry you lose." << endl;
        totalMoney = totalMoney - betAmount;
        cout << "You now have $" << totalMoney << "." << endl;
    }
    return 0;
}
int gameOver(){
    cout << "------Game Over------" << endl;
    cout << "Thank You For Playing" << endl;
    return 0;
}
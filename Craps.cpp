/* 
M3T2 - Craps Part 1
CSC 134
Shawn Oberndorfer
Start Date 9/22/2025
Last Worked On 9/22/2025
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int roll();
int firstRollResults();

int roll1;
int roll2;
int point;
bool gameEnd;

int main()
{
   
    srand(time(0));

    
    


    return 0;
}

int roll(){
    int myRoll;
    myRoll = (rand() % 6) + 1;
    return myRoll;
}
int firstRollResults(){
    roll1 = roll();
    roll2 = roll();
    int sum = roll1 + roll2;

    cout << "ROLL: " << sum << endl;

    if (sum == 7 || sum == 11){
        cout <<"You Win!" << endl;
        gameEnd = true;
    }
    else if(sum == 2 || sum == 3 || sum == 12){
        cout << "You Lose" << endl;
        gameEnd = true;
    } 
    else if(sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10){
            point = sum;
            cout << "Your point is: " << point << endl;
            gameEnd = false;
    }
}
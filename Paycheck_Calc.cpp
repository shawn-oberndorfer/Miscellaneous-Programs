/*
Shawn Oberndorfer
Created on 8/27/2025
Last Edited on 8/27/2025
A calculator for someone's paycheck
*/
#include <iostream>
using namespace std;

int main(){
    string user_name      = "";
    char   wage_confirm   = 'N';
    double hours_worked   = 0;
    double minutes_worked = 0;
    double hourly_wage    = 0;
    


    cout << "Hello what is your name?" << endl;
    cin >> user_name; 
    cout << "Welcome " << user_name << " to paycheck calculator." << endl;
    cout << "Please enter what your hourly rate is." << endl;
    do {
    cin >> hourly_wage;
    cout << "To confirm, do you make $" << hourly_wage << " an hour. (Y/N)" << endl;
    cin >> wage_confirm;
    wage_confirm = toupper(wage_confirm);

    if(wage_confirm == 'Y') {
        cout << "Hourly Wage Confirmed" << endl;
    }   else if(wage_confirm == 'N') {
        cout << "Please re-enter your hourly wage." << endl;
    }   else {
        cout << "Invalid Input" << endl;
        cout << "Please re-enter your hourly wage followed by a \"Y\" or a \"N\"." << endl;
        wage_confirm = 'N';
    }
        /* code */
    } while (wage_confirm == 'N');
    


return 0;
}
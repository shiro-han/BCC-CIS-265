/*
    CIS-265 Payroll Project v3
    Date: 11.05.2020
    Coded By: Shiro Han
    Version: 3.0

    CIS-165 Review Program for Professor Aljamal's Bergen Community College Class
*/

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main() {
    const int NUM_EMPLOYEES = 3;
    const float STATETAXPERCENT = .06;
    const float FEDTAXPERCENT = .12;
    const float UNIONFEEPERCENT = .02;

    float totalGross = 0;
    float averageGross;

    struct employee {
        string firstName;
        char middleInitial;
        string lastName;
        float rate;
        int hours;
        //inputted values

        float overtime;
        float gross;
        float stateTax;
        float fedTax;
        float unionFee;
        float net;
        //calculated values
    } e1, e2, e3;

    cout << "Enter employee " << 1 << "'s First Name" << endl;
    cin >> e1.firstName;
    cout << endl;

    cout << "Enter employee " << 1 << "'s Middle Initial" << endl;
    cin >> e1.middleInitial;
    cout << endl;

    cout << "Enter employee " << 1 << "'s Last Name" << endl;
    cin >> e1.lastName;
    cout << endl;

    cout << "Enter employee " << 1 << "'s Rate per Hour" << endl;
    cin >> e1.rate;
    cout << endl;
    while (!(e1.rate > 0 && e1.rate < 50)) {
        cout << "Invalid Input. Enter a number between 0 and 50" << endl;
        cout << "Enter employee " << 1 << "'s Rate per Hour" << endl;
        cin >> e1.rate;
        cout << endl;
    }

    cout << "Enter employee " << 1 << "'s Hours Worked" << endl;
    cin >> e1.hours;
    cout << endl;
    while (!(e1.hours > 0 && e1.hours < 60)) {
        cout << "Invalid Input. Enter a number between 0 and 60" << endl;
        cout << "Enter employee " << 1 << "'s Hours Worked" << endl;
        cin >> e1.hours;
        cout << endl;
    }

    if (e1.hours > 40){
        e1.overtime = (e1.hours - 40) * e1.rate * 1.5;
    } else {
        e1.overtime = 0;
    }

    e1.gross = e1.rate * e1.hours + e1.overtime;
    e1.stateTax = e1.gross * .06;
    e1.fedTax = e1.gross * .12;
    e1.unionFee = e1.gross * .02;
    e1.net = e1.gross - (e1.stateTax + e1.fedTax + e1.unionFee);
    totalGross += e1.gross;
    //input for the first employee. Since the instructions told us not to use any functions or arrays I did not modularize this code, and will be repeating it for the 2nd and 3rd employee.

    cout << "Enter employee " << 2 << "'s First Name" << endl;
    cin >> e2.firstName;
    cout << endl;

    cout << "Enter employee " << 2 << "'s Middle Initial" << endl;
    cin >> e2.middleInitial;
    cout << endl;

    cout << "Enter employee " << 2 << "'s Last Name" << endl;
    cin >> e2.lastName;
    cout << endl;

    cout << "Enter employee " << 2 << "'s Rate per Hour" << endl;
    cin >> e2.rate;
    cout << endl;
    while (!(e2.rate > 0 && e2.rate < 50)) {
        cout << "Invalid Input. Enter a number between 0 and 50" << endl;
        cout << "Enter employee " << 2 << "'s Rate per Hour" << endl;
        cin >> e2.rate;
        cout << endl;
    }

    cout << "Enter employee " << 2 << "'s Hours Worked" << endl;
    cin >> e2.hours;
    cout << endl;
    while (!(e2.hours > 0 && e2.hours < 60)) {
        cout << "Invalid Input. Enter a number between 0 and 60" << endl;
        cout << "Enter employee " << 2 << "'s Hours Worked" << endl;
        cin >> e2.hours;
        cout << endl;
    }

    if (e2.hours > 40){
        e2.overtime = (e2.hours - 40) * e2.rate * 1.5;
    } else {
        e2.overtime = 0;
    }

    e2.gross = e2.rate * e2.hours + e2.overtime;
    e2.stateTax = e2.gross * .06;
    e2.fedTax = e2.gross * .12;
    e2.unionFee = e2.gross * .02;
    e2.net = e2.gross - (e2.stateTax + e2.fedTax + e2.unionFee);
    totalGross += e2.gross;
    //input for the second employee

    cout << "Enter employee " << 3 << "'s First Name" << endl;
    cin >> e3.firstName;
    cout << endl;

    cout << "Enter employee " << 3 << "'s Middle Initial" << endl;
    cin >> e3.middleInitial;
    cout << endl;

    cout << "Enter employee " << 3 << "'s Last Name" << endl;
    cin >> e3.lastName;
    cout << endl;

    cout << "Enter employee " << 3 << "'s Rate per Hour" << endl;
    cin >> e3.rate;
    cout << endl;
    while (!(e3.rate > 0 && e3.rate < 50)) {
        cout << "Invalid Input. Enter a number between 0 and 50" << endl;
        cout << "Enter employee " << 3 << "'s Rate per Hour" << endl;
        cin >> e3.rate;
        cout << endl;
    }

    cout << "Enter employee " << 3 << "'s Hours Worked" << endl;
    cin >> e3.hours;
    cout << endl;
    while (!(e3.hours > 0 && e3.hours < 60)) {
        cout << "Invalid Input. Enter a number between 0 and 60" << endl;
        cout << "Enter employee " << 3 << "'s Hours Worked" << endl;
        cin >> e3.hours;
        cout << endl;
    }

    if (e3.hours > 40){
        e3.overtime = (e3.hours - 40) * e3.rate * 1.5;
    } else {
        e3.overtime = 0;
    }

    e3.gross = e3.rate * e3.hours + e3.overtime;
    e3.stateTax = e3.gross * .06;
    e3.fedTax = e3.gross * .12;
    e3.unionFee = e3.gross * .02;
    e3.net = e3.gross - (e3.stateTax + e3.fedTax + e3.unionFee);
    totalGross += e3.gross;
    //input for the third employee

    averageGross = totalGross/NUM_EMPLOYEES;

    cout << setprecision(2) << fixed << showpoint << endl;
    cout << setw(80) << "Data Housing Corp. Weekly Payroll" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "First Name" << setw(5) << "MI" << setw(10) << "Last Name" << setw(14) << "Rate per hour" << setw(14) << "Hours worked" << setw(14) << "Overtime" << setw(14) << "Gross Income" << setw(14) << "State Tax" << setw(14) << "Federal Tax" << setw(14) << "Union fees" << setw(5) << "Net" << endl;
    cout << "==========" << setw(5) << "==" << setw(10) << "=========" << setw(14) << "=============" << setw(14) << "============" << setw(14) << "========" << setw(14) << "============" << setw(14) << "=========" << setw(14) << "===========" << setw(14) << "==========" << setw(5) << "===" << endl;

    cout << left << setw(13) << e1.firstName << setw(3) << e1.middleInitial << setw(10) << e1.lastName << setw(1) << "$" << setw(14) << e1.rate << setw(18) << e1.hours << setw(1) << "$" << setw(9) << e1.overtime << setw(1) << "$" << setw(16) << e1.gross << setw(1) << "$" << setw(11) << e1.stateTax << setw(1) << "$" << setw(14) << e1.fedTax << setw(1) << "$" << setw(10) << e1.unionFee << setw(1) << "$" << setw(7) << e1.net << endl;
    //output for the first employee. Since the instructions told us not to use any functions or arrays I did not modularize this code, and will be repeating it for the 2nd and 3rd employee.

    cout << left << setw(13) << e2.firstName << setw(3) << e2.middleInitial << setw(10) << e2.lastName << setw(1) << "$" << setw(14) << e2.rate << setw(18) << e2.hours << setw(1) << "$" << setw(9) << e2.overtime << setw(1) << "$" << setw(16) << e2.gross << setw(1) << "$" << setw(11) << e2.stateTax << setw(1) << "$" << setw(14) << e2.fedTax << setw(1) << "$" << setw(10) << e2.unionFee << setw(1) << "$" << setw(7) << e2.net << endl;
    cout << left << setw(13) << e3.firstName << setw(3) << e3.middleInitial << setw(10) << e3.lastName << setw(1) << "$" << setw(14) << e3.rate << setw(18) << e3.hours << setw(1) << "$" << setw(9) << e3.overtime << setw(1) << "$" << setw(16) << e3.gross << setw(1) << "$" << setw(11) << e3.stateTax << setw(1) << "$" << setw(14) << e3.fedTax << setw(1) << "$" << setw(10) << e3.unionFee << setw(1) << "$" << setw(7) << e3.net << endl;
    //ouput for the remaining 2 employees

    cout << endl;
    cout << setw(15) << "Total Gross:" << '$' << totalGross << endl;
    cout << setw(15) << "Average Gross:" << '$' << averageGross << endl;

}
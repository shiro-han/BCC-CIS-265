/*
  CIS-265 Payroll Project
  Date: 10.02.2020
  Coded By: Shiro Han
  Version: 1.0

  CIS-165 Review Program for Professor Aljamal's Bergen Community College Class
*/

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main() {
  int numEmployees;

  cout << "Enter the number of employees to be entered:" << endl;
  cin >> numEmployees;
  cout << endl;

  while (numEmployees < 0){
    cout << "Invalid Input. Enter a positive number:" << endl;
    cin >> numEmployees;
    cout << endl;
  }

  if (numEmployees == 0) {
    cout << "0 Employees entered. Payroll will not be generated." << endl;
    cout << "Exiting program...";
    return 0;
  }

  string firstNames[numEmployees];
  char middleInitial[numEmployees];
  string lastNames[numEmployees];
  float rate[numEmployees];
  int hours[numEmployees];
  //Arrays for all inputed values

  float overtime[numEmployees];
  float gross[numEmployees];
  float stateTax[numEmployees];
  float fedTax[numEmployees];
  float unionFee[numEmployees];
  float net[numEmployees];
  float totalGross = 0;
  float averageGross;
  //Arrays for all calculated values

  for (int i = 0; i < numEmployees; i++){
    cout << "Enter employee " << i+1 << "'s First Name" << endl;
    cin >> firstNames[i];
    cout << endl;

    cout << "Enter employee " << i+1 << "'s Middle Initial" << endl;
    cin >> middleInitial[i];
    cout << endl;

    cout << "Enter employee " << i+1 << "'s Last Name" << endl;
    cin >> lastNames[i];
    cout << endl;

    cout << "Enter employee " << i+1 << "'s Rate per Hour" << endl;
    cin >> rate[i];
    cout << endl;
    while (!(rate[i] > 0 && rate[i] < 50)) {
      cout << "Invalid Input. Enter a number between 0 and 50" << endl;
      cout << "Enter employee " << i+1 << "'s Rate per Hour" << endl;
      cin >> rate[i];
      cout << endl;
    }

    cout << "Enter employee " << i+1 << "'s Hours Worked" << endl;
    cin >> hours[i];
    cout << endl;
    while (!(hours[i] > 0 && hours[i] < 60)) {
      cout << "Invalid Input. Enter a number between 0 and 60" << endl;
      cout << "Enter employee " << i+1 << "'s Hours Worked" << endl;
      cin >> hours[i];
      cout << endl;
    }

    if (hours[i] > 40){
      overtime[i] = (hours[i] - 40) * rate[i] * 1.5;
    } else {
      overtime[i] = 0;
    }

    gross[i] = rate[i] * hours[i] + overtime[i];
    stateTax[i] = gross[i] * .06;
    fedTax[i] = gross[i] * .12;
    unionFee[i] = gross[i] * .02;
    net[i] = gross[i] - (stateTax[i] + fedTax[i] + unionFee[i]);
    totalGross += gross[i];
  } //This loop asks for all the input necessary for each employee, as well as calculates all the values necessary per employee.

  averageGross = totalGross/numEmployees;

  cout << setprecision(2) << fixed << showpoint << endl;
  cout << setw(80) << "Data Housing Corp. Weekly Payroll" << endl;
  cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << "First Name" << setw(5) << "MI" << setw(10) << "Last Name" << setw(14) << "Rate per hour" << setw(14) << "Hours worked" << setw(14) << "Overtime" << setw(14) << "Gross Income" << setw(14) << "State Tax" << setw(14) << "Federal Tax" << setw(14) << "Union fees" << setw(5) << "Net" << endl;
  cout << "==========" << setw(5) << "==" << setw(10) << "=========" << setw(14) << "=============" << setw(14) << "============" << setw(14) << "========" << setw(14) << "============" << setw(14) << "=========" << setw(14) << "===========" << setw(14) << "==========" << setw(5) << "===" << endl;

  for (int i = 0; i < numEmployees; i++){
    cout << left << setw(13) << firstNames[i] << setw(3) << middleInitial[i] << setw(10) << lastNames[i] << setw(1) << "$" << setw(14) << rate[i] << setw(18) << hours[i] << setw(1) << "$" << setw(9) << overtime[i] << setw(1) << "$" << setw(16) << gross[i] << setw(1) << "$" << setw(11) << stateTax[i] << setw(1) << "$" << setw(14) << fedTax[i] << setw(1) << "$" << setw(10) << unionFee[i] << setw(1) << "$" << setw(7) << net[i] << endl;
  } //This loop prints out the data gathered during the first loop in the correct format.
  
  cout << endl;
  cout << setw(15) << "Total Gross:" << '$' << totalGross << endl;
  cout << setw(15) << "Average Gross:" << '$' << averageGross << endl;

}
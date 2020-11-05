/*
  CIS-265 Payroll Project v2
  Date: 10.30.2020
  Coded By: Shiro Han
  Version: 2.0

  CIS-165 Review Program for Professor Aljamal's Bergen Community College Class
*/

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
void input_employees(const int, string [], char [], string [], float [], float [], float [], float [], float [], float [], float [], float [], float &, float &);
void output(const int, string [], char [], string [], float [], float [], float [], float [], float [], float [], float [], float [], float &, float &);
float input_validation(float, int, int);
void string_input(string [], int, string);
void char_input(char [], int, string);
void float_input(float [], int, string, int, int);

float overtimeFn(float, float);
float grossFn(float, float, float);
float stateTaxFn(float);
float fedTaxFn(float);
float unionFeeFn(float);
float netFn(float, float, float, float);
void totalGrossFn(float &, float);
float averageGrossFn(float, const int);

int main() {
  const int NUM_EMPLOYEES = 3;

  string firstNames[NUM_EMPLOYEES];
  char middleInitial[NUM_EMPLOYEES];
  string lastNames[NUM_EMPLOYEES];
  float rate[NUM_EMPLOYEES];
  float hours[NUM_EMPLOYEES];
  //Arrays for all inputed values

  float overtime[NUM_EMPLOYEES];
  float gross[NUM_EMPLOYEES];
  float stateTax[NUM_EMPLOYEES];
  float fedTax[NUM_EMPLOYEES];
  float unionFee[NUM_EMPLOYEES];
  float net[NUM_EMPLOYEES];
  float totalGross = 0;
  float averageGross;
  //Arrays for all calculated values

  input_employees(NUM_EMPLOYEES, firstNames, middleInitial, lastNames, rate, hours, overtime, gross, stateTax, fedTax, unionFee, net, totalGross, averageGross);
  output(NUM_EMPLOYEES, firstNames, middleInitial, lastNames, rate, hours, overtime, gross, stateTax, fedTax, unionFee, net, totalGross, averageGross);

}

float overtimeFn(float hours, float rate){
  if (hours > 40){
    return (hours - 40) * rate * 1.5;
  } else {
    return 0;
  }
}

float grossFn(float rate, float hours, float overtime){
  return rate * hours + overtime;
}

float stateTaxFn(float gross){
  const float STATETAXPERCENT = .06;
  return gross * STATETAXPERCENT;
}

float fedTaxFn(float gross){
  const float FEDTAXPERCENT = .12;
  return gross * FEDTAXPERCENT;
}

float unionFeeFn(float gross){
  const float UNIONFEEPERCENT = .02;
  return gross * UNIONFEEPERCENT;
}

float netFn(float gross, float stateTax, float fedTax, float unionFee){
  return gross - (stateTax + fedTax + unionFee);
}

void totalGrossFn(float &totalGross, float currentGross){
  totalGross += currentGross;
}

float averageGrossFn(float totalGross, const int NUM_EMPLOYEES){
  return totalGross/NUM_EMPLOYEES;
}

void input_employees(const int NUM_EMPLOYEES, string firstNames[], char middleInitial[], string lastNames[], float rate[], float hours[], float overtime[], float gross[], float stateTax[], float fedTax[], float unionFee[], float net[], float &totalGross, float &averageGross){
  for (int i = 0; i < NUM_EMPLOYEES; i++){
    string_input(firstNames, i, "First Name");
    char_input(middleInitial, i, "Middle Initial");
    string_input(lastNames, i, "Last Name");
    float_input(rate, i, "Rate per Hour", 0, 50);
    float_input(hours, i, "Hours Worked", 0, 60);

    overtime[i] = overtimeFn(hours[i], rate[i]);

    gross[i] = grossFn(rate[i], hours[i], overtime[i]);
    stateTax[i] = stateTaxFn(gross[i]);
    fedTax[i] = fedTaxFn(gross[i]);
    unionFee[i] = unionFeeFn(gross[i]);
    net[i] = netFn(gross[i], stateTax[i], fedTax[i], unionFee[i]);
    totalGrossFn(totalGross, gross[i]);
  } //This loop asks for all the input necessary for each employee, as well as calculates all the values necessary per employee.

  averageGross = averageGrossFn(totalGross, NUM_EMPLOYEES);
}

void output(const int NUM_EMPLOYEES, string firstNames[], char middleInitial[], string lastNames[], float rate[], float hours[], float overtime[], float gross[], float stateTax[], float fedTax[], float unionFee[], float net[], float &totalGross, float &averageGross){
  cout << setprecision(2) << fixed << showpoint << endl;
  cout << setw(80) << "Data Housing Corp. Weekly Payroll" << endl;
  cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << "First Name" << setw(5) << "MI" << setw(10) << "Last Name" << setw(14) << "Rate per hour" << setw(14) << "Hours worked" << setw(14) << "Overtime" << setw(14) << "Gross Income" << setw(14) << "State Tax" << setw(14) << "Federal Tax" << setw(14) << "Union fees" << setw(5) << "Net" << endl;
  cout << "==========" << setw(5) << "==" << setw(10) << "=========" << setw(14) << "=============" << setw(14) << "============" << setw(14) << "========" << setw(14) << "============" << setw(14) << "=========" << setw(14) << "===========" << setw(14) << "==========" << setw(5) << "===" << endl;

  for (int i = 0; i < NUM_EMPLOYEES; i++){
    cout << left << setw(13) << firstNames[i] << setw(3) << middleInitial[i] << setw(10) << lastNames[i] << setw(1) << "$" << setw(14) << rate[i] << setw(18) << hours[i] << setw(1) << "$" << setw(9) << overtime[i] << setw(1) << "$" << setw(16) << gross[i] << setw(1) << "$" << setw(11) << stateTax[i] << setw(1) << "$" << setw(14) << fedTax[i] << setw(1) << "$" << setw(10) << unionFee[i] << setw(1) << "$" << setw(7) << net[i] << endl;
  } //This loop prints out the data gathered during the first loop in the correct format.
  
  cout << endl;
  cout << setw(15) << "Total Gross:" << '$' << totalGross << endl;
  cout << setw(15) << "Average Gross:" << '$' << averageGross << endl;
}

void string_input(string array[], int currentNum, string label){
  cout << "Enter employee " << currentNum+1 << "'s " << label << endl;
  cin >> array[currentNum];
  cout << endl;
}

void char_input(char array[], int currentNum, string label){
  cout << "Enter employee " << currentNum+1 << "'s " << label << endl;
  cin >> array[currentNum];
  cout << endl;
}

void float_input(float array[], int currentNum, string label, int lower_bound, int upper_bound){
  float input;
  cout << "Enter employee " << currentNum+1 << "'s " << label << endl;
  cin >> input;
  cout << endl;
  array[currentNum] = input_validation(input, lower_bound, upper_bound);
}

float input_validation(float input, int lower_bound, int upper_bound){
  while (input <= lower_bound || input >= upper_bound) {
      cout << "Invalid Input. Enter a number between " << lower_bound << " and " << upper_bound << ": ";
      cin >> input;
      cout << endl;
    }
  return input;
}
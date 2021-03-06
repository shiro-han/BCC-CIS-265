/*
  CIS-265 Area Functions by Value
  Date: 10.23.2020
  Coded By: Shiro Han
  Version: 2.0

  Assignment 2A for Professor Aljamal's Bergen Community College Class
*/
#include <iostream>
#include <cmath>
using namespace std;

//declare constants
const double PI = 3.1415926;

//declare prototypes
void greeting();
void startup();
float inputFn(float);
float positiveValidator(float);
void circle();
void square();
void rectangle();

//Main method - executes when program is run
int main() {
    greeting();
    startup();

    cout << "\nExiting Program...";
    return 0;
}

//Greeting method - prints text when user starts program
void greeting(){
    cout << "Welcome to Simple Area Calculation Program v1.0" << endl;
    cout << "Select one of the following options to get started: " << endl;
    cout << "1. Calculate Area of a Circle" << endl;
    cout << "2. Calculate Area of a Square" << endl;
    cout << "3. Calculate Area of a Rectangle" << endl;
    cout << "4. Exit Program" << endl << endl;
}

//handles the user's selection and uses recursion if an invalid input is given
void startup(){
    int selection;
    cout << "Select your option: ";
    cin >> selection;
    cout << endl;

    switch(selection){
        case 1:
            circle();
            break;
        case 2:
            square();
            break;
        case 3:
            rectangle();
            break;
        case 4:
            break;
        default:
            cout << "Invalid Input. Selection must be a number from 1-4." << endl;
            startup();
            break;
    }
}

//input fn - asks user for input, and returns input if input is positive.
//if input is negative, sends value to validator function and assigns the return value of validator function to input, which is then returned within the inputFn.
float inputFn(){
    float input;

    cin >> input;
    if (input < 0){
        input = positiveValidator(input);
    }

    return input;
}

//uses a while loop for input validation. returns value when input is valid
float positiveValidator(float input){
    while (input < 0){
        cout << endl;
        cout << "Invalid Input. Please enter a positive number: ";
        cin >> input;
    }

    return input;
}

//calculates area of circle
void circle(){
    float radius, area;

    cout << "Calculating Area of a Circle" << endl;
    cout << "Please enter the radius of your circle: ";
    radius = inputFn();

    area = pow(radius, 2)*PI;
    
    cout << "\nThe area of your circle is " << area;
}

//calculates area of square
void square(){
    float side, area;

    cout << "Calculating Area of a Square" << endl;
    cout << "Please enter the length of a side of your square: ";
    side = inputFn();

    area = pow(side, 2);
    
    cout << "\nThe area of your square is " << area;
}

//calculates area of rectangle
void rectangle(){
    float side1, side2, area;

    cout << "Calculating Area of a Rectangle" << endl;

    cout << "Please enter the base of your rectangle: ";
    side1 = inputFn();

    cout << "Please enter the height of your rectangle: ";
    side2 = inputFn();

    area = side1*side2;
    
    cout << "\nThe area of your rectangle is " << area;
}
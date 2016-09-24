

    //pre-processor directives
#include <iostream>         //input output stream
#include <cmath>            // math header file
using namespace std;

    //named constant variables
const string PROGRAMMER_NAME =" Chris Andrzejewski ";
const double CENTIMETERS_PER_INCH = 2.54;
const int INCHES_PER_FOOT = 12;

int main ()
{
    // Output Programmer Information
    cout <<"Name: "<< PROGRAMMER_NAME <<endl;
    cout <<"Program Information: CS150 Lab Assignment 1";
    cout <<"\n========== Lab 1 2016 =====================\n";

        //declare variables
    int feet=0;
    int inches=0;
    int totalInches=0;
    double centimeter=0;

        //Statements: Step 1 - Step 7
    cout <<endl;
    cout << " Enter an integer value for feet: ";        //Step 1a
    cin >> feet;                                         //Step 2a
    cout << " Enter an integer value for inches: ";      //Step 1b
    cin >> inches;                                       //Step 2b

    cout << endl<< " You entered:\n\t" << feet
         << " feet\n\t" << inches <<" inches"<< endl;    //Step 3

    totalInches = INCHES_PER_FOOT * feet + inches;       //Step 4


    cout << endl << " - Total number of inches = " << totalInches << endl; //Step 5

    centimeter = CENTIMETERS_PER_INCH * totalInches;     //Step 6

    cout << " - Total number of centimeters = " << centimeter << endl;                                //Step 7


    cout <<"\n\n";
    cout <<"\n==========================================\n";
    return 0;
}

/*/********************************************************
Programmer Name:
Lab CRN:
Date:
FileName: lab01_2016_F_LName.cpp

Program Information: cs150 Lab Assignment 1
Based on a Malik text example-Write a program that converts measurements input in feet and
 inches, to the equivalent in centimeters.
 Formula: 1 inch is equal to 2.54 centimeters.
*///********************************************************

    //pre-processor directives
#include <iostream>         //input output stream
#include <cmath>            // math header file
using namespace std;

    //named constant variables
const string PROGRAMMER_NAME =" stewie griffin ";
const double CENTIMETERS_PER_INCH = 2.54;
const int INCHES_PER_FOOT = 12;

int main ()
{
    // Output Programmer Information
    cout <<"Name: "<< PROGRAMMER_NAME <<endl;
    cout <<"Program Information: (describe the program)";
    cout <<"\n========== Lab 1 2016 =====================\n";

        //declare variables
    int feet=0;
    int inches=0;
    int totalInches=0;
    double centimeter=0;

        //Statements: Step 1 - Step 7
    cout <<endl;
                                    //Step 1a
                                    //Step 2a
                                    //Step 1b
                                   //Step 2b

    cout << endl<< " You entered:\n\t" << feet
         << " feet\n\t" << inches <<" inches"<< endl;  //Step 3

                                    //Step 4

                                    //Step 5

                                    //Step 6

                                    //Step 7


    cout <<"\n\n";
    cout <<"\n==========================================\n";
    return 0;
}

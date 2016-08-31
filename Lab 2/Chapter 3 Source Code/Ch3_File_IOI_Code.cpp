/* Study this program, and what it does. Run it, and see how
many files are created. Delete them, and run it again. Do the
new files have the same data, or new user data each time the
program is run?
    Description: fill this in with a concise brief description
    (step-by-step) of what this program does:






    Note the code that error checks the input and output file
    streams.
*/

#include <iostream>     // input and output functionality
#include <fstream>      //for input and output files
#include <iomanip>      // output formatting
#include <cmath>        // math functions
#include <string>
using namespace std;
int main()
{
    cout << "*********************************\n";
	cout << "*       Lab Assignment 2        *\n";
	cout << "*  CS150 ODU Computer Science   *\n";
	cout << "*      Whaaaaaaaaat?            *\n";
	cout << "*   fall semester 2015          *\n";
	cout << "*  example of multi file I/O    *\n";
	cout << "*********************************\n\n";



    // variable declaration and initialization
    double celsius=0, high=0, low=0, average=0; //store temperature data
    string name, date;                          //store user name, and date


    // output file stream variable 1
    ofstream outFile1;
    outFile1.open ("fahrenheit.txt");
    //check for failure opening OUTPUT file 1
    if(!outFile1){
        cout<<"\n ERROR creating output file. \n";
        return 0;
        }

    // output file stream variable 2
    ofstream outFile2;
    outFile2.open ("celsius.txt");
    //To do: check for failure opening OUTPUT file
    if(!outFile2){
        cout<<"\n ERROR creating output file. \n";
        return 0;
        }


    //prompt for input values
    cout << "\nEnter the date in mm/dd/yy format: "; // prompt user
    cin >> date;                                   // capture input and store in date variable
    cout << "Enter the low temperature value: ";          //.....
    cin >> low;
    cout << "Enter the high temperature value: ";         //...
    cin >> high;

     //calculate and store average value
    average = (high + low) / 2.0;


    //write results out to file, and then to screen
    outFile1 << date << "  " << average <<"\n";
    cout <<"\nDate: "<< date << "   Avg: " << average <<" Fahrenheit.\n";


    //close the output file stream
    outFile1.close();

    //set up input file stream to read from the file
    ifstream inFile;
    inFile.open("fahrenheit.txt");
    //To do: check for failure opening input file
    if(!inFile){
        cout <<"\n Input File Error! \n";
        return 0;
    }

    // read the data from the file
    inFile >> date;
    inFile >> average;

    // calculate the celsius equivalent of the fahrenheit temp
    // look back at the example program Ch3_TemperatureConversion_C.cpp
    // to see how to do this with the static cast
    celsius = ((average - 32.0) * (5.0 / 9.0));


    //configure file output formatting, and output to file
    outFile2 << showpoint << fixed << setprecision(2);
    outFile2 << date << "  " << celsius <<"\n";

    //configure standard output (monitor) formatting, and output to monitor
    cout << showpoint << fixed << setprecision(2);
    cout <<"\nDate: "<< date << "   Avg: " << celsius <<" Celsius.\n";


    ////close down file stream objects, and terminate program
    inFile.close();
    outFile2.close();
    return 0;
}
//========================end of main======================

//Programmer :
//Date       :
//Lab        :
//Description:

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//declare constants
const double PI = 3.14; //Global constant Variable


int main()
{

//Declare & initialize variables     TO STORE
    double cube_length=0.0;       //cube length
    double rectangle_width=0.0;   //rectangle width
    double rectangle_length=0.0;  //rectangle length
    double radius=0.0;            //circle radius
    double cube_area=0.0;         //cube area
    double cube_vol=0.0;          //cube volume
    double circ_area=0.0;         //circle area
    double circ_circumference=0.0;//circle circumference
    double rectangle_area=0.0;    //rectangle area
    double rectangle_perimeter=0.0;//rectangle perimeter


   ///Programmer_info

   // add the programmer code output that is shown at
   // the top of our lab 2 assignment document.



    ///CUBE
    cout << "\n" <<  setw( 20 ) << setfill( '=' ) << "=" << "CUBE" <<  setw( 20 ) << setfill( '=' ) << "=";
    cout<< endl << endl;

    cout << left << setw(20) << setfill(' ') << "Enter the length" << ": ";

    ///Prompt the user for length of a cube



    /// Write the code for calculating the area of the cube using formulas provided in the prompt





    //formatting output
    cout.fill(' '); //set the fill character to ' ' (space)
    cout.flags(  ios::showpoint | ios::fixed ); //set formatting flags
    cout.precision(2);

   //Summary of the measurements
    cout <<"\n"
         << setw( 16 ) << left << "  Length"<<":" << setw(10) << right << cube_length    << "\n"
         << setw( 16 ) << left << "  Area" <<":"  << setw(10) << right <<  "\n"
         << setw( 16 ) << left << "  Volume"<<":" << setw(10) << right <<  "\n";

    ///CIRCLE
    cout << "\n" <<  setw( 20 ) << setfill( '=' ) << "=" << "CIRCLE" <<  setw( 18 ) << setfill( '=' ) << "=";
    cout<< endl << endl;

    cout << left << setw(20) << setfill(' ') << "Enter the radius" << ": ";

    ///Prompt the user for circle radius




    /// Write the code for calculating the area and circumference of the circle using formulas provided in the prompt





    //Summary of the measurements
    cout << "\n"
     << setw( 16 ) << left << "  Radius" << ":" << setw(10) << right << radius     << "\n"
     << setw( 16 ) << left << "  Area"   << ":" << setw(10) << right <<   "\n"
     << setw( 16 ) << left << "  Circumference" << ":" << setw(10) << right <<  "\n";

    ///RECTANGLE
    cout << "\n" <<  setw( 20 ) << setfill( '=' ) << "=" << "RECTANGLE" <<  setw( 15 ) << setfill( '=' ) << "=";
    cout<< endl << endl;
    cout << left << setw(20) << setfill(' ') << "Enter the length" << ": "<<"\n";
    ///Prompt the user for rectangle length
    cout << left << setw(20) << setfill(' ') << "Enter the width" << ": ";
    ///Prompt the user for rectangle width




    /// Write the code for calculating the area and perimeter of the rectangle using formulas provided in the prompt





    //Summary of the measurements
    cout << "\n"
     << setw( 16 ) << left << "  length" << ":" << setw(10) << right << rectangle_length    << "\n"
     << setw( 16 ) << left << "  width" << ":" << setw(10) << right << rectangle_width     << "\n"
     << setw( 16 ) << left << "  Area"   << ":" << setw(10) << right <<  "\n"
     << setw( 16 ) << left << "  Perimeter" << ":" << setw(10) << right << "\n";



    return 0;
}



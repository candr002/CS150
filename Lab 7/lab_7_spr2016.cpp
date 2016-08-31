// Array Lab - spring 2016
// Put your required lab information here - name, date, ta name, email,.. ect... or lose points.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


void printit (   const int [],  int );
void fill_it( int  anArray [],  int size );


int main()
{

    const int SIZE_ONE = 20;
    int list_one [SIZE_ONE];


     fill_it ( list_one,  SIZE_ONE );

     cout << "\nlist_one \n\n";
     printit ( list_one, SIZE_ONE );




   cout << endl<< endl;
   return 0;
}
///end of main()
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// prints out the entries in an array
void printit ( const int  anArray [],  int size )
{
     int looper ;
     for (looper =0;looper <size;looper++)
            cout   <<  setw(5) <<anArray [looper] <<endl;

}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// fills an array with random numbers between 0 and 50, inclusive
void fill_it( int  anArray [],  int size )
{
    int num ;
    int looper;
    for ( looper = 0; looper < size ; looper++)

    {
        num = (rand () + time (0) ) % 51;
        anArray[looper] = num;

    }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// function definitions for the ones that you write:  squareIt, lowVal, tally, ect

///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

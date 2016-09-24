

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;


            ///Declaring function prototypes
///===============================================
void printit (   const int [],  int );
void fill_it( int  anArray [],  int size );
void reversePrinter ( const int  anArray [],  int size );
int tally (const int anArray [], int size, int target);
void squareIt (int anArray[], int size);
int lowVal (int anArray[], int size);

int main()
{
        ///Declaring Variables
    const int SIZE_ONE = 20;
    int list_one[SIZE_ONE];
    const int SIZE_TWO = 8 ;
    int list_two[SIZE_TWO] ;
    int inputValue = 0;



            ///Enumerating and outputting Arrays
///===================================
     fill_it ( list_one,  SIZE_ONE );

     cout << "\nlist_one \n\n";
     printit ( list_one, SIZE_ONE );

     fill_it (list_two, SIZE_TWO);

     cout <<"\nlist_two \n\n";
     printit (list_two, SIZE_TWO);


            ///Calling reversing function and outputting results
///====================================
    cout <<"\nlist_one in reverse\n\n";
    reversePrinter(list_one, SIZE_ONE);

    cout <<"\nlist_two in reverse\n\n";
    reversePrinter(list_two, SIZE_TWO);


            ///Calling tally function and outputting results
///====================================
    cout <<"\nlist_two tally\n\n";
    cout <<tally(list_two, SIZE_TWO, 40);

    cout <<"\nlist_one tally\n\n";
    cout <<tally(list_one, SIZE_ONE, 10) << endl;


    cout << "\nInput Value: ";
    cin >> inputValue;
    cout << "\nTally for List_one for given value of\""<< inputValue
        << "\" is:\n" << tally(list_one, SIZE_ONE, inputValue);


            ///Calling squaring function and outputting results
///====================================
    squareIt(list_one, SIZE_ONE);
    squareIt(list_two, SIZE_TWO);

    cout << "\nlist_one after squareit:\n\n";
    printit(list_one, SIZE_ONE);

    cout << "\nlist_two after squareit:\n\n";
    printit(list_two, SIZE_TWO);


            ///Calling lowest value function and outputting results
///====================================
    cout << "\n\nthe lowest value in list_one is: "
        <<lowVal(list_one, SIZE_ONE) << endl << endl ;

    cout << "the lowest value in list_two is: "
        <<lowVal(list_two, SIZE_TWO) << endl << endl ;

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
            ///Prints the array in reverse order
void reversePrinter ( const int  anArray [],  int size )
{
     int looper ;
     for (looper =(size - 1);looper >= 0;looper--)
            cout   <<  setw(5) <<anArray [looper] <<endl;
}

///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
            ///Outputs values equal or lower than target index
int tally (const int anArray [], int size, int target)
{

    int thecount = 0 ;
    for (int looper = 0; looper <= (target - 1); looper++)
        if (anArray[looper]>=target)
            (thecount++);

    return thecount;
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
            ///Replaces values within the array with their square
void squareIt (int anArray[], int size)
{


    for (int looper = 0; looper < size; looper++)
         anArray[looper]= pow(anArray[looper],2);



}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
            ///Outputs the lowest value of an array
int lowVal (int anArray[], int size)
{
    int value = anArray[0];
    for (int looper = 1; looper < size; looper++)

        if (anArray[looper] < value)
        {
            value = anArray[looper];
        }
    return value;
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

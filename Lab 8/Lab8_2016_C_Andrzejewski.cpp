// Array of structs Lab - spring 2016
//   ArrayStructPracticelab.cpp

#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

struct avatar{
        int age;
        string fname;
        float lifeForce;
        char gender;
};

void printit (   const avatar [],  int );
void fill_it( avatar  anArray [],  int size );
void get_Names( avatar  anArray [],  int size, ifstream& inFile );

///print reverse prototype
void reversePrinter (const avatar [], int);

///Tally Prototype
void tally (avatar anArray [], int size, int targetage, ifstream& inFile);

///Player into prototype
void get_PlayerInfo ( avatar anArray [], int size, ifstream& inFile);

///Print player info prototype
void print_PlayerInfo (avatar anArray [], int size);

///Lowest value prototype
double lowVal (const avatar anArray [], int size);

int main()
{

    ifstream inFile;
    inFile.open("names.txt");
    if(!inFile){cout<<"\nfile input error - names.txt\n";
        return 1;       //exit the program
    };


    const int SIZE_ONE = 20;
    avatar list_one [SIZE_ONE];

    get_Names(list_one, SIZE_ONE, inFile);

     fill_it ( list_one,  SIZE_ONE );

     cout << "\nlist_one \n\n";
     printit ( list_one, SIZE_ONE );
            ///filling and printing list two
///================================
    const int SIZE_TWO = 20;
    avatar list_two [SIZE_TWO];

    get_Names(list_two, SIZE_TWO, inFile);
    fill_it(list_two, SIZE_TWO);
    cout << "\nlist_two\n\n";
    printit(list_two, SIZE_TWO);
///================================


///Calling Reverse Printer for list one and two
///======================================
    cout << "\nlist_one reverse\n\n";
    reversePrinter(list_one, SIZE_ONE);
    cout << "\nlist_two reverse\n\n";
    reversePrinter(list_two, SIZE_TWO);
///======================================



///Calling tally function based on input
///======================================

    for (int count=0; count <3; count++)
    {
        int searchAge;
        cout << "\nEnter a value for age - for the search tally: ";
        cin >> searchAge;
        tally (list_one, SIZE_ONE, searchAge, inFile);
    }
///======================================

///closing names.txt infile
    inFile.close();

///opening playerinfo infile
    inFile.open("playerInfo.txt");
    if(!inFile){cout<<"\nfile input error - playerInfo.txt\n";
        return 1;       //exit the program
    };


///Calling get player info and print function
///====================================
    get_PlayerInfo(list_two, SIZE_TWO, inFile);
    print_PlayerInfo(list_two, SIZE_TWO);
///====================================

///Outputting lowest lifeForce
///=====================================
    cout << "the player the lowest life force value in list_one is "
        << lowVal(list_one, SIZE_ONE) << endl << endl;
    cout << "the player with the lowest life force value in list_two is "
        << lowVal(list_two, SIZE_TWO) << endl << endl;
///=====================================


   inFile.close();
   cout << endl<< endl;
   return 0;
}
///end of main()
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// prints out the entries in an array
void printit ( const avatar  anArray [],  int size )
{
     int looper ;
     for (looper =0;looper <size;looper++)
            cout   <<  setw(5) <<anArray[looper].fname <<endl;

}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// fills an array with random numbers between 0 and 50, inclusive
void fill_it( avatar  anArray [],  int size )
{
    int num ;
    int looper;
    for ( looper = 0; looper < size ; looper++)  {
       num = (rand () + time (0) ) % 71;    //generate random age
       anArray[looper].age = num;

       anArray[looper].fname ="default";    // default initial value
       anArray[looper].lifeForce = 100;    // default initial value

        if((looper%2==1)&&(anArray[looper].age%2!=0))   //some logic to vary the outcome
       anArray[looper].gender = 'm';
        else
       anArray[looper].gender = 'f';
    }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// fills an array with avatars with the names from an input file.
//  the parameter size indicates the number of names in the file.
void get_Names( avatar  anArray [],  int size, ifstream& inFile )
{
    int num ;
    int looper;
    for ( looper = 0; looper < size ; looper++)   {
      inFile >> anArray[looper].fname;    //read, store value in the fname attribute
    }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

///Reverse Printing Function
///====================================
void reversePrinter ( const avatar  anArray [],  int size )
{
     int looper ;
     for (looper = size-1 ;looper >= 0;looper--)
            cout <<  setw(5) <<anArray[looper].fname <<endl;
}
///========================================

///Tally function
///========================================
void tally (avatar anArray [], int size, int targetage, ifstream& inFile)
{
    int tallycount = 0;
    for (int looper = 0; looper < size; looper++)
    {
        if (anArray[looper].age >= targetage)
        {
            tallycount++;
        }
    }
    cout << tallycount << endl;
}
///========================================

///Player info function
///=========================================
void get_PlayerInfo(avatar anArray [], int size, ifstream& inFile)
{
    for (int looper = 0; looper < size; looper++)
    {
        inFile >> anArray[looper].gender;
        inFile >> anArray[looper].lifeForce;
        inFile >> anArray[looper].fname;
        inFile >> anArray[looper].age;
    }
}
///========================================

///Print player info function
///========================================
void print_PlayerInfo (avatar anArray [], int size)
{
    cout << setfill('-') << setw(14) << right << " life Force "
        << setfill('-') << setw(14) << right <<" name "
        << setfill('-') << setw(14) << right <<" age "
        << setfill('-') << setw(14) << right <<" gender --" << endl;
    for (int looper =0; looper <size; looper++)
    {
        cout << setw(3) << setfill(' ') << left << " "
            << setw(8) << anArray[looper].lifeForce
            << setw(9) << " "
            << setw(18) << anArray[looper].fname
            << setw(11) << anArray[looper].age
            << setw(14) << anArray[looper].gender << endl ;
    }
    cout << "\n" <<setfill('-') << setw(57) << " " ;

}
///========================================

///Low Val function
///========================================
double lowVal (const avatar anArray[], int size)
{
    double lowest = anArray[0].lifeForce;
    for (int looper = 1; looper < size; looper++)
    {
        if (anArray[looper].lifeForce < lowest)
            lowest = anArray[looper].lifeForce;
    }
    return lowest;
}

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

    const int SIZE_TWO = 20;
    avatar list_two [SIZE_TWO];
    fill_it(list_two, SIZE_TWO);
    printit(list_two, SIZE_TWO);






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
            cout   <<  setw(5) <<anArray[looper].age<<endl;

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

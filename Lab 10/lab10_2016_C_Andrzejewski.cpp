//***********************************************************
// NAME:Chris Andrzejewski
// UIN:01008193
// Lab 07 - cs150 - spring 2016
// Program description: Lab Assignment 10 Classes
//
//
// File Name:  lab10_2016_C_Andrzejewski.cpp
// TA Name: Aida Ghazizadeh
// TA Email: aghaziza@cs.odu.edu
//***********************************************************
//

#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE_ONE = 20;
const int SIZE_TWO = 20;



class avatar{
        int age;
        string fname;
        float lifeForce;
        char gender;

    public:
        int getAge(){return age;};
        void setAge(int a){age =a;};
        string getName(){return fname;};
        void setName(string s){fname =s;};
        float getLifeForce(){return lifeForce;};
        void setLifeForce(float f){lifeForce = f;};
        char getGender(){return gender;};
        void setGender(char g){gender = g;};
};

void printNames ( avatar [],  int );
void revPrintNames ( avatar anArray [],  int size );
void printItAll ( avatar [],  int );
void initialize_it( avatar  anArray [],  int size );
void get_Names( avatar  anArray [],  int size, ifstream& inFile );
void fillFromFile( avatar  anArray [],  int size, ifstream& inFile );
void tally (avatar anArray [], int size, int searchage);
void get_PlayerInfo ( avatar  anArray [],  int size, ifstream& inFile );
void print_PlayerInfo (avatar anArray [], int size);
float lowVal (avatar anArray [], int size);

int main()
{

    int targetAge = 0;
    ifstream inFile;
    inFile.open("names.txt");
    if(!inFile){cout<<"\nfile input error - names.txt\n";
        return 1;       //exit the program
    };

    avatar list_one [SIZE_ONE];
    avatar list_two [SIZE_TWO];

    get_Names(list_one, SIZE_ONE, inFile);
     cout << "\nlist_one after getNames is called. \n\n";
     printNames ( list_one, SIZE_ONE );


    inFile.close();
    inFile.open("playerInfo2.txt");
    if(!inFile){cout<<"\nfile input error - names.txt\n";
        return 1;       //exit the program
    };

     fillFromFile( list_one,  SIZE_ONE, inFile );

     ///===============================
     /// Clearing eof flag and resetting to the beginning of the file to read to list two
     inFile.clear();
     inFile.seekg(0, ios::beg);
     ///===============================


     cout << "\nlist_one after Fill it is called. \n\n";
     printItAll ( list_one, SIZE_ONE );



   ///===========================================
    /// Initializing array two
    fillFromFile (list_two, SIZE_TWO, inFile);



    ///Printing array two

    cout << "\n\n\nPrinting List Two\n\n";
    printItAll (list_two, SIZE_TWO);
    ///===============================================

    ///================================================
    ///reverse printing
    cout << "\n\n Printing List One in REVERSE!\n\n";
    revPrintNames (list_one, SIZE_ONE);
    cout << "\n\n Printing List Two in REVERSE!\n\n";
    revPrintNames (list_two, SIZE_TWO);

    ///==========================================



   ///===========================================
   ///    Running tally function three times!
    for (int counter =0 ; counter <3; counter++)
    {

    cout << "\n\nEnter TARGET AGE : ";
    cin >> targetAge;
    tally (list_one, SIZE_ONE, targetAge);
    }
    ///==========================================



     ///===============================
     /// calling get player and print player
     inFile.clear();
     inFile.seekg(0, ios::beg);
     get_PlayerInfo(list_two, SIZE_TWO, inFile);
     print_PlayerInfo(list_two, SIZE_TWO);
    ///================================

    ///================================
    ///Lowest value function for list one and list two

    cout << "\n\nThe player with the lowest life force value in list one is: "
        << lowVal(list_one, SIZE_ONE) << endl << endl;
    cout << "\n\nThe player with the lowest life force value in list two is: "
        << lowVal(list_two, SIZE_TWO) << endl << endl;
    ///==================================

    inFile.close();


   cout << endl<< endl;
   return 0;
}
///end of main()
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// prints out the entries in an array
void printNames( avatar anArray [],  int size)
{
     int looper=0;
     for (looper =0; looper<size; looper++){

            cout   <<  setw(5) << anArray[looper].getName();
            cout   <<endl;
     }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// prints out the entries in an array
void printItAll( avatar anArray [],  int size)
{
     int looper=0;
     for (looper =0; looper<size; looper++){

        cout<<"Name: "<<setw(5)<<anArray[looper].getName()<<"\tAge= ";
        cout<<anArray[looper].getAge()<<"\t\tGender= ";
        cout<<anArray[looper].getGender()<<"\tLife= ";
        cout<<anArray[looper].getLifeForce()<<"\n";

     }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// fills an array with random numbers between 0 and 50, inclusive
void initialize_it( avatar  anArray [],  int size )
{
    int num =0;
    int looper;
    for ( looper = 0; looper < size ; looper++)  {
       anArray[looper].setAge(num);
       anArray[looper].setName("default");    // default initial value
       anArray[looper].setLifeForce(100);    // default initial value
        if((looper%2==1)&&(anArray[looper].getAge()%2!=0))   //some logic to vary the outcome
       anArray[looper].setGender('m');
        else
       anArray[looper].setGender('f');
    }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// fills an array with avatars with the names from an input file.
//  the parameter size indicates the number of names in the file.
void get_Names( avatar  anArray [],  int size, ifstream& inFile )
{
    int looper=0;
    string temp;
    for ( looper = 0; looper < size ; looper++)   {
      inFile >> temp;
      anArray[looper].setName(temp);    //read, store value from file
    }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
// fills an array with data from the input file stream
        ///     stopped    here

void fillFromFile( avatar  anArray [],  int size, ifstream& inFile )
{
    int num=0, looper=0;
    string name;
    char gender;
    float life;
    int age;

    for ( looper = 0; looper < size ; looper++)  {
        inFile >> gender;
          anArray[looper].setGender(gender);
        inFile >> life;
          anArray[looper].setLifeForce(life);
        inFile >> name;
          anArray[looper].setName(name);
        inFile >> age;
          anArray[looper].setAge(age);
    }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

void revPrintNames ( avatar anArray [],  int size )
{
     int looper=0;
     for (looper = size-1; looper>=0; looper--){

            cout   << anArray[looper].getName();
            cout   <<endl;
     }
}

///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
void tally (avatar anArray [], int size, int searchage)
{
    int count = 0;

    for(int loop=0; loop < size ; loop++)
    {
        if (anArray[loop].getAge() >= searchage)
            count++;
    }
    cout << "\n\nThere are " << count << " ages equal or greater to " << searchage << ".\n";

}

///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

void get_PlayerInfo ( avatar  anArray [],  int size, ifstream& inFile )
{
    string name;
    char gender;
    float life;
    int age;

    for (int loop = 0; loop < size; loop++)
    {
        inFile >> gender;
        anArray[loop].setGender(gender);
        inFile >> life;
        anArray[loop].setLifeForce(life);
        inFile >> name;
        anArray[loop].setName(name);
        inFile >> age;
        anArray[loop].setAge(age);
    }
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
void print_PlayerInfo (avatar anArray [], int size)
{

    cout << "\n--------------------------------------------------------\n";
    cout << "\n-- life force ----- name -------- age ---- gender --\n";

     for (int looper =0; looper<size; looper++){
        cout << setw(10) << anArray[looper].getLifeForce() <<"\t";
        cout << setw(10) << anArray[looper].getName() <<"\t";
        cout << setw(5) << anArray[looper].getAge() <<"\t";
        cout << setw(5) << anArray[looper].getGender() <<endl;

     }
    cout << "--------------------------------------------------------\n";

}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
float lowVal (avatar anArray [], int size)
{
    float lowest = anArray[0].getLifeForce();

    for (int looper =1; looper < size; looper++)
    {
        if (anArray[looper].getLifeForce() < lowest)
            lowest = anArray[looper].getLifeForce();
    }
    return lowest;
}

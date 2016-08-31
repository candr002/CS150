// full programmer info here, or lose 25% of your grade.

// Array of classes Lab - spring 2016
//   ArrayClassesPracticelab.cpp

#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE_ONE = 20;

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
void printItAll ( avatar [],  int );
void initialize_it( avatar  anArray [],  int size );
void get_Names( avatar  anArray [],  int size, ifstream& inFile );
void fillFromFile( avatar  anArray [],  int size, ifstream& inFile );

int main()
{
    ifstream inFile;
    inFile.open("names.txt");
    if(!inFile){cout<<"\nfile input error - names.txt\n";
        return 1;       //exit the program
    };

    avatar list_one [SIZE_ONE];

    get_Names(list_one, SIZE_ONE, inFile);
     cout << "\nlist_one after getNames is called. \n\n";
     printNames ( list_one, SIZE_ONE );

    inFile.close();
    inFile.open("playerInfo2.txt");
    if(!inFile){cout<<"\nfile input error - names.txt\n";
        return 1;       //exit the program
    };

     fillFromFile( list_one,  SIZE_ONE, inFile );

     cout << "\nlist_one after Fill it is called. \n\n";
     printItAll ( list_one, SIZE_ONE );





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

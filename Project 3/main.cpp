#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int difficulty = 0;
    ifstream inFile;
    string openfile, stuff;


    cout << "\nEnter difficulty : ";
    cin >> difficulty;
    cout << "\nYou chose " << difficulty ;

   /* for (bool answer=0; answer =1 ; )
    {
        if (difficulty >=1 and difficulty <=3)
        {
            answer++;
        }
        else {
            cout << "\nEnter difficulty : ";
            cin >> difficulty;
            cout << "\nYou chose " << difficulty ;
            }
    }*/
        switch (difficulty)
        {
        case 1:
            openfile = "questions1.txt";
            break;
        case 2:
            openfile = "questions2.txt";
            break;
        case 3:
            openfile = "questions3.txt";
            break;
        }
   inFile.open (openfile.c_str());
   if (!inFile)
   {
       cerr << "Shit man";
       return 1;
   }
    inFile>> stuff;
    cout << stuff;

    inFile.close();
    return 0;
}

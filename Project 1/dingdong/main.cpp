#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


using namespace std;
void logo();
void AdjustedCalc();
const float SCORE_ADJUST = 6.975;     //used to calc adjusted average
                                    //see formula on project 1 assignment
int main()
{
    logo();
    //variable declarations

    string FullName,
        PlayerAlias,
        Date;

    char Gender;

    int PlayerID,
        GameLevel = 0,
        TotalLevelOnePlays = 0,
        TotalLevelTwoPlays = 0,
        TotalGameCount = 0,
        gamesum = 0;

    double Score = 0,
        AverageScore = 0,
        AverageAdjustedScore = 0;


     //Collecting Player data (Full Name, Alias, Gender and Player ID)

    cout << "\n--------------------------------------";
    cout << "\nEnter full name: ";
    getline(cin, FullName);
    cout <<"Enter game \"alias\": ";
    cin >> PlayerAlias;
    cout << "Enter Gender: ";
    cin >> Gender;
    cout << "Enter player ID: ";
    cin >> PlayerID;

    // declare, open, and validate the I/O file streams
    string gameDataInput,
            gameDataOutput;
    ifstream inFile;
    ofstream outFile;

    /*Was having issues with getline working properly at this point.
    My code was running without errors, but would completely skip
    the second getline command and spit out an error for !inFile.
    After some research, flushing the input with cin.clear() and
    cin.sync() got it working properly.*/


    cin.clear(); //flushing input buffer
    cin.sync();
    cout << "Enter input file name: ";
    getline(cin, gameDataInput); //Pulling file name for input
    inFile.open(gameDataInput.c_str());  //Opening input file
    outFile.open("gameDataOutput.txt"); //Opening output file

    if (!inFile){       //Infile validation
        cerr << "\n\nError in opening the input file.\n" ;
        return 1;
        } //End of infile validation


    //Output of initial data to monitor
    cout << "\n--------------------------------------\n";
    cout << "Full Name: " << FullName << endl;
    cout << "Alias: \"" << PlayerAlias << "\"" << endl ;
    cout << "Gender: " << Gender << "\tID: " << PlayerID << endl;
    cout << "Input File: " << gameDataInput << endl ;
    cout << "\n--------------------------------------\n";

    // Output of initial data to output file
    outFile << "\n--------------------------------------\n";
    outFile << "Full Name: " << FullName << endl;
    outFile << "Alias: \"" << PlayerAlias << "\"" << endl ;
    outFile << "Gender: " << Gender << "\tID: " << PlayerID << endl;
    outFile << "Input Name: " << gameDataInput << endl ;
    outFile << "\n--------------------------------------\n";

    //Setting headers for output table
    cout << setw(10) << left << " Date"
         << setw(12) << right << "Level"
         <<setw(9) << right << "Score\n";


    //loop until eof, TotalGameCounting and summing
    //"Priming" loop was causing issues reading and calculating all lines of input

    inFile >> Date >> GameLevel >> Score ;

    while (!inFile.eof()){
        //Pulling game instance data

        TotalGameCount++ ;

        //If/Else statement to keep track of total level plays
        if (GameLevel == 1){
            TotalLevelOnePlays++;
        }

        else {TotalLevelTwoPlays++;}
        //Tracking total points
        gamesum = gamesum + Score ;

        //Outputting game instance data to monitor
        cout << fixed << showpoint << setprecision(3)
            << Date
            << setw(8) << right << GameLevel
            << setw(12) << right << Score << endl ;
        cin.clear();
        cin.sync();
        inFile >> Date >> GameLevel >> Score ;
    }
    cout << "\n--------------------------------------\n\n\n\n\n";
    //Calculating average score of all games played
    AverageScore = gamesum / TotalGameCount ;

    //Calculating adjusted average score based on provided formula
    AverageAdjustedScore =
        sqrt((AverageScore/TotalLevelTwoPlays)* (pow(SCORE_ADJUST, 3)));


    //Outputting final game data to output file
    outFile << "Games played: " << TotalGameCount << endl
            << "\tLev 1: " << TotalLevelOnePlays << endl
            << "\tLev 2: " << TotalLevelTwoPlays << endl
            << "Average Score: " << fixed << showpoint << setprecision(3) <<  AverageScore << endl
            << "Avg Adj Score: " << AverageAdjustedScore << endl;
    outFile << "\n--------------------------------------\n";

    //Closing input and output files
    inFile.close();
    outFile.close();

    return 0;
}
//====endOfMain()================================)
void logo()
    {cout <<"  Project_1:  Tribble_Pursuit\n";}


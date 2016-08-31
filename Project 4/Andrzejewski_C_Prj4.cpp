//***********************************************************
// NAME:Chris Andrzejewski
// UIN:01008193
// Project 4 - cs150 - spring 2016
// Program description: Project 4 "Questions Game"
//
//
// File Name:  Andrzejewski_C_Prj2.cpp
// TA Name: Aida Ghazizadeh
// TA Email: aghaziza@cs.odu.edu
//***********************************************************


//=====================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const float DIFF_LEVEL_ONE = 1.23;
const float DIFF_LEVEL_TWO = 1.51;
const float DIFF_LEVEL_THREE = 2.02;
const int MAX_NUM_QUESTIONS = 15;
//----------------------------------------------
struct playerHistory
{
    string date;
    int difficulty;
    float score;
    string alias1;
};
//----------------------------------------------
struct gameQuestion
{
    string question;
    char answer;
    string ans1;
    string ans2;
    string ans3;
    string ans4;
};
//----------------------------------------------
/// The function "entryCount" returns the number of entries in the input file
/// The function "buildHistory" builds an array of the size that "entryCount" returns
/// The function "infileReset" uses .clear() and .seekg to clear the EOF flag on the file
///     and return to the beginning of the infile rather that having to open and close it
/// The Function "welcomeMsg" is just that. It is the message that appears at the beginning
///     of the game. it also calls "printTopScores"
/// The function "sortHistory" sorts the game history array in descending order
/// The function "printTopScores" prints the top game scores through whatever integer it is given
///     functionality was also added  that if the requested number of scores is more than the total array
///     size, it returns the entire sorted array.
void gameInfo();
char menu();
int entryCount (ifstream& inHistory);
void buildHistory (ifstream& inHistory,playerHistory anArray [], int list_size);
void infileReset (ifstream& inHistory);
void welcomeMsg(ifstream& inHistory, playerHistory anArray[], bool tORf, int list_size);
void printTopScores (playerHistory anArray [], int playerCount, bool tORf, int list_size);
void getQuestion(gameQuestion qBank[], int loopy, ifstream& inQuest);
void gameResults(string alias1, string alias2, double score1, double score2);
void gameResults(string alias1, double score1);
void upDateScore(int difficulty, int loopy, double& score1, double& score2);
void upDateScore(int difficulty, int loopy, double& score1);
void sortHistory (playerHistory anArray[], int listSize);

//----------------------------------------------
int main()
{
    bool menuSelect = false;
    int difficulty=3;
    int entryTotal =0;
    char solution;  //read and store the question solution
    char userChoice;     //store user provided solution to questions
    char next;      //input to pause between questions
    string date = "\"Mar/2/2016\"";
    string question, ans1,ans2,ans3,ans4;
    string temp;    //store the answer,as a string initially
    string alias1="codeJockey", alias2="codeRival";
    string alias1FileName, alias2FileName;
    string gameHistory = "gameHistory.txt";
    int numQuestions=4, posSolutions=4;
    double score1 =0, score2=0, totalScore =0;
    ifstream inQuest;
    ofstream outFile1, outFile2, outFile3;
    char menuChoice;

/// Welcome Message and displaying top 3 scores in game history
///=========================================================================
    ifstream inHistory;
    inHistory.open("gameHistory.txt");
        if(!inHistory)
        {
            cerr << "Error Opening Game History!!";
            return 1;
        }
    entryTotal = entryCount(inHistory);
    playerHistory historyDB [entryTotal];
    buildHistory(inHistory, historyDB,entryTotal);
    sortHistory(historyDB, entryTotal);
    welcomeMsg(inHistory, historyDB, menuSelect, entryTotal);
    inHistory.close();
///=========================================================================



//-------------------------------------------
    gameQuestion qBank[MAX_NUM_QUESTIONS];
    menuChoice = menu();
    while(menuChoice !='1' ||
            menuChoice !='2' ||
            menuChoice !='3'||
            menuChoice !='4')
    {
    // process the validated choice
    if(menuChoice == '4')  {
        cout <<"\nExiting.\n";
        return 0;
        }
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
    else if(menuChoice == '3')  {
            menuSelect = true;

/// Displaying top 10 scores in game history
///=========================================================================
        ifstream inHistory;
        inHistory.open("gameHistory.txt");
            if(!inHistory)
            {
                cerr << "Error Opening Game History!!";
                return 1;
            }
        cout << "\n\n====================================================\n\n";
        cout << "TOP TEN SCORES:\n\n";
        entryTotal = entryCount(inHistory);
        playerHistory historyDB [entryTotal];
        buildHistory(inHistory, historyDB,entryTotal);
        sortHistory(historyDB, entryTotal);
        printTopScores(historyDB, 10, menuSelect, entryTotal);
        cout << "\n\n====================================================\n\n";

        inHistory.close();
///=========================================================================
        }
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
    else if(menuChoice == '2')  {
        score1 = score2 =0;     //initialize to zero every new play
        cout <<"\nTWO PLAYER!\n";
        cout <<"Enter the date(example \"Feb/18/2016\"): ";
        cin >> date;
        cout <<"Enter your game alias(example \"codeDog\"): ";
        cin >> alias1;

        alias1FileName = alias1;
        alias1FileName = alias1FileName.append(".txt");
        outFile1.open(alias1FileName.c_str(), ios::app);
        if(!outFile1)  {
            cout <<"Output file ERROR!!\n\n";
            return 0;  }
        cout <<"Enter the 2nd game alias1: ";
        cin >> alias2;

        alias2FileName = alias2;
        alias2FileName = alias2FileName.append(".txt");
        outFile2.open(alias2FileName.c_str(), ios::app);
        if(!outFile2)  {
            cout <<"Output file ERROR!!\n\n";
            return 0;  }
        outFile3.open(gameHistory.c_str(), ios::app);
        if(!outFile2)  {
            cout <<"Output file ERROR!!\n\n";
            return 0;  }
    //================================================
        cout <<"Three questions each: ";
        numQuestions=6;
    //--------------------------------------------
        cout <<"Enter difficulty level: (1,2,3): ";
        cin >>difficulty;
        if(difficulty == 1)  {
            inQuest.open("questions1.txt");
            if(!inQuest)  {
                cout <<"\nERR-opening question file 1.\n";
                return 1;  }
            }
    //-------------------------------------------
        else if(difficulty == 2)  {
            inQuest.open("questions2.txt");
            if(!inQuest)  {
                cout <<"\nERR-opening question file 2.\n";
                return 1;  }
            }
    //-------------------------------------------
        else if(difficulty == 3){
            inQuest.open("questions3.txt");
            if(!inQuest){
                cout <<"\nERR-opening question file3.\n";
                return 1;}
            }
    //-------------------------------------------
        else{
            cout <<"\nInvalid difficulty level! Try again later.\n";
            return 0;  }
    //-------------------------------------------
        for(int loopy=1; loopy<=numQuestions+1; loopy++){

            getQuestion(qBank, loopy, inQuest);

    //------------------------------------------
            if(loopy%2 !=0)
                cout <<"\nPlayer ONE:";
            else
                cout <<"\nPlayer TWO";

            cout <<"\nQuestion ("<<loopy+1<<")\n"<<qBank[loopy].question<<"\n\n";
            cout <<"A) "<<qBank[loopy].ans1<<"\nB) "<<qBank[loopy].ans2<<"\nC) "<<qBank[loopy].ans3<<"\nD) "<<qBank[loopy].ans4;
            cout <<"\n Enter your choice: ";
            cin >> userChoice;
            userChoice = toupper(userChoice);
            cout <<"\nYou chose: "<<userChoice;
        //-------------------------------------------
            if(userChoice == qBank[loopy].answer){
                upDateScore(difficulty, loopy,score1, score2);
                cout <<"\tCORRECT!  score P1= "<<score1<<", P2= "<<score2;}
            else
                cout <<"\nSolution: "<<qBank[loopy].answer<<"\tGuess: "<<userChoice;
        //--------------------------------------------------
            cout <<"\nenter any char to continue:";
            cin >>next;
            cout <<"----------------------------------------\n\n";
            }   ///end of for loop of number of questions
    //-----------------------------------------------------
        gameResults(alias1, alias2, score1, score2);

        outFile1 <<date<<"\t"<<difficulty<<"\t"<<score1<<"\n";
        outFile2 <<date<<"\t"<<difficulty<<"\t"<<score2<<"\n";
        outFile3 <<alias1<<"\t"<<score1<<"\t"<<difficulty<<"\t"<<date<<"\n";
        outFile3 <<alias2<<"\t"<<score2<<"\t"<<difficulty<<"\t"<<date<<"\n";

        cout <<"\n\n\n\n";
        inQuest.close();
        outFile1.close();
        outFile2.close();
        outFile3.close();
    } ///end of menu option 2
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
    else if(menuChoice == '1')
        {
         score1=0;
         cout <<"Enter the date(example \"Feb/18/2016\"): ";
         cin >> date;
         cout <<"Enter your game alias(example \"codeDog\"): ";
         cin >> alias1;
         alias1FileName = alias1;
         alias1FileName = alias1FileName.append(".txt");
         outFile1.open(alias1FileName.c_str(), ios::app);
         if(!outFile1)
            {
            cout <<"Output file ERROR!!\n\n";
            return 0;  }
        //------------------------------
        outFile3.open(gameHistory.c_str(), ios::app);
        if(!outFile2)
            {
            cout <<"Output file ERROR!!\n\n";
            return 0;  }
        //------------------------------
        do
            {
             cout <<"How many questions? ( 1 - 15 ): ";
             cin >>numQuestions;
            }
       while(numQuestions > 15 || numQuestions < 1);
    //--------------------------------------------
        cout <<"Enter difficulty level: (1,2,3): ";
        cin >>difficulty;
        if(difficulty == 1)
          {
            inQuest.open("questions1.txt");
            if(!inQuest)  {
                cout <<"\nERR-opening question file 1.\n";
                return 1;   }
          }
    //-------------------------------------------
        else if(difficulty == 2)
          {
            inQuest.open("questions2.txt");
            if(!inQuest)  {
                cout <<"\nERR-opening question file 2.\n";
                return 1;   }
          }
    //------------------------------------------
        else if(difficulty == 3)
          {
            inQuest.open("questions3.txt");
            if(!inQuest)  {
                cout <<"\nERR-opening question file3.\n";
                return 1;   }
           }
    //-------------------------------------------
        else
           {
            cout <<"\nInvalid difficulty level! Try again later.\n";
            return 0;    }
    //-------------------------------------------
        for(int loopy=0; loopy<numQuestions; loopy++)  {
            getQuestion(qBank, loopy, inQuest);
        //------------------------------------------
            cout <<"\nQuestion ("<<loopy+1<<")\n"<<qBank[loopy].question<<"\n\n";
            cout <<"A) "<<qBank[loopy].ans1<<"\nB) "<<qBank[loopy].ans2<<"\nC) "<<qBank[loopy].ans3<<"\nD) "<<qBank[loopy].ans4;

            cout <<"\n Enter your choice: ";
            cin >> userChoice;
            userChoice = toupper(userChoice);
            cout <<"\nYou chose: "<<userChoice;
        //-------------------------------------------
            if(userChoice == qBank[loopy].answer)  {
                upDateScore(difficulty, loopy,score1, score2);
                }
            else
                cout <<"\nSolution: "<<qBank[loopy].answer<<"\tGuess: "<<userChoice;
        //--------------------------------------------------
            cout <<"\nenter any char to continue:";
            cin >>next;
            cout <<"----------------------------------------\n\n";
            }   ///end of for loop of number of questions
    //-----------------------------------------------------

        gameResults(alias1, score1);

        outFile1 <<date<<"\t"<<difficulty<<"\t"<<score1<<"\n";
        outFile3 <<alias1<<"\t\t"<<score1<<"\t"<<difficulty<<"\t"<<date<<"\n";

        cout <<"\n\n\n\n";
        inQuest.close();
        outFile1.close();
        outFile2.close();
        outFile3.close();
        }//end of menuChoice 1

        menuChoice = menu();
    } //end of while (menu)

    return 0;
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
///=-=-=-=-=- end of main =-=-=-=-=-=-=-=-=-=-=-=
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.

void gameInfo()
{
    cout <<"\n------------ About the Game ----------------------------------";
    /*
    cout <<"\n\n The game begins by prompting for the user information\n";
    cout <<" (the date and user game alias1). The user game alias1\n";
    cout <<" is used as the name of the user game score history output\n";
    cout <<" file. Format of this output file is same as the sample input\n";
    cout <<" files for project 1, and output for project 2. The user is asked\n";
    cout <<" for the number of questions and the difficulty level of the\n";
    cout <<" game. If the number of questions entered by the user is not\n";
    cout <<" within the specified acceptable range (1-15), then the user is\n";
    cout <<" repeatedly prompted until a valid value is entered. If the difficulty\n";
    cout <<" level entered by the user is not within the acceptable\n";
    cout <<" range (1-3), an error msg is displayed and the program terminates.\n";
    cout <<" A running score is calculated, displayed, and written to each\n";
    cout <<" userHistory.txt output file at game end. The contents\n";
    cout <<" of the gameHistory.txt file is appended with the latest game\n";
    cout <<" results for each new player results.\n";
    cout <<" sorted results are written to the gameHistory.txt output file.\n";
    cout <<"Some of the new to this version:\n";
    cout <<" - gameHistory.txt contains game info for all users sorted by score.\n";
    cout <<" - User history is stored for both users in two-player mode.\n";
    cout <<" - Game options are presented with a menu of 4 options.\n";
    */
    cout <<"Play the game and look at your project directory.\nExamine the files";
    cout <<" that are created. A game history file. User history files.";
    cout <<"----------------------------------------------------------------\n\n";
};
//===============================================
char menu()
{
    char choice;

    cout <<"Enter";
    cout <<"\n  1  (single play)";
    cout <<"\n  2  (two player)";
    cout <<"\n  3  (game info)";
    cout <<"\n  4  (exit)\n";



    cin >> choice;
    return choice;

};
//===============================================
void gameResults(string alias1, string alias2, double score1, double score2){
        cout <<"\nGame Results!";
        cout <<"\n  "<<alias1<<" = "<<score1<<" pts.";
        cout <<"\n  "<<alias2<<" = "<<score2<<" pts.";
        if(score1 > score2)
            cout <<"\n"<<alias1<<" wins!";
        else if(score2 > score1)
            cout <<"\n"<<alias2<<" wins!";
        else
            cout <<"\nIt's a tie!";
}
//===============================================
void gameResults(string alias1, double score1){
        cout <<"\nGame Results!";
        cout <<"\n  "<<alias1<<" = "<<score1<<" pts.";
}
//===============================================
void upDateScore(int difficulty, int loopy, double& score1, double& score2){
    if((difficulty == 1) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_ONE;     }
    else if((difficulty == 2) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_TWO;     }
    else if((difficulty == 3) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_THREE;   }
//---------player 2---------------------------
    else if((difficulty == 1) && (loopy%2 ==0)){
            score2 += DIFF_LEVEL_ONE;     }
    else if((difficulty == 2) && (loopy%2 ==0)){
            score2 += DIFF_LEVEL_TWO;     }
    else if((difficulty == 3) && (loopy%2 ==0)){
            score2 += DIFF_LEVEL_THREE;   }
}
//===============================================
void upDateScore(int difficulty, int loopy, double& score1) {
    if((difficulty == 1) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_ONE;     }
    else if((difficulty == 2) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_TWO;     }
    else if((difficulty == 3) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_THREE;   }
}
//===============================================
void getQuestion(gameQuestion qBank[], int loopy, ifstream& inQuest){
    string temp;
    getline(inQuest, qBank[loopy].question, '\n');   //get question
    getline(inQuest, temp, '\n');        //get the answer
    qBank[loopy].answer = temp[0];     //pull the character out
    getline(inQuest, qBank[loopy].ans1); //get the four choices
    getline(inQuest, qBank[loopy].ans2);
    getline(inQuest, qBank[loopy].ans3);
    getline(inQuest, qBank[loopy].ans4);
}

///=========================================================================
void welcomeMsg(ifstream& inHistory, playerHistory anArray[], bool tORf, int list_size)
{
    cout << "\n\n====================================================\n\n";
    cout << "\nWelcome to the QUESTIONS GAME!!"
            <<"\nHere are the current THREE TOP SCORES:\n\n";
    printTopScores(anArray, 3, tORf, list_size);
    cout << "\n\n====================================================\n\n";

}
///=========================================================================



///=========================================================================
void printTopScores (playerHistory anArray [], int playerCount, bool tORf, int list_size)
{
    if (playerCount > list_size)
    {
        playerCount = list_size;
    }
  float scoreSum =0, scoreAvg=0;

       for (int looper = 0; looper < playerCount; looper++)
        {
            if (tORf == true)
            {
             scoreSum = scoreSum+anArray[looper].score;
            }
        cout << setw(12) << anArray[looper].alias1 << "\t"
                << anArray[looper].score << "\t"
                << anArray[looper].date << endl;
        }
        if (tORf == true)
            {
            scoreAvg = scoreSum/playerCount;
            cout << "\n\nThe AVERAGE score for the top " << playerCount << " players: "
                << fixed << showpoint << setprecision(2) << scoreAvg
                << " per game.\n\n";
            }
}
///=========================================================================



///=========================================================================
int entryCount (ifstream& inHistory)
{
int counter = 0;
    infileReset(inHistory);
    playerHistory temp;

    inHistory >> temp.alias1
        >> temp.score
        >> temp.difficulty
        >> temp.date;
    counter++;


    while (!inHistory.eof())
        {
        inHistory >> temp.alias1
                >> temp.score
                >> temp.difficulty
                >> temp.date;
        counter++;
        }
    infileReset(inHistory);
    return counter;
}
///=========================================================================

///=========================================================================
void infileReset (ifstream& inHistory)
{
    inHistory.clear();

    inHistory.seekg(0,ios::beg);
}
///=========================================================================

///=========================================================================
void buildHistory(ifstream& inHistory, playerHistory anArray [], int list_size)
{
    infileReset(inHistory);
    inHistory >> anArray[0].alias1
                >> anArray[0].score
                >> anArray[0].difficulty
                >> anArray[0].date;

    for (int looper = 1; looper < list_size; looper++)
        {
         inHistory >> anArray[looper].alias1
                    >> anArray[looper].score
                    >> anArray[looper].difficulty
                    >> anArray[looper].date;
        }
    infileReset(inHistory);
}
///=========================================================================

///=========================================================================
void sortHistory (playerHistory anArray[], int listSize)
{

    playerHistory temp;

    for (int looper = 1; looper < listSize ; looper++)
        {
        for (int loop = 0; loop < listSize - looper ; loop++)
            {
            if (anArray[loop].score < anArray[loop+1].score)
                {
                temp = anArray[loop];
                anArray[loop] = anArray[loop+1];
                anArray[loop+1] = temp;
                }
            }
        }
}
///=========================================================================

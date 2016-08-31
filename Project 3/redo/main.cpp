//***********************************************************
// NAME:Chris Andrzejewski
// UIN:01008193
// Project 3- cs150 - spring 2016
// Program description: Two Player Option for Game Rojecgt
//
//
// File Name:  Andrzejewski_C_Prj3.cpp
//***********************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const float DIFF_LEVEL_ONE = 1.23;
const float DIFF_LEVEL_TWO = 1.51;
const float DIFF_LEVEL_THREE = 2.02;
const int MAX_NUM_QUESTIONS = 15;
//----------------------------------------------
struct gameQuestion
{
    string question;
    string answer;
    string ans1;
    string ans2;
    string ans3;
    string ans4;
};


///Function Prototypes
///----------------------------------------------
void gameInfo();
char menu();
void getQuestion(gameQuestion qbank [], int maxQuestNum, ifstream& inQuest);
void gameResults(string alias1, string alias2, double score1, double score2);
void gameResults(string alias1, double score1);
void upDateScore(int difficulty, int loopy, double& score1, double& score2);
void upDateScore(int difficulty, int loopy, double& score1);
void printQuestion(gameQuestion qbank [], int indexer);
char evaluateQuestion(gameQuestion qbank [], int indexer, char playerAnswer);
///----------------------------------------------
int main ()
{

  ///Declaring Variables
///-------------------------------------------
    int difficulty=3;
    char trueORfalse;  //read and store the question solution
    char userChoice;     //store user provided solution to questions
    char next;      //input to pause between questions    cout << "\nEnter difficulty : ";
    int listSize;
    cout << "\nYou chose " << difficulty ;
    string date = "\"Mar/2/2016\"";
    string question, ans1,ans2,ans3,ans4;
    string temp;    //store the answer,as a string initially
    string alias1="codeJockey", alias2="codeRival";
    string alias1FileName, alias2FileName;
    string gameHistory = "gameHistory.txt";
    string questionFile;
    int numQuestions=4, posSolutions=4;
    double score1 =0, score2=0, totalScore =0;
    ifstream questionIn;
    ifstream inHistory;
    ofstream outFile1, outFile2, outFile3;
    int menuChoice;

    gameQuestion questbank[MAX_NUM_QUESTIONS];
///-------------------------------------------



            ///Initiating and validating menu selection
///-------------------------------------------
    int correctResponse =0;
    do
    {
        switch (menuChoice)
        {
            case '1' :;
            case '2' :;
            case '3' :;
            case '4' :
                correctResponse++;
                break;
            default:
                    menuChoice = menu();

        }
    }
    while (correctResponse != 1);

///-------------------------------------------


        ///Menu selection 4
///-------------------------------------------
    if(menuChoice == '4')
    {
        cout <<"\nExiting.\n";
        return 0;
    }
///-------------------------------------------


        ///Menu 3 Selection
///-------------------------------------------
        else if(menuChoice == '3')
    {
        gameInfo();
    }
///-------------------------------------------


        ///Menu Selection 2
///-------------------------------------------
     else if(menuChoice == '2')
{
    //initialize to zero every new play
    cout <<"\nTWO PLAYER!\n";

    //prompt for date and alias 1, and alias 2
    cout << "\nPlease enter the current date (Ex. Mar/2/2016): ";
    cin >> date;
    cout << "\nPlease enter Player 1's alias: ";
    cin >> alias1;
    cout << "\nPlease enter Player 2's alias: ";
    cin >> alias2;

    // open and validate user history files
    alias1FileName = alias1.append(".txt");
    alias2FileName = alias2.append(".txt");
    inHistory.open(gameHistory.c_str(), ios::app);
    outFile1.open(alias1FileName.c_str(), ios::app);
    outFile2.open(alias2FileName.c_str(), ios::app);
    if (!inHistory)
        {
        cout << "\nError opening Game History file \"" << gameHistory <<"\"\n";
        return 1;
        }

    if (!outFile1)
    {
        cout << "\nError opening " << alias1FileName ;
        return 1;
    }
    if (!outFile2)
    {
        cout << "\nError opening " << alias2FileName ;
        return 1;
    }
//================================================
    cout <<"Three questions each: ";
    numQuestions=6;
//--------------------------------------------
    cout <<"\nEnter difficulty level: (1,2,3): ";
        cin >> difficulty;
    int happyanswer = 0;
    while (happyanswer != 1)
    {
        if((difficulty < 1) or (difficulty > 3))
        {
            cout <<"\nEnter difficulty level: (1,2,3): ";
            cin >> difficulty;
        }
        else if ((difficulty >= 1) and (difficulty <=3 ))
        {
            happyanswer++;
        }
    }

    switch(difficulty)
    {
        case 1:
            questionFile = "questions1.txt" ;
            break;
        case 2:
            questionFile = "questions2.txt" ;
            break;
        case 3:
            questionFile = "questions3.txt" ;
            break;
    }


    cout << "The file you are trying to open is : "<< questionFile << endl;
    questionIn.open(questionFile.c_str());

    if (!questionIn)
        {
        cout << "\nError opening output file \"" << questionFile << "\"\n" ;
        return 1;
        }


///*************************************************************
///*************************************************************
///*************************************************************
///*************************************************************
//-------------------------------------------
    // loop, and use
    // the getQuestion function to load array.
    getQuestion( questbank , MAX_NUM_QUESTIONS, questionIn);

/*     for (int looper = 0 ; looper < numQuestions; looper++)
     {
        if (looper % 2 == 0)
        {
            cout << alias2 << ", your question is:\n";
            printQuestion(questionBank, looper);
        }
        else
        {
            cout << alias1 << ", your question is:\n";
            printQuestion(questionBank, looper);
        }
        cin >> userChoice;
        trueORfalse = evaluateQuestion(questionBank, looper, userChoice);

        if (trueORfalse == 'T')
            {upDateScore(difficulty, looper, score1, score2);   }

        if (looper % 2 == 0)
            { cout <<"\nPlayer TWO";  }
        else
            { cout <<"\nPlayer TWO";  }


        cout <<"\nenter any char to continue:";
        cin >>next;
        cout <<"----------------------------------------\n\n";
     }

/*
    //display game results
    gameResults(alias1, alias2, score1, score2);

    // write output to user history files
    // write output to game history files
*/
    cout <<"\n\n\n\n";
    inHistory.close();
    questionIn.close();
    outFile1.close();
    outFile2.close();
    outFile3.close();
  } ///end of menu option 2
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
///-------------------------------------------

}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
///=-=-=-=-=- end of main =-=-=-=-=-=-=-=-=-=-=-=

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
    cout <<"\n\nPlay the game and look at your project\ndirectory.Examine the files";
    cout <<" that are created including\n a game history file and user history files.";
    cout <<" \nRead through the source code, and study what functions\n";
    cout <<" and code are provided already. You should study the\n";
    cout <<" the solution to project 2 that we reveiwed in lecture.\n\n";
    cout <<" There is a game description in this function, that is commented out.\n\n";
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

//implement the logic
            cout <<"\n"<<alias1<<" wins!";
            cout <<"\n"<<alias2<<" wins!";
            cout <<"\nIt's a tie!";
}
//===============================================
void gameResults(string alias1, double score1){
        cout <<"\nGame Results!";
        cout <<"\n  "<<alias1<<" = "<<score1<<" pts.";
}
//===============================================
void upDateScore(int difficulty, int loopy, double& score1, double& score2){
    if (loopy % 2 == 0)
    {
        if((difficulty == 1) && (loopy%2 !=0))
            {  score2 += DIFF_LEVEL_ONE;     }
    else if((difficulty == 2) && (loopy%2 !=0))
           {  score2 += DIFF_LEVEL_TWO;     }
    else if((difficulty == 3) && (loopy%2 !=0))
            { score2 += DIFF_LEVEL_THREE;   }
    }
    if((difficulty == 1) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_ONE;     }
    else if((difficulty == 2) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_TWO;     }
    else if((difficulty == 3) && (loopy%2 !=0)){
            score1 += DIFF_LEVEL_THREE;   }
// implement the logic for this 'overloaded' function

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
void getQuestion(gameQuestion qbank [], int maxQuestNum, ifstream& inQuest)
{
    for (int loopy = 0; loopy < maxQuestNum ; loopy++)
    {
        getline(inQuest, qbank[loopy].question);//get question
        getline(inQuest, qbank[loopy].answer);        //get the answer
        getline(inQuest,qbank[loopy].ans1); //get the four choices
        getline(inQuest, qbank[loopy].ans2);
        getline(inQuest, qbank[loopy].ans3);
        getline(inQuest, qbank[loopy].ans4);

    }
}

//===============================================
void printQuestion(vector<gameQuestion>& qBank, int indexer)
{

         cout << qBank[indexer].question <<endl ;
         cout << "A) " << qBank[indexer].ans1 <<endl ;
         cout << "B) " << qBank[indexer].ans2 <<endl ;
         cout << "C) " << qBank[indexer].ans3 <<endl ;
         cout << "D) " << qBank[indexer].ans4 <<endl ;
}
//===============================================


char evaluateQuestion(vector<gameQuestion>& qBank, int indexer, char playerAnswer)
    {
        if (playerAnswer == qBank[indexer].answer[0])
        { return 'T'; }
        else
        { return 'F'; }
    }

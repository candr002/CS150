/// C.Boyle - WORKING on project 3, spring 2016.
// This program plays a game.

#include <iostream>
#include <fstream>
#include <iomanip>
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
//----------------------------------------------
void gameInfo();
char menu();
void getQuestion(gameQuestion qBank[], int loopy, ifstream& inQuest);
void gameResults(string alias1, string alias2, double score1, double score2);
void gameResults(string alias1, double score1);
void upDateScore(int difficulty, int loopy, double& score1, double& score2);
void upDateScore(int difficulty, int loopy, double& score1);
//----------------------------------------------
int main()
{
    int difficulty=3;
    char solution;  //read and store the question solution
    char userChoice;     //store user provided solution to questions
    char next;      //input to pause between questions
    string date = "\"Mar/2/2016\"";
    string question, ans1,ans2,ans3,ans4;
    string temp;    //store the answer,as a string initially
    string alias1="codeJockey", alias2="codeRival";
    string alias1FileName, alias2FileName;
    string gameHistory = "gameHistory.txt";
    string qBankFile;
    int numQuestions=4, posSolutions=4;
    double score1 =0, score2=0, totalScore =0;
    ifstream inQuest;
    ofstream outFile1, outFileAlias1, outFileAlias2;
    char menuChoice;
//-------------------------------------------
    gameQuestion qBank[MAX_NUM_QUESTIONS];
    menuChoice = menu();

    // loop until a valid menu option is entered


    // process the validated choice
    if(menuChoice == '4')       {
        cout <<"\nExiting.\n";
        return 0;
    }
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
    else if(menuChoice == '3')  {
        gameInfo();
    }
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
    else if(menuChoice == '2')  {
    //initialize to zero every new play
    cout <<"\nTWO PLAYER!\n";

    //prompt for date and alias 1, and alias 2
    cout << "\nEnter the DATE: ";
    cin >> date;
    cout << "\nEnter PLAYER ONE alias: ";
    cin >> alias1 ;
    cout << "\nEnter PLAYER TWO alias: ";
    cin >> alias2;

    // open and validate user history files
    alias1FileName = alias1.append(".txt");
    outFileAlias1.open(alias1FileName.c_str(), ios::app);
    if (!outFileAlias1)
    {
        cerr<<"\nError opening Player One's game history";
        return 1;
    }

    alias2FileName = alias2.append(".txt");
    outFileAlias2.open(alias2FileName.c_str(), ios::app);
    if (!outFileAlias2)
    {
        cerr<<"\nError opening Player Two's game history";
        return 1;
    }


//================================================
    cout <<"Three questions each: ";
    numQuestions=6;
//--------------------------------------------
    cout <<"Enter difficulty level: (1,2,3): ";
    cin >> difficulty;


    if(difficulty == 1)
        {
        inQuest.open("questions1.txt");
        if(!inQuest)
            {
            cout <<"\nERR-opening question file 1.\n";
            return 1;
            }
        }
//-------------------------------------------
    else if(difficulty == 2)
        {
        inQuest.open("questions2.txt");
        if(!inQuest)
            {
            cout <<"\nERR-opening question file 2.\n";
            return 1;
            }
        }
//-------------------------------------------
    else if(difficulty == 3)
        {
        inQuest.open("questions3.txt");
        if(!inQuest)
            {
            cout <<"\nERR-opening question file3.\n";
            return 1;
            }
        }
//-------------------------------------------
    // loop, and use
    // the getQuestion function to load array.
    getQuestion(qBank, MAX_NUM_QUESTIONS, inQuest);

    for (int looper = 0; looper < numQuestions; looper++)
{
    if (looper % 2 == 0)
    {
        cout << "\nPlayer ONE:\n";
        cout << qBank[looper].question << endl;
        cout << "A) " << qBank[looper].ans1 << endl;
        cout << "B) " << qBank[looper].ans2 << endl;
        cout << "C) " << qBank[looper].ans3 << endl;
        cout << "D) " << qBank[looper].ans4 << endl;
        cin >> temp;
        if (toupper(temp[0]) == toupper(qBank[looper].answer[0]))
            {
            upDateScore(difficulty, looper, score1);
            }
    else
    {
        cout << "\nPlayer TWO:\n";
        cout << qBank[looper].question << endl;
        cout << qBank[looper].ans1 << endl;
        cout << qBank[looper].ans2 << endl;
        cout << qBank[looper].ans3 << endl;
        cout << qBank[looper].ans4 << endl;
        cin >> temp;
        if (toupper(temp[0]) == toupper(qBank[looper].answer[0]))
            {
            upDateScore(difficulty, looper, score2);
            }

        }
    }
    cout <<"\nenter any char to continue:";
    cin >>next;
    cout <<"----------------------------------------\n\n";
}
//--------------------------------------------------

    //display game results
    gameResults(alias1, alias2, score1, score2);

    // write output to user history files
    outFileAlias1 << date << "\t"
                    << difficulty << "\t"
                    << score1 << endl;


    outFileAlias2 << date << "\t"
                    << difficulty << "\t"
                    << score2 << endl;
    // write output to game history files
    outFile1.open(gameHistory.c_str(), ios::app);
    if(!outFile1)
    {
        cerr << "Error opening Game History";
        return 1;
    }
    outFile1 << alias1 << "\t"
            << score1 << "\t"
            << difficulty << "\t"
            << date << endl;

    outFile1 << alias2 << "\t"
            << score2 << "\t"
            << difficulty << "\t"
            << date << endl;


    cout <<"\n\n\n\n";
    inQuest.close();
    outFile1.close();
    outFileAlias1.close();
    outFileAlias2.close();
  } ///end of menu option 2
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
    else if(menuChoice == '1')  {

    cout << "\nEnter the DATE: ";
    cin >> date;
    cout << "\nEnter PLAYER alias: ";
    cin >> alias1 ;

    // open and validate user history files
    alias1FileName = alias1.append(".txt");
    outFileAlias1.open(alias1FileName.c_str(), ios::app);
    if (!outFileAlias1)
    {
        cerr<<"\nError opening Player's game history";
    }
    //prompt for number of questions
    cout << "\nEnter Number of questions: ";
    cin >> numQuestions;

    // prompt for difficulty level, and open file
    cout <<"Enter difficulty level: (1,2,3): ";
    cin >> difficulty;
//-------------------------------------------
    // loop, and use
    // the getQuestion function to load array.
 getQuestion(qBank, MAX_NUM_QUESTIONS, inQuest);

    for (int looper = 0; looper < numQuestions; looper++)
    {

        cout << "\nPlayer ONE:\n";
        cout << qBank[looper].question << endl;
        cout << qBank[looper].ans1 << endl;
        cout << qBank[looper].ans2 << endl;
        cout << qBank[looper].ans3 << endl;
        cout << qBank[looper].ans4 << endl;
        cin >> temp;
        if (toupper(temp[0]) == toupper(qBank[looper].answer[0]))
            {
            upDateScore(difficulty, looper, score1);
            }
    cout <<"\nenter any char to continue:";
    cin >>next;
    cout <<"----------------------------------------\n\n";
    }

   ///end of for loop of number of questions
//-----------------------------------------------------

    //show gameResults
    gameResults(alias1, score1);

    outFileAlias1 << date << "\t"
                << difficulty << "\t"
                << score1 << endl;

    outFile1.open(gameHistory.c_str(), ios::app);
    if(!outFile1)
    {
        cerr << "Error opening Game History";
        return 1;
    }
    outFile1 << alias1 << "\t"
            << score1 << "\t"
            << difficulty << "\t"
            << date << endl;


    cout <<"\n\n\n\n";
    inQuest.close();
    outFile1.close();
    outFileAlias1.close();
    outFileAlias2.close();
    }//end of menuChoice 1

   //     menuChoice = menu();
   // } //end of while (menu)

    return 0;
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
        cout <<"\n  "<<alias2<<" = "<<score2<<" pts.";



//implement the logic
        if (score1 > score2)
            {cout <<"\n"<<alias1<<" wins!";}
        else if (score1 < score2)
            {cout <<"\n"<<alias2<<" wins!";}
        else if (score1 == score2)
            {cout <<"\nIt's a tie!";}
}
//===============================================
void gameResults(string alias1, double score1){
        cout <<"\nGame Results!";
        cout <<"\n  "<<alias1<<" = "<<score1<<" pts.";
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
    getline(inQuest, qBank[loopy].answer, '\n');        //get the answer
    getline(inQuest, qBank[loopy].ans1); //get the four choices
    getline(inQuest, qBank[loopy].ans2);
    getline(inQuest, qBank[loopy].ans3);
    getline(inQuest, qBank[loopy].ans4);
}

//===============================================
//===============================================

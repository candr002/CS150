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
    char answer;
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
    int numQuestions=4, posSolutions=4;
    double score1 =0, score2=0, totalScore =0;
    ifstream inQuest;
    ofstream outFile1, outFile2, outFile3;
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

    // open and validate user history files
//================================================
    cout <<"Three questions each: ";
    numQuestions=6;
//--------------------------------------------
    cout <<"Enter difficulty level: (1,2,3): ";

//-------------------------------------------
    // loop, and use
    // the getQuestion function to load array.


    //if player one
        cout <<"\nPlayer ONE:";
    // or if it's player two
        cout <<"\nPlayer TWO";

    // present the question, and store the user input
    // if input is correct,
    // update the score

//--------------------------------------------------
    cout <<"\nenter any char to continue:";
    cin >>next;
    cout <<"----------------------------------------\n\n";
       //end for loop of number of questions
//-----------------------------------------------------
    //display game results
    gameResults(alias1, alias2, score1, score2);

    // write output to user history files
    // write output to game history files

    cout <<"\n\n\n\n";
    inQuest.close();
    outFile1.close();
    outFile2.close();
    outFile3.close();
  } ///end of menu option 2
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=.
    else if(menuChoice == '1')  {

    //prompt for date and alias 1, and alias 2

    // open and validate user history files

    // open and validate user history files

    // open and validate game history file


    //prompt for number of questions

    // prompt for difficulty level, and open file

//-------------------------------------------
    // loop, and use
    // the getQuestion function to load array.

    // present the question, and store the user input
    // if input is correct,
    // update the score
    // or show selection and solution

//--------------------------------------------------
    cout <<"\nenter any char to continue:";
    cin >>next;
    cout <<"----------------------------------------\n\n";

   ///end of for loop of number of questions
//-----------------------------------------------------

    //show gameResults

    cout <<"\n\n\n\n";
    inQuest.close();
    outFile1.close();
    outFile2.close();
    outFile3.close();
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

//===============================================
//===============================================

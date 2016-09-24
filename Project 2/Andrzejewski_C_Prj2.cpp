
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

/// constant point values for difficulty levels
const float DIFF_LEVEL_ONE = 1.23 ,
            DIFF_LEVEL_TWO = 1.51 ,
            DIFF_LEVEL_THREE = 2.02 ;

int main()
{

    cout << "\  ______________________________\n";
    cout << "  Project_Two_Game_Time_for_Bonzo\n";
    cout << "\  ______________________________\n";

    // variable declarations
    string date,
        playerAlias,
        inFileName ,
        outFileName ,
        question,
        answerA ,
        answerB ,
        answerC ,
        answerD ,
        correctAnswer ,     ///I elected to define the "correctAnswer" and "choice" variables as a string
        choice ;            ///so I could stick to using getline to avoid errors from bouncing back and
                            ///forth between getline and inFile.

    int difficultyLevel = 0 ,
        requestedQuestionTotal = 0,
        questionCount = 0 ;

    float questionWeightValue = 0.0 ,
            totalPoints = 0.0 ;

    char nextquest ;
        //choice ,
      //  correctAnswer ;

    ifstream inFile;
    ofstream outFile;



    ///prompt user for info  ***Step 1***
    cout << "Enter the date(example \"Feb/18/2016\"): " ;
    cin >> date ;

    cout << "\nEnter your game alias(example \"codedog\"): ";
    cin >> playerAlias ;

    cout << "\nHow many questions? (1 - 15): ";
    cin >> requestedQuestionTotal ;

    ///Validating number of questions ***Step 1A***
        while (requestedQuestionTotal < 1 || requestedQuestionTotal > 15){
            cout << "\nIncorrect question number..." ;
            cout << "\nHow many questions? (1 - 15): ";
            cin >> requestedQuestionTotal ;
        }

    cout << "\nEnter difficulty level: (1,2,3): ";
    cin >> difficultyLevel ;
    cout << "\n";

    ///Validating difficulty level ***Step 1B***

    if (difficultyLevel < 1 || difficultyLevel > 3){
        cout << "\nIncorrect difficulty level." ;
        return 1;
    }


    ///open and validate file streams ***Step 2***

    ///Appending player alias to set up output filename ***Step 2A***

    outFileName = playerAlias.append(".txt");

    ///Opening and validating newly created output file ***Step 2B***

    outFile.open(outFileName.c_str(), ios::app);

    if (!outFile){
        cerr << "\nError opening OUTPUT file!\n";
        return 1;
    }

    ///Switch statement to decide which question file to open  ***Step 2C***
    ///based on player choice and selecting question weight value

   switch (difficultyLevel){

        case 1:
                inFileName = "questions1.txt";
                questionWeightValue = DIFF_LEVEL_ONE;
                break;

        case 2:
                inFileName = "questions2.txt";
                questionWeightValue = DIFF_LEVEL_TWO ;
                break;

        case 3:
                inFileName = "questions3.txt";
                questionWeightValue = DIFF_LEVEL_THREE ;
                break;
        } ///End of switch




    ///Opening and validating input file based on requested difficulty ***Step 2D***

    inFile.open(inFileName.c_str());

    if (!inFile){
        cerr << "Error opening INPUT file...";
        return 1;
    }

    ///While loop for asking questions until requested umber of questions is met ***Setp 3***

    ///Priming While loop ***Step 3A***
    getline (inFile, question);                 ///By sticking to getline, I can make the best use the of input formatting.
    getline (inFile, correctAnswer);            ///This allows for a more complex (multiple word) answer pool and also has
    getline (inFile, answerA);                  ///the added benefit of limiting potential errors.
    getline (inFile, answerB);
    getline (inFile, answerC);
    getline (inFile, answerD);



   ///While loop start ***Step 3B***
    while (requestedQuestionTotal > questionCount){

            ///Incrementing question count ***Step 3C***
        questionCount++;

    /// output question, and choices ***Step 3D***

        cout << "\nQuestion (" << questionCount << ")\n";

        cout << "\n" << question
            << "\nA) " << answerA
            << "\nB) " << answerB
            << "\nC) " << answerC
            << "\nD) " << answerD ;


    /// get user input for prompted question ***Step 3E***

        cout << "\nEnter your choice: ";
        cin >> choice ;


    ///Evaluate if question is correct and prompt accordingly ***Steps 3F and 3G***

        if (toupper(choice[0]) == toupper(correctAnswer[0])){            ///Comparing the first value of both variables
                cout << "\nYou chose: " << choice << "\t\tCORRECT!\n";   ///to find a true statement
                totalPoints = totalPoints + questionWeightValue ;
            }

        else {                                                           ///Prompt if given a false statement
                cout << "\nYou chose: " << choice << endl;
                cout << "Solution: " << correctAnswer
                    << "\tGuess: " << choice << endl ;
            }

      ///Prompt to continue ***Step 3H***

                cout << "--> enter n for next question:";
                cin >> nextquest;
                cout << "\n--------------------------------------\n" ;


    ///Populate information for next question ***Step 3I***





    getline (inFile, question);
    getline (inFile, correctAnswer);
    getline (inFile, answerA);
    getline (inFile, answerB);
    getline (inFile, answerC);
    getline (inFile, answerD);
    } /// End of while loop.


    /// OUTPUT ***Step 4***


    /// Outputting to Monitor ***Step 4A***
    cout << showpoint << fixed << setprecision(3) ;
    cout << "\n\nScore for " << outFileName << " = " << totalPoints;
    cout << "\n\n\n\n\n";

    ///Outputting/appending file. ***Step 4B***

    outFile << showpoint << fixed << setprecision(3);
    outFile << setw(11) << left << date
            << setw(5) << right << difficultyLevel
            << setw(9) << right << totalPoints << endl ;


    ///Closing input and output files ***Step 5***

    inFile.close();
    outFile.close();


    ///End program ***Step 6***
    return 0;
}
///=-=-=-=-=- end of main =-=-=-=-=-=-=-=-=-=-=-=

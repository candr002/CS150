///***********************************************************
/// NAME:Chris Andrzejewski
/// UIN:01008193
/// Project 5 - cs150 - spring 2016
/// Program description: Project 5 "Questions Game"
///
///
/// File Name:  CAndrzejewski_Project5.cpp
/// TA Name: Aida Ghazizadeh
/// TA Email: aghaziza@cs.odu.edu
///***********************************************************

///===========================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

///===========================================================



///    ***Declaring constants, structs and linked lists***
///===========================================================
const float DIFF_LEVEL_ONE = 1.23;
const float DIFF_LEVEL_TWO = 1.51;
const float DIFF_LEVEL_THREE = 2.02;
const int MAX_NUM_QUESTIONS = 15;

struct playerHistory
{
    string date;
    int difficulty;
    float score;
    string alias;
};

typedef playerHistory histType;

struct histNode
{
    histType info;
    histNode *link;
};

///===========================================================

///             ***Declaring Functions***
///===========================================================
void topFive (histNode* first);
void infileReset (ifstream& inHistory);
histNode* buildHistory (ifstream& inHistory);
void histSort(histNode *first, int thecount);
int entryCount (ifstream& inHistory);
void print(histNode *first);
histType* linkdListCreate(ifstream& inFile);
histType* deleteNode( histNode  *first, string deleteID);
void sortHistory (histNode *first);
void topScore(histNode *first);
void menu (ifstream& inHistory, histNode *first, string deleteID, int menuSel, int thecount);
int choice1(histNode *first, int menuSel);
int choice2(histNode *first, int menuSel, int thecount);
int choice3(histNode *first, int menuSel);
/*void choice4;
void choice5;*/
///===========================================================

///===========================================================
int main()
{
    ifstream inHistory;
    ofstream outHistory;
    histNode *list;
    int totalEntries = 0;
    int menuChoice = 0;
    string deleteAlias;


    inHistory.open("gameHistory.txt");
    if (!inHistory)
        {
        cerr << "\n\nError opening Input file!\n";
        return 1;
        }


    totalEntries = entryCount(inHistory);

    list = buildHistory(inHistory);

    menu(inHistory, list, deleteAlias, menuChoice, totalEntries);

    cout << "You have chosen option 6... GoodBye!!";
    return 0;
    inHistory.close();

}


///=========================================================================
void infileReset (ifstream& inHistory)
{
    inHistory.clear();

    inHistory.seekg(0,ios::beg);
}
///=========================================================================

///=========================================================================
int entryCount (ifstream& inHistory)
{
int counter = 0;
    infileReset(inHistory);
    string temp;

    getline(inHistory, temp);
    counter++;


    while (!inHistory.eof())
        {
        getline(inHistory, temp);
        counter++;
        }
    infileReset(inHistory);
    return counter;
}
///=========================================================================

///=========================================================================
void menu (ifstream& inHistory, histNode *first, string deleteID, int menuSel, int thecount)
{
    cout << "--------------------------------------------------------";
    cout << "\nWelcome to the ALMIGHTY QUESTIONS GAME HISTORY TOOL MANAGER!!!!";
    cout << "\n\nPlease Select a tool to use. Choices are as follows:";
    cout << "\n\n\t1: View GAME HISTORY";
    cout << "\n\t2: View TOP 5 SCORES";
    cout << "\n\t3: View OVERALL GAME STATS";
    cout << "\n\t4: EDIT Player History";
    cout << "\n\t5: SAVE Changes to File";
    cout << "\n\t6: EXIT Tool Manager\n";


    cin >> menuSel;
    cout << "\n-------------------------------------------------------------------\n\n";

    while (menuSel != 6)
        {
            switch (menuSel)
            {
            case 1:
                {
                    menuSel = choice1(first, menuSel);
                    break;
                };
            case 2:
                {
                    menuSel = choice2(first, menuSel, thecount);
                    break;
                };
            case 3:
                {
                    menuSel = choice3(first, menuSel);
                    break;
                };
 /*           case 4:
                {
                    choice4();
                    break;
                };
            case 5:
                    {
                    choice5();
                    break;
                    };*/
            }
        }
}


///=========================================================================

///=========================================================================
histNode* buildHistory (ifstream& inHistory)
{
    histNode *current = NULL, *tempNode = NULL;
    playerHistory player;
    infileReset(inHistory);
    inHistory >> player.alias
                >>player.score
                >>player.difficulty
                >>player.date;

    while (inHistory)
        {

        tempNode = new histNode;
        tempNode->info = player;
        tempNode->link = current;
        current = tempNode;
        inHistory >> player.alias
                    >>player.score
                    >>player.difficulty
                    >>player.date;
        }
    infileReset(inHistory);
    return current;
}
///=========================================================================

///=========================================================================
int choice1(histNode *first, int menuSel)
{
    histNode *current;
    current = first;
    cout << setw(12) << left <<"ALIAS" << "\tSCORE" << "\tDIFFICULTY" << "\tDATE";
    cout << "\n-------------------------------------------------------------------\n";

    while (current != NULL)
        {
      cout << fixed << showpoint << setprecision (2) << setw(12);
      cout << current->info.alias
            << "\t" <<current->info.score
            << "\t    " << current->info.difficulty
            << "\t      " << current->info.date << "\n";
      current = current->link;
        }
    cout << "\n-------------------------------------------------------------------\n\n";

    cout << "\n\n-------------------------------------------------------------------\n\n";
    cout << "\n\nPlease Select a tool to use. Choices are as follows:";
    cout << "\n\n\t1: View GAME HISTORY";
    cout << "\n\t2: View TOP 5 SCORES";
    cout << "\n\t3: View OVERALL GAME STATS";
    cout << "\n\t4: EDIT Player History";
    cout << "\n\t5: SAVE Changes to File";
    cout << "\n\t6: EXIT Tool Manager\n\n";
    cin >> menuSel;
    cout << "\n-------------------------------------------------------------------\n\n";

    return menuSel;
}
///=========================================================================

///=========================================================================
int choice2(histNode *first, int menuSel, int thecount)
{
 //   histSort(first, thecount);
    topFive(first);

    cout << "\n\n-------------------------------------------------------------------\n\n";
    cout << "\n\nPlease Select a tool to use. Choices are as follows:";
    cout << "\n\n\t1: View GAME HISTORY";
    cout << "\n\t2: View TOP 5 SCORES";
    cout << "\n\t3: View OVERALL GAME STATS";
    cout << "\n\t4: EDIT Player History";
    cout << "\n\t5: SAVE Changes to File";
    cout << "\n\t6: EXIT Tool Manager\n\n";
    cin >> menuSel;
    cout << "\n-------------------------------------------------------------------\n\n";

    return menuSel;
}

///=========================================================================

///=========================================================================
int choice3(histNode *first, int menuSel)
{
    topScore(first);
    cout << "\n-------------------------------------------------------------------\n\n";

    cout << "\n\n-------------------------------------------------------------------\n\n";
    cout << "\n\nPlease Select a tool to use. Choices are as follows:";
    cout << "\n\n\t1: View GAME HISTORY";
    cout << "\n\t2: View TOP 5 SCORES";
    cout << "\n\t3: View OVERALL GAME STATS";
    cout << "\n\t4: EDIT Player History";
    cout << "\n\t5: SAVE Changes to File";
    cout << "\n\t6: EXIT Tool Manager\n\n";
    cin >> menuSel;
    cout << "\n-------------------------------------------------------------------\n\n";
}

///=========================================================================

///=========================================================================
void histSort(histNode *first, int thecount)
{
 histNode *trail, *current, *outterCurrent, *temp;

trail = first;
outterCurrent = trail->link;

while (outterCurrent != NULL)
    {
    while (current != NULL)
        {
        current = outterCurrent;
        if (trail->info.score>current->info.score)
            {

            temp->link = current;
            current->link = trail;
            trail->link = temp->link;

            }
        trail = trail->link;
        current = current->link;
        }
    outterCurrent = outterCurrent->link;
    }


}
///=========================================================================

///=========================================================================
void topFive (histNode* first)
{
 histNode *current;
 current = first;

     cout << setw(12) << left <<"ALIAS" << "\tSCORE" << "\tDIFFICULTY" << "\tDATE";
    cout << "\n-------------------------------------------------------------------\n";
    for (int looper =0; looper < 5; looper++)
        {
      cout << fixed << showpoint << setprecision (2) << setw(12);
      cout << current->info.alias
            << "\t" <<current->info.score
            << "\t    " << current->info.difficulty
            << "\t      " << current->info.date << "\n";
      current = current->link;
        }
    cout << "\n-------------------------------------------------------------------\n";
}
///=========================================================================

///=========================================================================
void topScore(histNode *first)
{
    histNode *top, *current;
    current = first;
    top = first;
    while (current)
        {
        current = current->link;
        if (current->info.score > top->info.score)
            top = current;
        current = current->link;
        }
    cout << showpoint << fixed << setprecision(2);
    cout << "\nThe TOP SCORE is " << top->info.score << " by " << top->info.alias <<".\n";
}
///=========================================================================


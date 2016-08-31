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
void getQuestion(vector<gameQuestion>& qbank, int maxQuestNum, ifstream& inQuest);
void gameResults(string alias1, string alias2, double score1, double score2);
void gameResults(string alias1, double score1);
void upDateScore(int difficulty, int loopy, double& score1, double& score2);
void upDateScore(int difficulty, int loopy, double& score1);
///----------------------------------------------

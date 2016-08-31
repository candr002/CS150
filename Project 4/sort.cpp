#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main ()
{

    struct playerHistory
    {
        string date;
        int difficulty;
        float score;
        string alias1;
    };
    playerHistory temp;
    ifstream infile;
    int counter = 0;


    infile.open("gamehistory.txt");
    if (!infile)
    {
        cerr << "Nope";
        return 1;
    }
    while (!infile.eof())
        {
        infile >> temp.alias1
                >> temp.score
                >> temp.difficulty
                >> temp.date;
        counter++;
        }
    infile.clear();
    infile.seekg(0,ios::beg);

    playerHistory histfile[counter] ;

    for (int looper = 0; looper <counter ; looper++)
        {
                infile >> temp.alias1
                    >> temp.score
                    >> temp.difficulty
                    >> temp.date;
                histfile[looper] = temp;
        }
    for (int looper = 0; looper < counter ; looper++)
    {
    cout <<histfile[looper].alias1 << "\t"
        <<histfile[looper].score << "\t"
        <<histfile[looper].difficulty << "\t"
        <<histfile[looper].date << endl;
    }
    cout << "\n\n\n\n";
    temp = histfile[0];

    for (int looper = 1; looper < counter ; looper++)
        {
        for (int loop = 0; loop < counter - looper ; loop++)
            {
            if (histfile[loop].score < histfile[loop+1].score)
                {
                temp = histfile[loop+1];
                histfile[loop+1] = histfile[loop];
                histfile[loop] = temp;
                }
            }
        }
    for (int looper = 0; looper < counter ; looper++)
        {
        cout <<histfile[looper].alias1 << "\t"
            <<histfile[looper].score << "\t"
            <<histfile[looper].difficulty << "\t"
            <<histfile[looper].date << endl;
        }
}

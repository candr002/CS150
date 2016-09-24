

#include <iostream>
#include <iomanip>

using namespace std;

      //Named constants – new category of customers

      //Named constants – residential customers
const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREM_CHANNEL = 7.50;

      //Named constants – business customers
const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 5.00;
const double BUS_COST_PREM_CHANNEL = 50.00;

int main()
{
        //Variable declaration
    int accountNumber;
    char customerType;
    int numOfPremChannels;
    int numOfBasicServConn;
    double amountDue;

    cout << fixed << showpoint;                     //Step 1
    cout << setprecision(2);                        //Step 1

    cout << "This program computes a cable "
         << "bill." << endl;

    cout << "Enter account number (an integer): ";  //Step 2
    cin >> accountNumber;                           //Step 3
    cout << endl;

    cout << "Enter customer type: "
         << "R or r (Residential), "
         << "B or b (Business):  ";                 //Step 4
    cin >>  customerType;                           //Step 5
    cout << endl;

    /* Your decision structure goes here: steps (6,7,8) of
      the algorithm.
      If your UIN is an even number -implement a switch structure.
      If your UIN is odd number, - you must implement the if-else structure.
     see the example source code for this textbook example.
    */










    // don't forget to close the file stream variables


    cout <<"\n\n--------------------------\n";
    return 0;
}

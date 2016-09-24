

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

      //Named constants – new category of customers
const double GOV_BILL_PROC_FEES = 47.99;    //Government customer fees
const double GOV_BASIC_SERV_COST = 82.33;
const double GOV_BASIC_CONN_COST = 7.50;
const double GOV_COST_PREM_CHANNEL = 69.88;
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

    //declaring input file
    string inFileName ;
    ifstream inFile;

    //Prompt user for input file name
    cout << "Enter the input file name: ";
    getline(cin, inFileName);

    //Opening the input file
    inFile.open(inFileName.c_str());

    //Validating input file
    if( !inFile ){
         cerr << "\n\n ERROR opening INPUT file\n\n";
         return 1;
        }

    //declaring the output file
    ofstream outFile;

    //Opening output file
   outFile.open("billingoutput.txt");

   //Validating output file
    if( !outFile ){
         cerr << "\n\n ERROR opening OUTPUT file\n\n";
         return 1;
        }

    //setting up heading for output file

    outFile << setw(8) << left << "Acc#"
            << setw(8) << "TYPE"
            << setw(8) << "AmntDue \n";

    //Reading account number and customer type until end of file
    inFile >> accountNumber >> customerType ;


    /* Your decision structure goes here: steps (6,7,8) of
      the algorithm.
      If your UIN is an even number -implement a switch structure.
      If your UIN is odd number, - you must implement the if-else structure.
     see the example source code for this textbook example.
    */



    while (inFile){
            //Government Calculations
            if (customerType== 'G' or customerType== 'g' ){
                //Pulling number of basic connections and number of premium channels
                inFile >> numOfBasicServConn >> numOfPremChannels;
                //calculating bill
                if (numOfBasicServConn<=10){
                    amountDue = GOV_BILL_PROC_FEES
                        + GOV_BASIC_SERV_COST
                        + (numOfPremChannels *
                          GOV_COST_PREM_CHANNEL);
                }
                else amountDue = GOV_BILL_PROC_FEES
                        + GOV_BASIC_SERV_COST
                        + ((numOfBasicServConn - 10) *
                           GOV_BASIC_CONN_COST)
                        + (numOfPremChannels *
                          GOV_COST_PREM_CHANNEL);
            } //End of Govt calculations


            //Business Calculations
            else if (customerType== 'B' or customerType== 'b' ){
                //Pulling number of basic connections and number of premium channels
                inFile >> numOfBasicServConn >> numOfPremChannels;
                //calculating bill
                if (numOfBasicServConn<= 10) {               //Step 7e
                        amountDue = BUS_BILL_PROC_FEES
                        + BUS_BASIC_SERV_COST
                        + (numOfPremChannels *
                          BUS_COST_PREM_CHANNEL);
                    }

                else amountDue = BUS_BILL_PROC_FEES
                        + BUS_BASIC_SERV_COST
                        + (numOfBasicServConn - 10) *
                           BUS_BASIC_CONN_COST
                        + (numOfPremChannels *
                          BUS_COST_PREM_CHANNEL);
            } // End of Business Calculations


            //Residential Calculations
            else if (customerType== 'R' or customerType== 'r'){
                inFile >> numOfPremChannels ;
                 //calculating bill
                amountDue = RES_BILL_PROC_FEES              //Step 6c
                   + RES_BASIC_SERV_COST
                   + numOfPremChannels *
                     RES_COST_PREM_CHANNEL;
            } // End of Residential calculations


             //Outputting account data to file
            outFile << fixed << setprecision(2) << showpoint << left
                        << setw(8) << accountNumber
                        << setw(8) << customerType << "$"
                        << setw(8) << amountDue << endl;

            //Pulling new customer info
            inFile >> accountNumber >> customerType ;
    } //End of while loop for reading account data

    // Closing input and output files
    inFile.close();
    outFile.close();

    //Outputting program completion notification
    cout <<"\n\n--------------------------\n";
    cout << "  FlyByNight Cable Company\n";
    cout << "    Billing Program\n";
    cout << "Billing info written to:" << inFileName << endl;
    cout << "-------------------------\n";
    return 0;
}

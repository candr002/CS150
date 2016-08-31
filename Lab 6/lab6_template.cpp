//  Cable Bill example from Chapter 4
// Using if else instead of switch

#include <iostream>
#include <iomanip>
#include<fstream>

using namespace std;

//Named constants – residential customers
const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREM_CHANNEL = 7.50;
//Named constants – business customers
const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 5.00;
const double BUS_COST_PREM_CHANNEL = 50.00;
//Named constants - Government customers
const double Gov_bill_proc_fee = 47.99;
const double Gov_basic_serv_cost = 82.33;
const double Gov_basic_conn_cost = 7.50;
const double Gov_premium_channel_cost = 69.88;
//Named constants – military customers
const double MIL_BILL_PROC_FEES = 54.50;
const double MIL_BASIC_SERV_COST = 40.50;
const double MIL_COST_PREM_CHANNEL = 17.44;


   ///Declare Function prototypes




int main()
{

    ///Create Programmer info

    string name=" ";                //Variable declaration
    int yourid=0;
    int accountNumber=0;             //store customer account number
    char customerType=' ';             //input by user
    double amountDue=0.0;
    int busCount=0;
    int resCount=0;
    int govtCount=0;
    int militaryCount=0;
    double totalDue =0.0;
    string inputFileName= " ";
    ifstream inFile;
    ofstream outfile;            // calculated by the program

    outfile << fixed << showpoint;                     //Step 1
    outfile << setprecision(2);                        //Step 1

    cout << "This program computes a cable "
         << "bill." << endl;

    cout<<"Enter the input file name:";

    ///Take input file name using geline()


    ///Open the input file


    ///Validate input


    ///Open output file


    ///Validate output file


        ///Prompt user for name, UIN and print the output on console window.


        cout<<"----------------------------\n"
            <<"FlyByNIght Cable Company\n"
            <<"Billing Program\n"
            <<"Billing information written  ///Formulato:""\"output.txt\"";
        cout<<"\n----------------------------\n";
        cout<<endl;

        ///Output the user data to output file.

        outfile<<endl;

        outfile<<"**************************"<<endl;

        outfile<<"programmer_info\n";

        outfile<<"**************************"<<endl;

        outfile<<"Acc#   Type    AmntDue\n";

    inFile >> accountNumber;                         //Step 4
    inFile >> customerType;

    while(/*Read till the end of input file*/){

          if (customerType =='r' || customerType =='R')
              {
                ///Count the total number of residents

                ///Call the resident function

                ///Print to the output file using output file stream variable


              }

          else if (customerType =='b' || customerType =='B')
              {
                ///Count the total number of business customers

                ///Call the business customer function

                ///Print to the output file using output file stream variable


              }
          else if  (customerType =='g' || customerType =='G')
              {

                ///Count the total number of government customer

                ///Call the government customer function

                ///Print to the output file using output file stream variable

              }


          else if (customerType == 'm' || customerType == 'M')
              {

               ///Count the total number of military customer

               ///Call the government customer function

               ///Print to the output file using output file stream variable

              }

           else
                outfile<< "Invalid customer type." << endl;

        inFile >> accountNumber;                         //Step 4
        inFile >> customerType;
      }


    outfile <<"\n=============================\n";
    outfile <<"    "<<busCount+resCount+govtCount+militaryCount<<" total accounts.\n";
    outfile <<"   -  "<<resCount<<" residential accounts.\n";
    outfile <<"   -  "<<busCount<<" business accounts.\n";
    outfile <<"   -  "<<govtCount<<" Government accounts.\n";
    outfile <<"   -  "<<militaryCount<<" Military accounts.\n";
    outfile <<"Billing total for all accounts: "<<totalDue<<"\n";



   ///close input and output file stream variables.

    return 0;
}


double residential(ifstream& input)
{
   double bAmount=0.0;
   int numOfPremChannels=0;

   ///Use formulas to calculate the billing amount


   return bAmount;
}


double business(ifstream& input)
{
    double bAmount=0.0;
    int numOfPremChannels=0;
    int numOfBasicServConn=0;

    ///Use formulas to calculate the billing amount




    return bAmount;

}

double goverment(ifstream& input)
{
    int numOfPremChannels=0;
    int numOfBasicServConn=0;
    double bAmount=0.0;

    ///Use formulas to calculate the billing amount

    return bAmount;
}

double military(ifstream& input)
{
    int numOfPremChannels=0;
    double bAmount=0.0;


    ///Use formulas to calculate the billing amount


    return bAmount;
}


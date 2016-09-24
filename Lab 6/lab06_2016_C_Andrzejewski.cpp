


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



    int numOfPremChannels = 0;
    int numOfBasicServConn = 0;

   ///Declare Function prototypes
    double residential(ifstream& input);
    double business(ifstream& input);
    double goverment(ifstream& input);
    double military(ifstream& input);




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

    getline(cin, inputFileName);


    ///Open the input file
    inFile.open(inputFileName.c_str());


    ///Validate input
    if (!inFile){
        cerr << "\nError opening INPUT file!";
        return 1;
        }

    ///Open output file
    outfile.open("output1.txt");

    ///Validate output file
    if(!outfile){
        cerr << "\nError opening OUTPUT file!";
        return 1;
        }

        ///Prompt user for name, UIN and print the output on console window.
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Enter your ID(UIN): ";
    cin >> yourid;


        cout<<"----------------------------\n"
            <<"FlyByNIght Cable Company\n"
            <<"Billing Program\n"
            <<"Billing information written to:\"output1.txt\"";
        cout<<"\n----------------------------\n";
        cout<<endl;

        ///Output the user data to output file.

        outfile<<endl;
        outfile << "Name:" << name << endl;
        outfile << "ID(UIN):" <<yourid << endl;
        outfile<<"**************************"<<endl;

        outfile<<"Programmer Name: Chris Andrzejewski\n";
        outfile<<"Programmer UIN: 01008193\n";
        outfile<<"TA Name: Aida Ghazizadeh\n" ;
        outfile<<"TA Email: aghaziza@cs.odu.edu\n";

        outfile<<"**************************"<<endl;

        outfile<<"Acc#   Type    AmntDue\n";

    inFile >> accountNumber;                         //Step 4
    inFile >> customerType;

    while(!inFile.eof()){

          if (customerType =='r' || customerType =='R')
              {
                ///Count the total number of residents
                resCount++;
                ///Call the resident function
                amountDue = residential(inFile);
                ///Print to the output file using output file stream variable
                outfile << accountNumber << "\t"
                    <<customerType << "\t"
                    << amountDue << endl;

              }

          else if (customerType =='b' || customerType =='B')
              {
                ///Count the total number of business customers
                busCount++;
                ///Call the business customer function
                amountDue = business(inFile);
                ///Print to the output file using output file stream variable
                outfile << accountNumber << "\t"
                    <<customerType << "\t"
                    << amountDue << endl;

              }
          else if  (customerType =='g' || customerType =='G')
              {

                ///Count the total number of government customer
                govtCount++;
                ///Call the government customer function
                amountDue = goverment(inFile);
                ///Print to the output file using output file stream variable
                outfile << accountNumber << "\t"
                    <<customerType << "\t"
                    << amountDue << endl;
              }


          else if (customerType == 'm' || customerType == 'M')
              {

               ///Count the total number of military customer
                militaryCount++;
               ///Call the government customer function
                amountDue= military(inFile);
               ///Print to the output file using output file stream variable
                outfile << accountNumber << "\t"
                    <<customerType << "\t"
                    << amountDue << endl;
              }

   //        else{
   //             outfile<< "Invalid customer type." << endl;

   //        }



        totalDue = totalDue + amountDue;
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
    inFile.close();
    outfile.close();
    return 0;
}


double residential(ifstream& input)
{
   double bAmount=0.0;
   int numOfPremChannels=0;

   input >> numOfPremChannels;

   ///Use formulas to calculate the billing amount
    bAmount = RES_BILL_PROC_FEES
                   + RES_BASIC_SERV_COST
                   + numOfPremChannels *
                     RES_COST_PREM_CHANNEL;


   return bAmount;
}


double business(ifstream& input)
{
    double bAmount=0.0;
    int numOfPremChannels=0;
    int numOfBasicServConn=0;


    input >> numOfPremChannels;
    input >> numOfBasicServConn;


    ///Use formulas to calculate the billing amount
    bAmount = BUS_BILL_PROC_FEES
            + BUS_BASIC_SERV_COST
            + (numOfBasicServConn - 10) *
            BUS_BASIC_CONN_COST
            + (numOfPremChannels *
              BUS_COST_PREM_CHANNEL);



    return bAmount;

}

double goverment(ifstream& input)
{
    int numOfPremChannels=0;
    int numOfBasicServConn=0;
    double bAmount=0.0;

    ///Use formulas to calculate the billing amount

    input >> numOfPremChannels;
    input >> numOfBasicServConn;

    if (numOfBasicServConn<=10){
                    bAmount = Gov_bill_proc_fee
                        + Gov_basic_serv_cost
                        + (numOfPremChannels *
                          Gov_premium_channel_cost);
                }
            else {
                    bAmount = Gov_bill_proc_fee
                        + Gov_basic_serv_cost
                        + ((numOfBasicServConn - 10) *
                           Gov_basic_conn_cost)
                        + (numOfPremChannels *
                          Gov_premium_channel_cost);
                }
    return bAmount;
}

double military(ifstream& input)
{
    int numOfPremChannels=0;
    double bAmount=0.0;

    input >> numOfPremChannels;

    ///Use formulas to calculate the billing amount

    bAmount = MIL_BILL_PROC_FEES+
            MIL_BASIC_SERV_COST+
            numOfPremChannels * MIL_COST_PREM_CHANNEL;

    return bAmount;
}


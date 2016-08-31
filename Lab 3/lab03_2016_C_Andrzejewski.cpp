///Fill out these Preliminary Comments,  or lose points.
//Programmer Name: Chris Andrzejewski
//Programmer UIN: 01008193
//Program Description: CS 150 Lab 3

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(){
                //fill in this programmer info
cout << "************************************\n";
	cout << "*        Lab Assignment 3      *\n";
	cout << "*  CS150 ODU Computer Science  *\n";
	cout << "*  Author: Chris Andrzejewski  *\n";
	cout << "*  Date: 3 Feb 2016            *\n";
	cout << "*lab03_2016_C_Andrzejewski.cpp *\n";
	cout << "*  TA Name: Aida Ghazizadeh    *\n";
	cout << "*  TA Email:aghaziza@cs.odu.edu*\n";
	cout << "********************************\n";

    //declare and initialize variables (formatting)
    int width = 5;
    //declare and initialize variables (user info)done for you.
      string fName ="Kendra";
      string lName ="Melzinski";
      int empID=6983;


    ///hint: see example code for the following:
    //declare and initialize variables (for the stock item)

    string itemID ; //ID of item
    double markUp ; // Percentage the store will mark up
    double initialPrice ;  //base price of item prior to markup
    double sellPrice ;  //Price after store markup
    double taxRate ;    //Percentage of local sales tax
    double salesTax ;  //Value of sales tax for the item
    double finalPrice ;  //final cost of item after markup and sales tax

    ///declare input stream variables. hint: see example code:

    //declare & set up INPUT stream variables
    string inFileName ;
    ifstream inFile ;
    //prompt user for a filename
    cout << "Enter the name of your input file: " ;
    cin >> inFileName ;
    cout << endl;
    //open input file
    inFile.open(inFileName.c_str());
    //validate the input file
    if( !inFile ){
         cerr << "\n\n ERROR opening INPUT file\n\n";
         return 1;
        }

    ///declare OUTPUT stream variables (done for you)
      ofstream outFile;
    //open output file (done for you)
      outFile.open("outLab3.txt");
    //validate the output file
      if( !outFile ){
         cerr << "ERROR opening OUTPUT file\n\n";
         return 1;
        }


    ///Prompt for, and store user info
                            //first name
                            cout << "Enter first name: ";
                            cin  >> fName ;
                            //cout << endl ;
                            //last name
                            cout << "Enter last name: ";
                            cin >> lName ;
                            //cout << endl;
                            //ID Number
                            cout << "Enter employee ID: ";
                            cin >> empID ;
                            //cout << endl ;

    ///Write user info to output file(done for you)
    outFile <<"Employee: "<< fName <<" "<<lName;
    outFile <<", ID: "<<empID<<"\n";



    ///Read item information from input file.
    //hint: use getline for item name (see example provided)
                                //read item name
                                getline(inFile, itemID);
                                //read original price
                                inFile >> initialPrice;
                                //read markup
                                inFile >> markUp;
                                //read tax rate
                                inFile >> taxRate;




    ///Calculate desired values
        //hint: see example source code

    // calculate selling price
    sellPrice = (initialPrice * (markUp / 100)) + initialPrice ;
    // calculate salesTax
    salesTax = sellPrice * (taxRate / 100) ;
    // calculate final price
    finalPrice = sellPrice + salesTax ;

    ///Write results to output file in required format
    //hint:see example movie tickets program)
	//hint: it may be easier to output the info to the monitor
	//      until you format it correctly, and then use
	//      the same code (change cout to outFile) to send
	//      the data to the file.
    outFile <<  fixed << showpoint << setprecision(2);
    outFile << "Item: " << itemID << endl;
    outFile << left << setw(35) << setfill('.') << "- Purchase Price: "
         << " $" << initialPrice << endl;
    outFile << setfill('.') << left << setw(35) << "- Markup Percent: "
        << " " <<  markUp << "%" << endl;
    outFile << setfill('.') << left << setw(35) <<setfill('.')
         << "- Selling Price: "  << " $" << sellPrice << endl;
    outFile << setfill('.') << left << setw(35)
         << "- Sales tax rate: " << "  " << taxRate << "%" << endl;
    outFile << setfill('.') << left << setw(35)
         << "- Total sales tax: " << " $" << salesTax << endl;
    outFile << setfill('.') << left << setw(35)
         << "- Final sales amt: "
         << " $" <<  finalPrice << endl;
    outFile << "---------------------------------------------" << endl;

    cout << "\n\n\nInformation written to file \"outLab3.txt\"\n\n\n" ;
    cout <<        "-------------------------------------------" ;



    //close file stream variables
    outFile.close();    //close output file stream variable
    inFile.close();
                        //DON'T FORGET TO close INPUT file stream

    return 0;}
///=-=-=-=-=-=-=ENDofMAIN-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

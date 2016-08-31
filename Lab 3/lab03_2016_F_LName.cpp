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
	cout << "*  TA Name:                    *\n";
	cout << "*  TA Email:                   *\n";
	cout << "********************************\n";

    //declare and initialize variables (formatting)
    int width = 5;
    //declare and initialize variables (user info)done for you.
      string fName ="Kendra";
      string lName ="Melzinski";
      int empID=6983;


    ///hint: see example code for the following:
    //declare and initialize variables (for the stock item)



    ///declare input stream variables. hint: see example code:

    //declare & set up INPUT stream variables

    //prompt user for a filename

    //open input file

    //validate the input file


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
                            //last name
                            //ID Number


    ///Write user info to output file(done for you)
    outFile <<"Employee: "<< fName <<" "<<lName;
    outFile <<", ID: "<<empID<<"\n";



    ///Read item information from input file.
    //hint: use geline for item name (see example provided)
                                //read item name
                                //read original price
                                //read markup
                                //read tax rate



    ///Calculate desired values
        //hint: see example source code

    // calculate selling price

    // calculate salesTax

    // calculate final price


    ///Write results to output file in required format
    //hint:see example movie tickets program)
	//hint: it may be easier to output the info to the monitor
	//      until you format it correctly, and then use
	//      the same code (change cout to outFile) to send
	//      the data to the file.



    //close file stream variables
    outFile.close();    //close output file stream variable

                        //DON'T FORGET TO close INPUT file stream

    return 0;}
///=-=-=-=-=-=-=ENDofMAIN-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

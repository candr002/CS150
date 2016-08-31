//Programmer : boyle
//Date       : stardate 2016
//Lab        : 3
//Description: example of getline (twice), and example of prompting
//              the user for the name of an input file.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string input;
  //declare & set up INPUT stream variables
      ifstream inFile;
      string input_filename;
    //prompt user for a filename
      cout << "Enter the name of your input file: ";
      getline( cin, input_filename);
    //open input file
      inFile.open( input_filename.c_str() );
  //        inFile.open("testing.txt");

    //validate the input file
      if( !inFile ){
         cerr << "ERROR: could not open input file\n\n";
         return 1;
        }

    getline(inFile, input);
    cout <<"\n\n\t"<<input<<"\n\n";

    inFile.close();
    return 0;
}
	

/* *************************************************************
 Programmer:    your name goes here
 file:          first_last_lab1A.cpp        change this
 TA Name:       ( put the name of your lab TA here )
 TA Email:      (find out your TAs email, and put it here)

 Given the length and width of a rectangle, this C++ program
 computes and outputs the perimeter and area of the rectangle.
 Modify this program to produce the required output
 as explained in the comments below. You will submit this program
 as part of your solution for lab 1.
//********************************************************** */

#include <iostream>

using namespace std;

int main()
{
    ///(1) Required "programmer info code"




    ///(2) declared. initialize these variables to zero!
    double length;
    double width;
    double area;
    double perimeter;

    cout << "\nProgram to compute and output the perimeter and "
         << "area of a rectangle.\n\n\n";

    ///(3) ask the user for the length, using a cout statement

    ///(4) store input in variable, using a cin statement

    ///(5) do the same two steps for width.

    ///(7)calculations - all you need to do is UN-comment these two lines
    //perimeter = 2 * (length + width);
    //area = length * width;

    ///(8) output results
    cout << " Length = " << length << endl;
    cout << " Width =  " << width << endl;
    cout << " Perimeter = " << perimeter << endl;
    cout << " Area = " << area << endl;


    cout<<"\n\n";       // comment out this line, and see what happens
    cout <<endl<<endl;  // now comment out this one,.. what happens?

    ///(9) exit program
    return 0;
}//========================end of main======================


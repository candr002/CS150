///lab 10 on linked lists. This is an important one. You will see
/// a question similar to this on the lab final.

//Programmer :  fill this information in, or receive a zero for a grade.
//Date       :
//Lab        :
//Description:
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

///employeeType struct, node struct, typedef statement go here.


            // Function Prototypes
 void print(nodeType *);  // Function to print a LL
 void printOne (employeeType one);
 nodeType* linkdListCreate2 (ifstream& inFile);
 nodeType* linkdListCreate1 (ifstream& inFile);
 employeeType getOne ( ifstream& dataIn );
 int avgDependents (nodeType *list);
 int locateId(nodeType *list, int targetID);
 nodeType* deleteNode( nodeType  *first, int deleteID);

  int main ()
{
    //get our input file stream handling taken care of
        ifstream dataFile;
        dataFile.open ( "Employees.txt" );
        if (!dataFile)
        {  cout << "\n\n\t  INPUT FILE ERROR  \n\n";    }
    //------------------------------------------------
    ///Declare and initialize a head pointer to first node in list

    char choice ='U';
    while((choice != 'B')&&(choice !='F'))  {
        cout<<"Create list: Forwards(enter F)   Backwards(enter B)\n";
        cin >>choice;
    }
    ///Use a decision structure to create the list
    /// either forwards or backwards, according to the user input.


    ///print the list of employees


    /// calculate the average number of dependents
    cout<<"\nAverage # dependents: ";


    ///use locateID function to determine target value, then deleteNode
    ///to remove the employee at that node number from the LL
    int id=0, location=0;
    cout<<"\nEnter an ID to fire someone: ";
    cin>>id;
    loc = locateId(first, id);
    if(location!=0){
       cout<<"\nID Number "<<id<<" was at node "<<location<<", and has been terminated.\n"<<loc;

       ///terminate the employee with the target ID number, by deleting the node

       cout <<"\n\nNew list:\n";
       ///print the list of employees

    }
    else
        cout <"\nThat ID is not in our list.\n";


    cout <<"\n";
    return 0;
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=:-@
///-----------------------------------------------------------------
//Creates a linked list by adding a new last node after each call to
// the getOne function, thus inserting the nodes into the list in the
// same order as the input file - returns pointer to first node in list.
 nodeType* linkdListCreate1 (ifstream& inFile){


     return NULL;
 }
///-----------------------------------------------------------------
//Creates a linked list by setting the first pointer to the new node
// after each call to the getOne function, thus inserting nodes into
// list in reverse order. returns pointer to first node in list.
 nodeType* linkdListCreate2 (ifstream& inFile){


     return NULL;
 }
///-----------------------------------------------------------------
//print makes a temp pointer to head of LL, and moves node
//to node displaying the values of the members of each element
  void print(nodeType *first){


   }
///-----------------------------------------------------------------
//the getOne function reads one line of input data from the file stream,
// and loads it into an employeeType class or struct object
// that it returns to the calling function
employeeType getOne ( ifstream& dataIn ){
    employeeType one;

      dataIn >> one.firstName >> one.lastName >> one.gender
             >> one.idNum >> one.payrate >> one.dependents;

      return one;
 }
///-----------------------------------------------------------------
//print out one employeeType class or struct object
 void printOne ( employeeType one){
      cout << fixed << showpoint << setprecision (2);
      cout << "ID Num: " << one.idNum << endl;
      cout << "Name: " <<one.firstName << " " << one.lastName<< endl;
      cout << "-Gender: " << one.gender <<"\n";
      cout << "-Payrate $"<< one.payrate <<"\n";
      cout << "-Dependents " << one.dependents <<"\n";
 }
///-----------------------------------------------------------------
// in case of duplicates, the first occurrence of deleteItem is removed.
// list can be ordered or unordered
nodeType * deleteNode(nodeType *first, int deleteID)
{


}//end deleteNode
//=======================================================================
//calculates average number of dependents for all employees
 int avgDependents (nodeType *list){


 }// end of average function
//=======================================================================
//=======================================================================
//locates the number of the node in the list that
//contains the target ID value.
 int locateId(nodeType *list, int targetID){

 }// end of locate the ID function
//=======================================================================
///-=-=-=-=-=-=-=-=-=-=-=-=-endOf-main=-=-=-=-=-=-=-=-=-=-=-=-=-=:-@





//=====================================================================


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

///employeeType struct, node struct, typedef statement go here.
    struct employeeType
    {
        int idNum;
        string firstName;
        string lastName;
        int idnum;
        float payrate;
        char gender;
        int dependents;
    };

    typedef employeeType infoType;

    struct nodeType
    {
        infoType info;
        nodeType *link;
    };



            // Function Prototypes
 void print(nodeType *first);  // Function to print a LL
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
        dataFile.open ( "empData.txt" );
        if (!dataFile){
        {  cout << "\n\n\t  INPUT FILE ERROR  \n\n";    }
            return 1;}
    //------------------------------------------------
    ///Declare and initialize a head pointer to first node in list
    nodeType  *list;



    char choice ='U';
    while((toupper(choice) != 'B')&&(toupper(choice) !='F'))  {
        cout<<"Create list: Forwards(enter F)   Backwards(enter B)\n";
        cin >>choice;
    }
    ///Use a decision structure to create the list
    /// either forwards or backwards, according to the user input.
    if (toupper(choice) == 'B')
            list = linkdListCreate2(dataFile);

    else
            list = linkdListCreate1(dataFile);


    ///print the list of employees

        cout <<"\n\n\n========================================================\n\n";
        cout << "\t\tYOUR EMPLOYEE LIST:\n\n";
                print(list);
        cout <<"\n\n========================================================\n\n";

    /// calculate the average number of dependents
    int avgDeps;
        avgDeps = avgDependents(list);
    cout<<"\nAverage # dependents: " << avgDeps;


    ///use locateID function to determine target value, then deleteNode
    ///to remove the employee at that node number from the LL
    int id=0, location=0;
    cout<<"\nEnter an ID to fire someone: ";
    cin>>id;
    location = locateId(list, id);

    if(location!=0){
       cout<<"\nID Number "<<id<<" was at node "<<location<<", and has been terminated.\n";

       ///terminate the employee with the target ID number, by deleting the node
        list = deleteNode(list, id);

       ///print the list of employees
        cout <<"\n\n\n\n\n========================================================\n\n";
        cout << "\n\n\t\tYOUR NEW EMPLOYEE LIST:\n\n";



        print (list);
        cout <<"\n\n========================================================\n\n";

        }
    else
        {cout <<"\nThat ID is not in our list.\n";}


    cout <<"\n";
    return 0;
}
///-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=:-@
///-----------------------------------------------------------------
//Creates a linked list by adding a new last node after each call to
// the getOne function, thus inserting the nodes into the list in the
// same order as the input file - returns pointer to first node in list.
 nodeType* linkdListCreate1 (ifstream& inFile){

     nodeType *first = NULL;
     nodeType *last = NULL;
     nodeType *temp = NULL;

     employeeType person;

     person = getOne(inFile);

     while (inFile)
        {
         temp = new nodeType;
         temp->info = person;
         temp->link = NULL;

         if (first == NULL)
            {
             first = temp;
             last = temp;
            }
        else
            {
            last->link = temp;
            last = temp;
            }
        person = getOne(inFile);
        }


     return first;
 }
///-----------------------------------------------------------------
//Creates a linked list by setting the first pointer to the new node
// after each call to the getOne function, thus inserting nodes into
// list in reverse order. returns pointer to first node in list.
 nodeType* linkdListCreate2 (ifstream& inFile){
    nodeType *first= NULL, *temp = NULL;

    employeeType person;
    person = getOne(inFile);

    while (inFile)
        {
        temp = new nodeType;
        temp->info = person;
        temp->link = first;
        first = temp;
        person = getOne(inFile);
        }

     return first;
 }
///-----------------------------------------------------------------
//print makes a temp pointer to head of LL, and moves node
//to node displaying the values of the members of each element
  void print(nodeType *first){
    nodeType *current;
    current = first;

    while (current != NULL)
        {
        printOne(current->info);
        cout << "\n";
        current = current->link;
        }

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
nodeType *current; //pointer to traverse the list
    nodeType  *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
       if (first->info.idNum == deleteID) //Case 2
        {
            current = first;
            first = first->link;


            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to
                                   //the second node

            while (current != NULL && !found)
            {
               if (current->info.idNum != deleteID)

                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;

                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else

    return first;

}//end deleteNode
//=======================================================================
//calculates average number of dependents for all employees
 int avgDependents (nodeType *list){
    if (list==NULL)
        {
        return 0;
        }

    int sum = 0, avg = 0, count = 0;
    nodeType *ptr;
    ptr = list;

    while (ptr != NULL)
        {
        sum = sum + ptr->info.dependents;
        count++;
        ptr = ptr->link;
        }

    if (count != 0)
        {
        avg = sum / count;
        return avg;
        }
 }// end of average function
//=======================================================================
//=======================================================================
//locates the number of the node in the list that
//contains the target ID value.
 int locateId(nodeType *list, int targetID){
     if (list==NULL)
        {
        return 0;
        }
    int count = 1;

    nodeType *ptr;
    ptr = list;
    while (ptr != NULL)
        {
        if (ptr->info.idNum == targetID)
            {
            return count;
            }
        count++;
        ptr = ptr->link;
        }
 }// end of locate the ID function
//=======================================================================
///-=-=-=-=-=-=-=-=-=-=-=-=-endOf-main=-=-=-=-=-=-=-=-=-=-=-=-=-=:-@


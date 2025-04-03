#include <iostream>
#include <string>
using namespace std;


// this is a single line comment

/*
this is a multiline comment
*/


void myFunction(); // declaration 
int main(){
    cout<< "hello world"<<endl;

    // Variables 
    /*
    they are containers for storing data values
    */

    // declaring (creating) a variable
    int myNumber = 2025;
    cout << "my number is: " << myNumber << endl;

    // declaring multiple variables 
    int x = 5, y = 10, z = 15;

    // user input
    cout << "type a number: " << endl;
    cin >> myNumber;
    cout << "my number is: " << myNumber << endl;

    // data types 
    /* string is used to store a sequence of characters.
    it is not a built in type but it behaves like one 
    to use them we must include the <string> library
    */
    string greetings = "hello";
    cout << greetings<< endl;

    /* for input from the user, cin terms white spaces as terminating characters,
    so to get more than one word from the user we use getline()
    */

   string fullNamecin;
   string fullNamegetline;
    cout << "type your full name: " << endl;
    cin >> fullNamecin;
    cout << "your full (cin) name is: " << fullNamecin << endl;
    // why does the part below behave unexpectedly?
    cout << "type your full name again: " << endl;
    getline(cin, fullNamegetline);
    cout << "your full (getline) name is: " << fullNamegetline << endl;


    // Arrays
    /**
     * arrays are used to store multiple values in a single variable
     */
    string myName[3] = { "daniel", "orango", "masi"};
    string firstName = myName[0];
    string lastName = myName[2];

    cout<<"first name: " << firstName << "last name: "<< lastName << endl;


    // functions 
    myFunction();
    return 0;
}

// Function definition
void myFunction() {
  cout << "I just got executed!";
}
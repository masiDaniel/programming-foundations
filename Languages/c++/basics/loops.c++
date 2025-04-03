#include <iostream>
using namespace std;

int main(){

    /**
     * loop execuete a block of code as long as a specific condition
     * is reaced
     */

    //while loop
    int i = 0;
    while (i < 5){
        cout << "the value for i is "<< i << endl;
        i++;
    }

    cout << "the value for i outside the loop is "<< i << endl;

    // do while loop 
    int j = 0;

    do{
        cout << "the value for j is "<< j << endl;
        j++;

    }while(j<5);


    return 0;
}
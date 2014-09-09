/*
 * File:   main.cpp
 */
#include<iostream>

using namespace std;

/*
 * Simple main.cpp which compares the elements
 * of two arrays and returns True if the second array
 * contains all the elements of the first array else
 * it returns False
 *
 * @ author Sameera Desai
 */

/*
 * The main program
 */
int main() {
    int size1, size2;               //size of the two arrays
    bool contains;                //contains used to check if second array
                                  //contains elements of first array
    bool final = 1;                 //final result

    //Prompt the user for the size of the list
    cout << "List 1 size: ";
    cin >> size1;
    int list1[size1];            //first list

    //Prompt the user for data of the first list
    cout << "List 1 data: ";
    for(int i = 0; i < size1; i++) {
        cin >> list1[i];
    }

    //Prompt the user for the size of the second list
    cout << "List 2 size: ";
    cin >> size2;
    int list2[size2];           //second list
    cout << "List 2 data: ";
    for(int i = 0; i < size2; i++) {
        cin >> list2[i];
    }

    //Compare the elements of both the lists
    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            //If list2 contains the element from list1
            //set contains to 1 else set contains to zero

            if(list1[i] == list2[j]) {
                contains = 1;
                break;
            }
            else {
                contains = 0;
            }
        }

        //Perform Logical AND final and contains
        final = final && contains;
    }

    //if the AND result is 1 print TRUE else if
    //the AND result is zero print FALSE
    if(final){
        cout << "TRUE" << endl;
    }
    else if(final == 0) {
        cout << "FALSE" << endl;
    }
    return 0;
}

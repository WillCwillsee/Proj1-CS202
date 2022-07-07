//
//  names.cpp
//
//
//  Created by William Charles on 12/26/19.
//

#include "names.hpp"
#include <iostream>
#include <fstream>

using namespace std;

const int ARR_COLS = 9;
const int ARR_ROWS = 10;

void myStringCopy (char destination [ARR_ROWS][ARR_COLS], const char source[ARR_ROWS][ARR_COLS]);

int myStringLength(const char str[][ARR_COLS], int row);
 
int myStringCompare(const char str1[][ARR_COLS], int row1, const char str2[][ARR_COLS], int row2);

void readNames(ifstream& inputStream, char inputfile[], char namesArray[ARR_ROWS][ARR_COLS]);

void printNamesToTerminal(char namesArray[ARR_ROWS][ARR_COLS], int nameOrder[]);

void sortNamesAlphabetic(char namesArray[ARR_ROWS][ARR_COLS], char tempNames[ARR_ROWS][ARR_COLS], int nameOrder[], int tempOrder[]);

int main ( ) {
    ifstream inputStream;
    ofstream outputStream;
    char inputFile [8], /*outputFile [8],*/ namesArray[ARR_ROWS][ARR_COLS] = { }, tempNames[ARR_ROWS][ARR_COLS] = { };
    int nameOrder[11] = {1,2,3,4,5,6,7,8,9,10}, tempOrder[11] = { };
    cout << "What is the name of the input file? " << endl;
    cin >> inputFile;
    
    //cout << "What is the name of the output file? " << endl;
    //cin >> outputFile;
    
    inputStream.open(inputFile);
    /*outputStream.open(outputFile);
     outputStream.close();
     */

    readNames(inputStream, inputFile, namesArray);
    printNamesToTerminal(namesArray, nameOrder);
    myStringCopy(tempNames, namesArray);
   /* int z = 3;
    
    z = myStringCompare(namesArray, 0, tempNames, 0);
    cout << z;
    z = myStringCompare(namesArray, 1, tempNames, 1);
    cout << z;
   */
    
    
    inputStream.close();
    return 0;
}

void readNames(ifstream& inputStream, char inputfile[8], char namesArray[ARR_ROWS][ARR_COLS]){
    for (int i = 0; i < ARR_ROWS; i++){
            inputStream.getline(namesArray[i], ARR_COLS);
    }
}

 void printNamesToTerminal(char namesArray[ARR_ROWS][ARR_COLS], int nameOrder[]){
     for (int m = 0; m < ARR_ROWS; m++){
         cout << nameOrder[m] << " ";
         for (int n = 0; n < ARR_COLS; n++){
             cout << namesArray[m][n];
         }
         cout << endl;
     }
 }

void sortNamesAlphabetic(char namesArray[ARR_ROWS][ARR_COLS], char tempNames[ARR_ROWS][ARR_COLS], int nameOrder[], int tempOrder[]){
    for (int m = 0; m < ARR_ROWS; m++){
            for (int n = 0; n < ARR_COLS; n++){
                if (myStringCompare(namesArray, m, tempNames, m) > 0){
                    //myStringCopy();
                }
            }
    }
}

 void myStringCopy (char destination[ARR_ROWS][ARR_COLS], const char source[ARR_ROWS][ARR_COLS]){
     for (int m = 0; m < ARR_ROWS; m++){
         for(int n = 0; n < ARR_COLS; n++){
             destination[m][n] = source[m][n];
         }
     }
}


 int myStringLength(const char str[][ARR_COLS], int row){
     int counter = 0;
        while(str[row][counter]!= '\0'){
         counter++;
        }
     return counter;
 }


 int myStringCompare(const char str1[][ARR_COLS], int row1, const char str2[][ARR_COLS], int row2){
     int i=0, p=0;
     while(p == 0){
         if (str1[row2][i] > str2[row2][i]){
             goto positive;
         }
        else if(str1[row2][i] < str2[row2][i]){
            goto negative;
        }
        else {
            if (str1[row1][i] == '\0') {
                goto even;
            }
            if (str1[row1][i] == str2[row2][i]){
                i++;
                p=0;
            }
        }
     }
    positive:
     return 1;
    negative:
     return -1;
    even:
     return 0;
 }


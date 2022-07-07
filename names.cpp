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

/*void myStringCopy (char destination [], const char source[]);

int myStringLength(const char str[]);

int myStringcompare(const char str1 [], const char str2[]);
 
void readNames(char inputfile[], char namesArray[ARR_ROWS][ARR_COLS]);

//void printNamesToTerminal(char namesArray[ARR_ROWS][ARR_COLS]);
*/
int main ( ) {
    ifstream inputStream;
    ofstream outputStream;
    char inputFile [8], /*outputFile [8],*/ namesArray[ARR_ROWS][ARR_COLS];
    cout << "What is the name of the input file? " << endl;
    cin >> inputFile;
    
    //cout << "What is the name of the output file? " << endl;
    //cin >> outputFile;
    
    inputStream.open(inputFile);
    /*outputStream.open(outputFile);
    outputStream.close();
    readNames(inputFile, namesArray);*/
    for (int i = 0; i < ARR_ROWS; i++){
      inputStream.getline(namesArray[i],ARR_COLS);
    }
    
    for (int m = 0; m < ARR_ROWS; m++){
        for (int n = 0; n < ARR_COLS; n++){
            cout << namesArray[m][n];
        }
        cout << endl;
    }
    
    //printNamesToTerminal(char namesArray[ARR_ROWS][ARR_COLS]);
    inputStream.close();
    return 0;
}

/*void readNames(char inputfile[8], char namesArray[ARR_ROWS][ARR_COLS]){
    for (int i = 0; i < ARR_ROWS; i++){
        for (int j = 0; i < ARR_COLS; j++){
            inputStream >> namesArray[i][j];
        }
    }
}

void printNamesToTerminal(char namesArray[ARR_ROWS][ARR_COLS]){
    for (int i = 0; i < ARR_ROWS; i++){
        for (int j = 0; i < ARR_COLS; j++){
              cout >> namesArray[i][j];
        }
        cout >> endl;
    }
}

void myStringCopy (char destination [], const char source[]){
    
}

int myStringLength(const char str[]){
    
}

int myStringcompare(const char str1 [], const char str2[]){
    
} */

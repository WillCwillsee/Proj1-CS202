//
//  names.cpp
//
//
//  Created by William Charles on 12/24/19.
//

#include <iostream>
#include <fstream>

using namespace std;

const int ARR_COLS = 9;
const int ARR_ROWS = 10;

/*Function Declaration*/

/*Takes in two character arrays and copies the content of the second one into the first one*/
void myStringCopy (char destination [ARR_ROWS][ARR_COLS], const char source[ARR_ROWS][ARR_COLS]);

/*Takes in a 2D character array and a row number and count the number of characters in that row.  Then it returns that number. */
int myStringLength(const char str[][ARR_COLS], int row);

/*Takes in two 2D character arrays and the row number for each string and compares which one should come first Alphabetically.  It returns a 1, -1. or a 0 depending on whether str1 has a higher, lower, or even value than str2, respectively.*/
int myStringCompare(const char str1[][ARR_COLS], int row1, const char str2[][ARR_COLS], int row2);

/*Takes a file name, and a 2D character array.  Then inputs the contents of the file into the 2D array, line by line. */
void readNames(ifstream& inputStream, char inputfile[], char namesArray[ARR_ROWS][ARR_COLS]);

/*Takes in a 2D character array and a 1D character array and prints each row of the 2D array preceded by one character in the 1D array*/
void printNamesToTerminal(char namesArray[ARR_ROWS][ARR_COLS], int nameOrder[]);

/*Takes in a four arrays.  The 2D array with the names and the 1D array with the order number, as well as a temporary storage array for each of them.  The function then sorts the 2D array of names alphabetically.*/
void sortNamesAlphabetic(char namesArray[ARR_ROWS][ARR_COLS], char tempNames[ARR_ROWS][ARR_COLS], int nameOrder[], int tempOrder[]);

/*Takes in a four arrays.  The 2D array with the names and the 1D array with the order number, as well as a temporary storage array for each of them.  The function then sorts the 2D array of names by length and alphabetically.*/
void sortNamesByLength(char namesArray[ARR_ROWS][ARR_COLS], char tempNames[ARR_ROWS][ARR_COLS], int nameOrder[], int tempOrder[]);

/*Takes in an output file name, a 2D character array of names and a 1D array of the original order of the names.  It prints the order first and then the Name, line by line*/
void printNamesToFile(ofstream& outputStream, char outputFile[], char namesArray[ARR_ROWS][ARR_COLS], int nameOrder[]);

/*Main program body*/
int main ( ) {
    
    /*Variable declarations*/
    ifstream inputStream;
    ofstream outputStream;
    char inputFile [20], outputFile [20], namesArray[ARR_ROWS][ARR_COLS] = { }, tempNames[ARR_ROWS][ARR_COLS] = { };
    int nameOrder[11] = {0,1,2,3,4,5,6,7,8,9}, tempOrder[11] = {0,1,2,3,4,5,6,7,8,9};
    
    /*Prompts the user to enter the input and output filenames and stores them for use later*/
    cout << "What is the name of the input file? " << endl;
    cin >> inputFile;
    cout << "What is the name of the output file? " << endl;
    cin >> outputFile;
    
    /*Opens the input file and stores the contents in a 2D array*/
    inputStream.open(inputFile);
    readNames(inputStream, inputFile, namesArray);
    inputStream.close();
    
    /*Prints the names to the terminal in the inputfile in their original order*/
    cout << "Unsorted Data (Original Input Order and Name)" << endl << "=============================" << endl;
    printNamesToTerminal(namesArray, nameOrder);
  
    /*Sorts the names in the 2D array alphabetically and then prints them to the terminal preceded by their original order */
    sortNamesAlphabetic(namesArray, tempNames, nameOrder, tempOrder);
    cout << "Alphabetcially Sorted Data (Original Input Order and Name)" << endl << "=============================" << endl;
    printNamesToTerminal(namesArray, nameOrder);
    
    /*Sorts the names in the 2D array by length and alphabetically then prints them to the terminal preceded by their original order */
    sortNamesByLength(namesArray, tempNames, nameOrder, tempOrder);
    cout << "Sorted-by-Length –and– Alphabetically Data (Original Input Order and Name)" << endl << "=============================" << endl;
    printNamesToTerminal(namesArray, nameOrder);

    /*Stores the names in the 2D array, sorted by length and alphabetically, to the output file given by the user.*/
    outputStream.open(outputFile);
    printNamesToFile(outputStream, outputFile, namesArray, nameOrder);
    outputStream.close();
    
    return 0;
}

/*Function Implementation*/

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
        if (str1[row1][i] > str2[row2][i]){
            goto positive;
        }
        else if(str1[row1][i] < str2[row2][i]){
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
    for (int z = 0; z < ARR_ROWS-1; z++){
        for (int m = 0; m < ARR_ROWS-1; m++){
            if (myStringCompare(namesArray, m, namesArray, m+1) > 0){
                tempOrder[m] = nameOrder[m];
                nameOrder[m] = nameOrder[m+1];
                nameOrder[m+1] = tempOrder[m];
                for (int n = 0; n < ARR_COLS-1; n++){
                    tempNames[m][n] = namesArray[m][n];
                    namesArray[m][n] = namesArray[m+1][n];
                    namesArray[m+1][n] = tempNames[m][n];
                    
                }
            }
        }
    }
}

void sortNamesByLength(char namesArray[ARR_ROWS][ARR_COLS], char tempNames[ARR_ROWS][ARR_COLS], int nameOrder[], int tempOrder[]){
    for (int z = 0; z < ARR_ROWS-1; z++){
        for (int m = 0; m < ARR_ROWS-1; m++){
            if (myStringLength(namesArray, m) > myStringLength(namesArray, m+1)){
                tempOrder[m] = nameOrder[m];
                nameOrder[m] = nameOrder[m+1];
                nameOrder[m+1] = tempOrder[m];
                for (int n = 0; n < ARR_COLS-1; n++){
                    tempNames[m][n] = namesArray[m][n];
                    namesArray[m][n] = namesArray[m+1][n];
                    namesArray[m+1][n] = tempNames[m][n];
                    
                }
            }
            else if (myStringLength(namesArray, m) == myStringLength(namesArray, m+1)){
                if (myStringCompare(namesArray, m, namesArray, m+1) > 0){
                    tempOrder[m] = nameOrder[m];
                    nameOrder[m] = nameOrder[m+1];
                    nameOrder[m+1] = tempOrder[m];
                    for (int n = 0; n < ARR_COLS-1; n++){
                        tempNames[m][n] = namesArray[m][n];
                        namesArray[m][n] = namesArray[m+1][n];
                        namesArray[m+1][n] = tempNames[m][n];
                    }
                }
            }
        }
    }
}


void printNamesToFile(ofstream& outputStream, char outputFile[], char namesArray[ARR_ROWS][ARR_COLS], int nameOrder[]){
    
    for (int m = 0; m < ARR_ROWS; m++){
        outputStream << nameOrder[m] << " ";
        for(int n = 0; n < ARR_COLS; n++){
            outputStream << namesArray[m][n];
        }
        outputStream << endl;
    }
    
}

/*
Concept-
File handling is used to store data permanently in a computer
Using file handling we can store our data in secondary memory (Hard disk).
-------------------------------------------
How to achieve the File Handling
For achieving file handling we need to follow the following steps:-
    STEP 1-Naming a file
    STEP 2-Opening a file
    STEP 3-Writing data into the file
    STEP 4-Reading data from the file
    STEP 5-Closing a file.
__________________________________________________________________________________
                                  ios
                                   |
    istream<-----------------------|------------------------->  ostream
       |  |                        |                          |          |
       |  |                     iostream                      |          |
       |  *ifstream                 |                       *ofstream    |
       |                         *fstream                                |
       |                                                      ostream_withassign
    istream_withassign

Streams-
    1. streams are nothing but the flow of data in a sequence.
    --------------------------------------------------------------
    1.  ofstream-
    The ofstream is derived from the ostream class.
    It provides the output stream to operate on file. The output stream objects can be used to write the sequences of characters to a file. This class is declared in the fstream header file. 
*/


#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
    ofstream fout;
    fout.open("sample2.txt");
    getch();
    fout<<"Hello i'm Rajat";
    getch();
    fout.close();
    getch();

    return 0;
}
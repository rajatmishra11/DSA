/*
    File Opening Modes-
     ios::in                 input/read
     ios::out               output/write
     ios::app               append
     ios::ate               update
     ios::binary            binary

     ---------------------------------------
     Where to write modes?
     as a second argument of open() function.
     ofstream fout;
     fout.open("file name", file_opening_mode);
     ifstream fin;
     fin.open("file name ", file_opening_mode);
     fstream file;
     file.open("file name", file_opening_mode);
    ---------------------------------------
    Text Mode v/s Binary Mode-
        1. text mode is default opening mode.
        2.  Binary mode can be specified with ios::binary
*/
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("sample2.txt",ios::app);
    return 0;
}
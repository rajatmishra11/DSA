

#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;



/*
tellg()-
    1.  defined in istream class
    2.  its prototype is-
        - streampos tellg()
    3.   returns the position of the current character in the
        input stream.
    ---------------------------------------------------------

tellp()-
    1.  defined in ostream class
    2.  its prototype is
        - streampos tellp()
    3.  returns the position of the current charcter in the output
        stream.
*/

int main()
{
    /*
    ifstream fin;
    char ch;
    fin.open("sample2.txt");
    int pos = fin.tellg();
    cout << pos;

    fin>>ch;
    pos = fin.tellg();
    cout << pos;

    fin >> ch;
    pos = fin.tellg();
    cout << pos;
    getch();
    //012
    */

    ofstream fout;
    char ch;
    fout.open("sample2.txt", ios::app);
    int pos;
    pos=fout.tellp();
    cout<<pos;
    //0        why?
    fout<<" Jai Shree Ram";
    fout.close();
    return 0;
}
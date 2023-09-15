/*
    seekg()-
        1.  defined in istream class
        2.  its prototype is -
            -istream & seekg(streampos pos);
            -istream & seekg(stream)
        3.  pos is a new absolute position within the 
            stream(relative to the begining).
        4.  off is offset value, relative to the way parameter.
        5.  way values ios_base::beg,
                       ios_base::cur,
                       ios_base::end.
        -------------------------------------------------------------
    seekp()-
        1.  defined in ostream class.
        2.  its prototype is:
            -ostream & seekp(streampos pos);
            -ostream & seekp(streamoff off, ios_base::seekdir way);
        3.  pos is new absolute position within the stream
            (realative to the begining).
        4.  off is offset value, realative to the way parameter.
        5.  way values ios_base::beg,
                       ios_base::cur,
                       ios_base::end

*/
// Hello i'm Learning File Handling in C++.Jai Shree Ram Jai Shree Ram Jai Shree Ram Jai Shree Ram Jai Shree Ram
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(){


    /*
    ifstream fin;
    fin.open("sample2.txt");

    cout<<fin.tellg()<<endl;
    cout<<char(fin.get());
    cout << fin.tellg() << endl;
    cout << char(fin.get());
    cout << fin.tellg() << endl;


    fin.seekg(0);
    //get pointer ko 0 pe le aaega seekg()
    cout << char(fin.get());
    cout << fin.tellg() << endl; //1 pr

    fin.seekg(6);
    // get pointer ko 6 pe le aaega seekg()
    cout << char(fin.get());
    cout << fin.tellg() << endl; //7 pr

    fin.seekg(3, ios_base::cur);
    // current positon se get pointer ko 3 aage pe le aaega seekg()
    cout << char(fin.get());
    cout << fin.tellg() << endl; //

    fin.seekg(4, ios_base::beg);
    // current positon jo ab begin se get pointer ko 3 aage pe le aaega seekg()
    cout << char(fin.get());
    cout << fin.tellg() << endl; //

    fin.seekg(-33, ios_base::end);
    // current positon last se pahele get pointer ko 33 aage pe le aaega seekg()
    cout << char(fin.get());
    cout << fin.tellg() << endl; //
    */

   ofstream fout;
   fout.open("sample2.txt", ios::ate|ios::app);
   cout<<fout.tellp()<<endl;
   fout<<"ABCDE";
   cout<<fout.tellp()<<endl;
   fout.close();
   
   //same as above
    return 0;
}
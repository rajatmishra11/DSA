#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
    ifstream fin;
    char ch;
    fin.open("sample2.txt");
    // fin>>ch;
    // while(!fin.eof())
    // {
    //     cout<<ch;
    //     fin>>ch;
    // }
    // fin.close();  space is not considered

    ch=fin.get();
    while(!fin.eof())
    {
        cout<<ch;
        ch=fin.get();
    }
    fin.close();

    getch();
    return 0;
}
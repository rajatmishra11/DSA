/*
Key difference cpp vs c
2. C++ holds Encapsulation Properties in structures-  
    a) Data hiding feature is allowed in C++ structure.
    b) In C++, we can define a constructor for a structure.
    c) We can define member functions inside structures which are
    functions that operate on the data contained in the structure.
  
*/

#include<bits/stdc++.h>
using namespace std;
 

struct book
    {
        int bookid;
        char title[20];
        float price;

        //member function
        void input()
        {
            cout<<"Enter the id, title, price\n";
            cin>>bookid>>title>>price;
        }

        void display()
        {
            cout<<"SrNo. "<<bookid<<" ,Title :"<<title<<", $"<<price<<endl;
        }
    };

int main()
{

    //3.Object of a structure can be accessed using the “dot” notation in C++.
    book b1;
    b1.input();
    b1.display();

    return 0;
}
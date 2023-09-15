/*
Key difference cpp vs c
3. Data Security-
    a) Use of Access Specifiers
        private, public
4. We can define an object of a structure using the “new” operator.
5. We can define an object of a structure using the “new” operator.
6. In C++, we can define default values for the members of a structure.
7. C++ structures can have static members.
    
*/

#include<bits/stdc++.h>
using namespace std;
 

struct book
    {   
        private:
            int bookid;
            char title[20];
            float price;

        //member function
        public:
            void input()
            {
                cout<<"Enter the id, title, price\n";
                cin>>bookid>>title>>price;
                if(bookid<0) bookid= -bookid;
                if(price<0) price=-price;
            }

            void display()
            {
                cout<<"SrNo. "<<bookid<<" ,Title :"<<title<<", $"<<price<<endl;
            }
    };

int main()
{
    book b1;
    b1.input();
    b1.display();
    
    //private members can't be changed by outside
    book b2;
    // b2.bookid=-9;
    // error: structure3.cpp:16:17: note: declared private here      
    //      int bookid;

    return 0;
}
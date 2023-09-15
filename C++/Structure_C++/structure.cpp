#include <bits/stdc++.h>
using namespace std;
//structure in cpp->
/*
key difference in cpp v/s c
1. In C++,we do not need to use ‘struct’ keyword for declaring variables.
 
*/



struct book{
    int bookid;
    char title[20];
    float price;
};

book input(){
    book b;
    cout<<"Enter book_id, book_tiltle, book_price:"<<endl;
    cin>>b.bookid>>b.title>>b.price;
    return b;
}

void display(book b){
    cout<<"Serial Number: "<<b.bookid<<" , Title: "<<b.title<<", $f"<<b.price<<endl;
}
int main(){
    //taking input via 
    //1. initialise structure ={arg1, arg2, arg3};
    book b1= {1, "Gita", 340.6};
    display(b1);

    //2. using . operator
    book b2;
    b2.bookid=2;
   // b2.title="Mahabharata";  error - becoz string can't be pushed into chararray
    strcpy(b2.title, "Mahabharata");
    b2.price=670.7;
    display(b2);
    //3. by a special input() function that return structure named book
    book b3;
    b3= input();
    display(b3);
    return 0;
}
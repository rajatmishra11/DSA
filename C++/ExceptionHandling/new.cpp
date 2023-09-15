/*
    Execption Handling in C++
    ________________________________
    1.  C++ provides a built in error handling meachanism
        that is called exception handling
    2.  using exception handling , you can more easily manage
        and respond to runtime errors.
    ________________________________
    Exceptions-
            1.  is any abnormal behaviour, run time error.
            2.  are off beat situation in your program where
                program should be ready to handle it with appropriate
                response.
    __________________________________
    Keywords- try, catch, throw :-
    try-
        1.  Program statements that you want to monitor for exceptions
            are contained intry block.
        2.  if any exception occurs within the try block
            it is thrown (using throw).
        3.  The Exception is caught, using catch and processed.

    catch- 
        1.  When an exception is caught, arg will recieve its value.
        2.  If you don't need access to the exception itself, specify
            only type in the catch clause- arg is optional.
        3.  any type of data can be caught, including classes that you create.

    throw-
        1.  the general form of the throw staement is-
            throw exception;
        2.  Thrrow must be executed either within the try block
            proper or from any function that the code within the
            block calls.
*/

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    cout << "Welcome Coders!!";

    /*
    try
    {
        throw 10.9;
        cout << "\nIn Try";
    }
    catch (int e)
    {
        cout << "\nI'm Integer..Exception-No. " << e;
    }
    catch(double e)
    {
        cout<<"\nI'm double..Exception-No."<<e;
    }
    */
  

//    int i=2;
//     try
//     {
//             if(i==1) throw 1;
//             if(i==2)  throw 2;
//             if(i==3) throw 3;
//             cout<<"I'm in try block\n";
//     }
//     catch(int e)
//     {
//         cout<<"\nException no:"<<e<<endl;
//     }

    int i=1;
    try
    {
            if(i==1) throw "hello";
            if(i==2)  throw 'o';
            if(i==3) throw 3;
            cout<<"I'm in try block\n";
    }
    catch(...)
    {
        cout<<"\nException :"<<endl;
    }

    cout << "\nLast Line";
    return 0;
}
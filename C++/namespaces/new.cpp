/*
    What is Header Files-
        1. Set of predefined standard library function.
        2.  may or may not use (.h) as the extension.
        3.  we request to use a header files in our program
            by including it with the preproccesing directive
            #include
    ---------------------------------------------------------------------------
    Function Declaration- prototype, name, return type,type of arg, no. of arg.
    Function Defintion- Actual Coding, Memory Allocation.
    ---------------------------------------------------------------------------
    Note:-
    Header file- conatins Declaration only either fun, variables, classes.
    Library File- Fn Defintion(Coding).

    ---------------------------------------------------------------------------
    iostream - is a file conatining one of namespace having name std, in which
                cin and cout is declared.
                that's why we use,
                #include <iostream>
                using namespace std;
    ___________________________________________________________________________
    ----------------------------------------------------------------------------
    ***************************************************************************
    namespaces-
        1.  is a group of declarartions.
        2. namespace is a keyword.
        3. is a container for identifiers.
        4. it puts the names of its members in a distinct space
            so that they don't conflict with the names in other namespaces or
            global namespace.

        5. Creation-
        namespace namespace_name
        {
            //declaration
            ....
            ....
            ....
        }

        6. Namespace defintion doesn't terminates with a semicolon
           like in class defintiion.
        7. The namespace defintion must be done at global scope, or
           nested inside another namespace.
        8. You can use an alias name for your namespace name, for
            ease of use-
            namespace ms    =   MYspace;
        9. Nmaespace is not class, you can;t make an object.
        10. unnamed nmaespaces too.
          namespace {
                //declarations
          }
        11. namespaces can be extended-
                namespaces drfintion can be continued and extended over multiple files,
                they are not redefined multiple files, they are not redefinded or overriden.
    -----------------------------------------------------------------------------
    Accessing members of namespace-
        any name(indentifier) declared in a namespace can be explicitly specified using the
        namespaces's name and the scope resolution :: operator with the identifier.
    -------------------------------------------------------------------------------------
    The using directive;
     -  using keyword allows us to import an entire namespace into your program
     with a global scope.
     -  it can be used to import a namespace into another namespace
        or any program.
*/
#include <iostream>

// using namespace std;
// if we didnt use this
// fo every cout and cin
// we have to use std::cin<<" "; or std::cout<<" ";

using namespace std;

namespace Myspace
{
    int a;
    int f1();
    class A
    {
    public:
        void fun1();
    };
}
/// defining variable , fun and class of namespace.
int Myspace::f1()
{
    cout << "Hello i'm function of namespace\n";
}

void Myspace::A::fun1()
{
    cout << "I'm class A function of MySpace\n";
}

using namespace Myspace;

int main()
{
    // namespace myspace; wrong-> shoul be global

    // a=5;  error a ka apne scope mein acesible hai

    Myspace::a = 5;
    /*
    if we use
    using namespace Myspace;
    a is directly accesible;
    a=5;                      //right
    */

    cout << a << endl;
    f1();
    A obj;
    obj.fun1();

    return 0;
}
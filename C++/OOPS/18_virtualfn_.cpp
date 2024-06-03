#include <bits/stdc++.h>
using namespace std;

/*
Base Class Pointer -
    1.  Base Class Pointer can point to the object of any class
        of its descendant class.
    2.  but it's converse is not true.

*/

class A
{
public:
    void f1()
    {
        cout << "Mai A ka f1 Hun" << endl;
    }
    void f2()
    {
        cout << "Mai A ka f2 Hun" << endl;
    }
};

class B : public A
{
public:
    void f1()
    {
        // method overriding -> same protype
        cout << "Mai B ka f1 hun" << endl;
    }
    void f2(int x)
    {
        // method hiding-> same name- but different arg.
        cout << "Mai B ka f2 Hun" << endl;
    }
};

int main()
{

    A *ptr;
    B obj;
    obj.f1(); // early binding by compiler
    // obj.f2();    //B pe jaaegya -> error (arg nhi diya hai)
    ptr = &obj;
    obj.f1();
    obj.f2(9);

    return 0;
}

/*
In C++, the `virtual` keyword is used to enable polymorphism, which allows functions to be overridden in derived classes and ensures that the correct function is called based on the actual type of the object, not the type of the pointer/reference.

### How the `virtual` Keyword Works

1. **Declaration:**
   - When a member function is declared as `virtual` in a base class, it indicates that the function can be overridden in any derived class.
   ```cpp
   class Base {
   public:
       virtual void display() {
           std::cout << "Display from Base" << std::endl;
       }
   };
   ```

2. **Override in Derived Class:**
   - Derived classes can override the virtual function to provide their own implementation.
   ```cpp
   class Derived : public Base {
   public:
       void display() override {  // 'override' is optional but good practice
           std::cout << "Display from Derived" << std::endl;
       }
   };
   ```

3. **Polymorphic Behavior:**
   - When you call a virtual function using a base class pointer or reference that actually points to a derived class object, the derived class's version of the function is invoked.
   ```cpp
   Base* b = new Derived();
   b->display();  // Output: "Display from Derived"
   delete b;
   ```

### Purpose in Polymorphism

The primary purpose of the `virtual` keyword is to support **runtime polymorphism**. This is achieved through:

1. **Virtual Table (VTable):**
   - When a class has virtual functions, the compiler creates a virtual table (vtable) for the class. This table holds pointers to the virtual functions of the class.
   - Each object of the class contains a pointer to its class's vtable, enabling dynamic dispatch.

2. **Dynamic Binding:**
   - The decision about which function to invoke is made at runtime based on the actual type of the object, not the type of the reference or pointer to the object.
   - This allows for flexible and extensible code, where you can add new derived classes without changing existing code that uses base class pointers or references.

### Example

Here's a complete example demonstrating how `virtual` works:

```cpp
#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Display from Base" << std::endl;
    }

    virtual ~Base() {}  // Virtual destructor for proper cleanup
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Display from Derived" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->display();  // Output: "Display from Derived"
    delete b;

    return 0;
}
```

### Key Points

- **Virtual Destructor:** If a base class has virtual functions, it should also have a virtual destructor to ensure proper cleanup of derived class objects.
- **Override Keyword:** Using `override` is good practice as it helps catch errors at compile time by ensuring the function is actually overriding a base class virtual function.
- **Pure Virtual Functions:** You can make a function pure virtual by setting it to `0`, making the class abstract and forcing derived classes to override the function.
  ```cpp
  class Base {
  public:
      virtual void display() = 0;  // Pure virtual function
  };
  ```

Using the `virtual` keyword appropriately helps achieve dynamic polymorphism, making your code more flexible and easier to extend.
*/
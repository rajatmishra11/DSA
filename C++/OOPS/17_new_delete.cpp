/*
SMA-
    1. Declarative statements- fixed memory space.
    2. Compile Time Allocation
    3. wastage of memeory space.
DMA-
    1. assigning memory space to a process or program
       at the time when program execution takes place.
    2. here reallocation and even freeing of used memory space is permitted.
    3. new keyword is used in C++.
    4. delete is used to free up memory that is hold by 
        variables which are dynamically created though new keyword.
        (data-type) pointer_name= new (data-type);
        delete (pointer name);
        

------------------------------------
    int *p= new int;           
        ^        ^
        |        |
p(static)       new ke baaad wala dynaamic variable hai
    float *q= new float;

    delete p;
    delete q;
-------------------------------------   
    Dynamic Array-
    int *q= new int[5];
    delete q[];
-------------------------------------
    Oops mein-
    Complex *ptr = new Complex;
*/
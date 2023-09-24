/*
Binary Heap->
    1.  used in Heap Sort.
    2.  implementd (Priority- Queue)
    3.  is a Complete Binary Tree.
        ( last level se pahele - Completely Filled)
        && (last level left to right filled honi chahiye)
    4.  internally implemented as Array.
        ek node jiska index i hai, to uska left , right aur parent-> ka index
        left[i]= 2*i+1;
        right[i]= 2*i+2;
        parent[i]= abs((i-1)/2);
-------------------------------------------------------------------------------
    Types- Min Heap && Max Heap.
    1. Min Heap->
        every node has value smaller than its descendents.
    2.  Max Heap->
        every node has vale greater than its descendents.
-------------------------------------------------------------------------------
    Min Heap Opeartion->
        1. Insertion of a key-
            Algo-
                1. Insert a key at last by increment size by 1.
                2.  Arrange The Heap-
                    check parent of ele-
                        if(ele < parent) swap;
                        stopping condn: when parent < ele or reached till root
        -----------------------------------------------------------------------
        2.  Heapify (Imp)
            Algo-
                1.  kisi index par heap voilate kar rha hoga prop. ko let say( i th).
                2. Call Min_Heapify( int index);
                3. extract min from node, node->left, & node->right.
                4.  swap(min_from_three , node);
                5. Call recursive for the child tree for which we got min.
        -----------------------------------------------------------------------
        3. GetMin-
            algo-
                return the minimum ele from MinHaep.
                return root,
                return arr[0];
        ------------------------------------------------------------------------
        3.  Extract_Min- (find min + remove from Heap)
            algo- min-ele is present at arr[0]
            1. swap(arr[0], arr[size-1]); swap 1st ele & last ele
            2. call MinHeapify(0)
        ------------------------------------------------------------------------
        4.  Descrese Key(int index, int key)
            ith index par value change karke value==key karni hai
            algo-
            1. pahele ith pos pr key daal do
            2. phir i ke liye swap wala concept
        ------------------------------------------------------------------------
        5.  delete(int key)

            - jo key delete krini hai-> uski jagah -ifinity daal do
            -   ExtractMin-> -infinty de dega usko bahar fe dega
            - kahatammmmmmmm....................
            algo-
                1. Decrese key(int i, int -INfinity)
                2.  ExtractMin()

*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    int *arr;
    int size;
    int capacity;

public:
    MinHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int parent(int i)
    {
        return abs((i - 1) / 2);
    }

    void insertkey(int i);
    void deletekey(int key);
    int extractMin();
    void MinHeapify(int index);
    void decreasekey(int i, int key);
    void printHeap();
};

void MinHeap::insertkey(int key)
{
    if (size == capacity)
        return;
    size++;
    arr[size - 1] = key;
    int i = size - 1;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void MinHeap::deletekey(int i)
{
    if (size == 0 or i >= size)
        return;
    decreasekey(i, INT_MIN);
    extractMin();
}

int MinHeap::extractMin()
{
    if (size == 0)
        return INT_MAX;
    if (size == 1)
    {
        size--;
        return arr[0];
    }
    int ans = arr[0];
    swap(arr[0], arr[size - 1]);
    size--;
    MinHeapify(0);
    return ans;
}

void MinHeap::MinHeapify(int i)
{
    // left index-
    int li = left(i);
    // right index-
    int ri = right(i);
    // parent index- i *khud hai
    int smallest = i;

    // check valid left
    if (li < size && arr[li] < arr[smallest])
    {
        smallest = li;
    }

    // check valid right
    if (ri < size && arr[ri] < arr[smallest])
    {
        smallest = ri;
    }

    // jo bhi aaya smallest aa gya-
    // agar smalest node pr na hai= swap
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::decreasekey(int i, int key)
{
    arr[i] = key;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void MinHeap::printHeap()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    MinHeap h(9);
    for (int i = 0; i < 9; i++)
    {
        int c;
        cout << "Enter case 1, 2, or 3: " << endl;
        int n;
        cin >> c;
        if (c == 1)
        {
            // isert key
            cout << "insert key to heap: ";
            cin >> n;
            h.insertkey(n);
        }

        if (c == 2)
        {
            // delete key-
            cout << "delete a key from heap: ";
            cin >> n;
            h.deletekey(n);
        }

        if (c == 3)
        {
            // get min
            cout << "extract min from  heap: ";
            cout << h.extractMin() << endl;
        }
        cout << "heap is :";
        h.printHeap();
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 50

int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
}

int main() {
    int n = 4, m = 4;
    int M[MAX][MAX] = {{0 ,1, 1, 0},
                       {1, 1, 1, 1},
                       {1 ,1 ,1 ,1},
                       {1 ,1, 0, 0}};
                       
    cout << maxArea(M, n, m);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
//ignore diagonal(vo khud)
//1.who is celebrity->
//2.everyone knows him, and he knows no-one



bool knows(int a, int b,vector<vector<int> >& M ){
    if(M[a][b]==1) return 1;
    else return 0;
}

int celebrity(vector<vector<int> >& M, int n) 
{
    //1.celebrity ki row mein all zero
    //2.celebrity ki col mein all zero
    //except khud(diagonal);
    //har ele ki row and col O(n^2);
    //algo-
    //put all element in stack(index)
    //
    //A=s.top()
    //B=s.top()
    //if A know B remove A
    //if B know A remove B
    //jo bacha use push karo
    //aise last backa bo ho skta hai-> last mein check karo
    //verify

    stack<int>st;
    for(int i=0; i<n; i++){
        st.push(i);
    }
    while(st.size() > 1){
        int a=st.top();
        st.pop();

        int b=st.top();
        st.pop();

        if(knows(a,b,M)){
            st.push(b);
        }
        else {
            st.push(a);
        }
    }
    //----> vo lisi ko na janta hai
    bool rowcheck=0;
    int zerocount=0;
    int candi=st.top();
    for(int i=0; i<n; i++){
        if(M[candi][i]==0){
            zerocount++;
        }
    }
    if(zerocount==n){
        rowcheck=1;
    }
    //----> use sb jaante hai
    bool colcheck=0;
    zerocount=0;
    for(int i=0; i<n; i++){
        if(M[i][candi]==1){
            zerocount++;
        }
    }
    if(zerocount==n-1){
        colcheck=1;
    }
    if(rowcheck && colcheck) return candi;
    else return -1;
}

int main()
{

 int N = 3;
 vector<vector<int> >M= {{0 ,1, 0},
                        {0, 0 ,0}, 
                         {0, 1, 0}};
 cout<<celebrity(M,N);
 
    return 0;
}
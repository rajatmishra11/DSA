#include<bits/stdc++.h>
using namespace std;
 

//custom data type 
//1. store data
//2. store the index of row in main array
//3. position of element in that particular column
class node{
    public:
        int data;
        int i;  //row
        int j;  //col
        node(int data, int i, int j){
            this->data=data;
            this->i=i;
            this->j=j;
        }
};
//custom comparator
class mycmp{
    public:
    bool operator()(node *a, node* b){
        return a->data > b->data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //custom queue
        priority_queue<node*, vector<node*> , mycmp> minh;
        vector<int>ans;

        //push 1st elements of each coloums in 2d matrix->
        for(int i=0; i<k ; i++){
            node* temp= new node(arr[i][0], i, 0);
            minh.push(temp);
        }
        
        //step2-> jab tak heap khali nhi hai->
        while(minh.size()>0){
            //get value at the top of pq
            node* temp=minh.top();
            ans.push_back(temp->data);
            minh.pop();
            //fetch the index of both row and postion in that row
            int i=temp->i;
            int j=temp->j;
            //check boundation->
            //next position should not exceed the row size of that particular
            if(j+1< arr[i].size()){
                //then push the next element of same row 
                node* next=new node(arr[i][j+1], i, j+1);
                minh.push(next);
            }
        }
        //at last ans will contain k sorted array
        return ans;
    }
};



int main()
{

 vector<vector<int>>arr = {{3,4,5},{4,5,6},{7,8,9}};
 int k=3; 
 Solution obj;
 vector<int>output= obj.mergeKArrays(arr,k);
 
 for(int i=0; i<k*k ; i++){
    cout<<output[i]<<" ";
 }
    return 0;
}
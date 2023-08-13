#include<bits/stdc++.h>
using namespace std;
 
class Node
{   
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data=data;
            left=right=NULL;
        }
};

void preorder(Node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

int findpos(int ele, int in[],int start, int end){
    for(int i=start; i<=end; i++){
        if(ele==in[i]){
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int post[],int &idx, int in_start, int in_end, int n){
    if(idx<0 || in_start > in_end){
        cout<<"im returning null from base case"<<endl;
        return NULL;
    }
    int ele= post[idx--];
    Node *root= new Node(ele);
    int pos= findpos(ele, in,in_start, in_end);
    cout<<"im   " <<root->data<<" caaling my right"<<endl;
    root->right=solve(in , post, idx, pos+1, in_end, n);
    cout<<"im   "  <<root->data<<" caaling my left"<<endl;
    root->left=solve(in, post, idx,in_start, pos-1,n);
    cout<<"im returning "<<root->data<<endl;
    return root;
    

}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    //index last se start aur 0 ki or->
    int post_suru_piche_se= n-1;
    Node *ans=solve(in, post,post_suru_piche_se,0,n-1,n);
    return ans;
}

int main()
{
   int  in[] = {4 ,8 ,2 ,5 ,1 ,6 ,3 ,7,};
   int post[] ={8 ,4 ,5, 2, 6, 7, 3, 1};
    int n=sizeof(post)/sizeof(post[0]);
    Node *root=buildTree(in, post,n);
    cout<<"\n\n";
    preorder(root);
    return 0;
}
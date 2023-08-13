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
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}



int findpos(int ele, int in[], int start, int end){
    for(int i=start; i<=end; i++){
        if(ele==in[i]) return i;
    }
    return -1;
}

Node * solve(int in[], int pre[], int &idx, int in_start, int in_end, int n){
    if(idx>=n || (in_start > in_end)){
        return NULL;
    }
    int ele=  pre[idx];
    int pos=findpos(ele, in, in_start, in_end);
    Node *root= new Node(ele);
    idx++;
    //left call
    root->left= solve(in, pre, idx, in_start, pos-1, n);
    ///right call;
    root->right= solve(in, pre,idx,pos+1, in_end, n);
    return root;
}

 Node* buildTree(int in[],int pre[], int n)
    {
        int pre_idx=0;
        Node* ans=solve(in, pre, pre_idx, 0, n-1, n);
        return ans;
    }
int main()
{
    int in[]={7,3,11,1,17,3,18};
    int pre[]={1,3,7,11,3,17,18};
    int n=sizeof(pre)/sizeof(pre[0]);
    Node *root=buildTree(in, pre,n);
    preorder(root);
    return 0;
}
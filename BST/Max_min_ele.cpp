#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

node* inserttobst(node* &root, int d){
    
    //base case->
    if(root==NULL){
        root = new node(d);
        return root;
    }
    
    if(d > root->data){
        //go -right 
        root->right= inserttobst(root->right, d);
    }

    else{
        //go- left
        root->left= inserttobst(root->left, d);
    }

    return root;
}

void input(node *&root){
    int data;
    cin>>data;
    while(data!=-1){
        inserttobst(root, data);
        cin>>data;
    }
}

 int findMax(node *root)
    {
        if(root==NULL) return -1;
        if(root->right==NULL){
            return root->data;
        }
        return findMin(root->right);
    }
int findMin(node *root)
    {
        if(root==NULL) return -1;
        if(root->left==NULL){
            return root->data;
        }
        return findMin(root->left);
    }

int main()
{   
    node *root= NULL;
    cout<<"Enter data to create BST:"<<endl;
    input(root);
   cout<<findMax(root)<<", "<<findMin(root);
    return 0;
}
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

bool search(node* root, int x) {
    if(root==NULL) return 0;
    int val=root->data;
    if(val==x){
        return 1;
    }
    if(val<x){
        return search(root->right, x);
    }
    else{
        return search(root->left, x);
    }
}

int main()
{   
    node *root= NULL;
    cout<<"Enter data to create BST:"<<endl;
    input(root);
    cout<<"Enter the ele to search"<<endl;
    int n;
    cin>>n;
    cout<<search(root,n);
    
    return 0;
}
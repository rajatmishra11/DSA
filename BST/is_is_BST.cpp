#include<bits/stdc++.h>
using namespace std;
 

class node{
    public:
        int data;
        node *left;
        node *right;

        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

bool check(node *root, int min, int max){
    if(root==NULL) return 1;
    if(root->data >= min && root->data < max){
        //rec
        bool left= check(root->left, min, root->data);
        bool right= check(root->right, root->data, max);
        return left && right;
    }
    else return false;
}

bool isBST(node* root) 
    {  
        return check(root, INT_MIN, INT_MAX);
    }

int main()
{
    node *root=new node(14);
    root->left=new node(13);
    root->right=new node(15);
    root->left->left= new node(2);
    cout<< isBST(root);
    return 0;
}
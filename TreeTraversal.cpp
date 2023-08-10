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


void inorder(Node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}
int main()
{

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    cout<<"INORDER:\n";
    inorder(root);
    cout<<"\nPREORDER:\n";
    preorder(root);
    cout<<"\nPOSTORDER:\n";
    postorder(root);

    return 0;
}
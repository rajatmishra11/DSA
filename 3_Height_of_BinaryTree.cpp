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

int height(Node *root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(height(root->left),height(root->right));
}


int main()
{

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    cout<<height(root);
    return 0;
}
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

bool identical(Node *root, Node *root2){
    //base case
    if(root==NULL && root2==NULL){
        return true;
    }
    if(root==NULL && root2!=NULL) return false;
    if(root!=NULL && root==NULL) return false;
    
    bool left=identical(root->left , root2->left);
    bool right= identical(root->right, root2->right);
    bool val= root->data == root2->data;
    if (left && right && val){
        return true;
    } 
    else
    {   
        return false;
    }
    
}

int main()
{

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);

    Node* root2= new Node(1);
    root2->left= new Node(0);
    root2->right=new Node(3);
    root2->left->left= new Node(4);
    root2->left->right=new Node(5);
    root2->left->left->left=new Node(6);
    cout<<identical(root, root2);
    return 0;
}
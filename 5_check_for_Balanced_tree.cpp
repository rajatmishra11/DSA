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
    return max(height(root->left), height(root->right))+1;
}

//Function to check whether a binary tree is balanced or not.
//O(N^2)
bool isBalanced(Node *root)
{
    if(root==NULL){
        return 1;
    }
    bool left= isBalanced(root->left);
    bool right=isBalanced(root->right);
    
    //3rd condition
    bool diff= abs(height(root->left)- height(root->right)) <= 1;
    return (left && right && diff);
}

//O(N)
// {true, height_subtree_of_that_node};
pair<bool,int> isBalanced2(Node *root){
    if(root==NULL){
        pair<int,int> p=make_pair(true,0);
        return p;
    }
    pair<int,int>left= isBalanced2(root->left);
    pair<int,int>right= isBalanced2(root->right);

    bool leftans=left.first;
    bool rightans=right.first;
    bool diff= abs(left.second-right.second)<=1;

    pair<int,int> ans;
    ans.second=max(left.second, right.second)+1;

    if(leftans && rightans && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}

int main()
{

    Node* root= new Node(10);
    root->left= new Node(20);
    root->right=new Node(30);
    root->left->left= new Node(40);
    root->left->right=new Node(60);
        //           10
        //         /   \
        //       20    30 
        //     /   \
        //   40   60

    cout<<isBalanced(root)<<endl;

     cout<<isBalanced2(root).first;
    return 0;
}
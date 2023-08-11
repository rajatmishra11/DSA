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

pair<bool, int> isSumTree(Node *root){
    if(!root){
        pair<bool, int>p=make_pair(true,0);
        return p;
    }
    if(!root->left && !root->right){
        pair<bool, int>p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int> isLeftSumTree=isSumTree(root->left);
    pair<bool, int> isRightSumTree=isSumTree(root->right);

    bool leftSum= isLeftSumTree.first;
    bool rightSum= isRightSumTree.first;
    bool third= root->data== isLeftSumTree.second+ isRightSumTree.second;

    pair<bool,int> ans;
    if(leftSum && rightSum && third){
        ans.first=true;
        ans.second=root->data+ isLeftSumTree.second+ isRightSumTree.second;
    }
    else{
        ans.first=false;
    }
    return ans;
}


int main()
{

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    

    cout<<isSumTree(root).first<<endl;
    Node* root2= new Node(3);
    root->left= new Node(1);
    root->right=new Node(2);
    cout<<isSumTree(root2).first;
    return 0;
}
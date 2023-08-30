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

void levelorder2(node *root){
    cout<<"BFS OF TREE Level wise is-> "<<endl;
    queue<node*>q;
    q.push(root);
    //seperator is NULL push null to queue
    q.push(NULL);

    while(!q.empty()){
        node *temp=q.front();
        //cout<<temp->data<<" ";
        q.pop();
        if(temp==NULL){
            //prev level complete travese->
            cout<<endl;
            //leftout elements ke liye push NULL
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            //not null
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


int solve(node *root, int &i, int k ){
    //O(n)
   //base case->
    if(root==NULL) return -1;
   
    int left= solve(root->left, i, k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right, i, k);
}

int KthSmallestElement(node *root, int k) {
        // BST->inorder is sorted 
        int i=0;
        return solve(root, i, k);
}


int solve2(node *root, int &i, int k ){
    //O(n)
    //O(n)
   //base case->
    if(root==NULL) return -1;
    int right= solve2(root->right, i, k);
    if(right!=-1){
        return right;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve2(root->left, i, k);
}

int KthLargestElement(node *root, int k) {
        // BST->inorder is sorted 
        int i=0;
        return solve2(root, i, k);
}

int main()
{   
    node *root= NULL;
    cout<<"Enter data to create BST"<<endl;
    input(root);
    cout<<"Printing the BST"<<endl;
    levelorder2(root);
    int k;
    cout<<"Enter the kth value for kth smallest Number"<<endl;
    cin>>k;
    cout<<KthSmallestElement(root, k)<<endl;
    cout<<"Enter the kth value for kth largest Number"<<endl;
    int x;
    cin>>x;
    cout<<KthLargestElement(root,x);
    return 0;
}
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


void inorder(node *root,int target, vector<int>&ans){
    if(root==NULL) return ;
    inorder(root->left, target, ans);
    ans.push_back(root->data);
    inorder(root->right, target, ans);
}

int isPairPresent(node *root, int target)
{
    vector<int>ans;
    inorder(root, target, ans);
    int i=0, j=ans.size()-1;
    while(i<j){
        int sum= ans[i]+ans[j];
        if(sum==target ) return 1;
        else if( sum>target ) j--;
        else i++;
    }
    return 0;
}

int main()
{   
    node *root= NULL;
    cout<<"Enter data to create BST"<<endl;
    input(root);
    cout<<"Printing the BST"<<endl;
    levelorder2(root);
    int k;
    cout<<"Enter the val to check two sum"<<endl;
    cin>>k;
    cout<<isPairPresent(root, k);
    return 0;
}
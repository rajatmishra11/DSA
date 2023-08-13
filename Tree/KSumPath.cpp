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


void solve(Node *root, int k, int &count, vector<int>path, vector<vector<int>>&allpaths){
    //base case
    if(!root){
        return;
    }
    path.push_back(root->data);
    solve(root->left,k,count, path,allpaths);
    solve(root->right,k,count, path, allpaths);

    //check for k sum
    int sum=0;
    for(int i=path.size()-1; i>=0; i--){
        sum+=path[i];
        if(sum==k){
            count++;
            
        }
    }
    allpaths.push_back(path);
    path.pop_back();

}

int KsumPath(Node *root, int target, vector<vector<int>> &allpaths){
    int count=0;
    vector<int>path;
    solve(root, target,count, path,allpaths);
    return count;
}


int main()
{

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->left->right=new Node(5);
    root->left->left->left=new Node(6);
    int target=7;
    vector<vector<int>>allpaths;
    cout<<"No of Paths having k sum is :"<<KsumPath(root, target,allpaths)<<endl;
    for(int i=0; i< allpaths.size(); i++){
        for(int j=0; j< allpaths[i].size(); j++){
            cout<<allpaths[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}
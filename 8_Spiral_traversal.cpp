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

vector<int> spiral(Node *root){
    vector<int>res;
    cout<<"im fn call"<<endl;
    if(!root) return res;
    //pushing ist node
    queue<Node*>q;
    q.push(root);

    bool flag=1; //left_to_right=1;
    
    while(!q.empty()){
        int size=q.size();
        vector<int>temp(size);

        //level wise traversal
        for (int i = 0; i < size ; i++)
        {
            Node *front= q.front();
            q.pop();
    
            int index=0;
            if(flag){
                 index=i;
            }
            else{
                 index= size-i-1;
            }
            temp[index]=front->data;

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        flag=!flag;
        for(auto it: temp){
            res.push_back(it);
        }
        
    }
    return res;
}

 
int main()
{

    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->right->left= new Node(4);
    root->right->right=new Node(5);
    cout<<"im before fn call"<<endl;
    vector<int>ans = spiral(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
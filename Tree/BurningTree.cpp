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


    Node* createMapping(Node* root, int target, map<Node* ,Node*>&mp){
        Node* res=NULL;
        queue<Node*>q;
        q.push(root);
        mp[root]=NULL;
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front->data==target){
                res=front;
            }
            if(front->left){
                mp[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burntree(Node *root, map<Node*,Node*>&mp){
        map<Node*,bool> vis;
        queue<Node*>q;
        q.push(root);
        vis[root]=1;
        int ans=0;
        
        while(!q.empty()){
            int size=q.size();
            bool flag=0;
            for(int i=0; i<size; i++){
                Node* front=q.front();
                q.pop();
                
                if(front->left && !vis[front->left]){
                    flag=1;
                    q.push(front->left);
                    vis[front->left]=1;
                }
                
                if(front->right && !vis[front->right]){
                    flag=1;
                    q.push(front->right);
                    vis[front->right]=1;
                }
                
                if(mp[front] && !vis[mp[front]]){
                    flag=1;
                    q.push(mp[front]);
                    vis[mp[front]]=1;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
    
  
    int minTime(Node* root, int target) 
    {
       map<Node*, Node*>mp;
       Node* targetNode= createMapping(root, target, mp);
       int ans=burntree(targetNode, mp);
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
    int target=5;
    cout<<minTime(root,target);
    return 0;
}


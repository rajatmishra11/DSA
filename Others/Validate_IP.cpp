/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
    public:
    
   bool check(string s) {
            // code here
      int n=s.size();
      if(n<=0 or n>3){
        return false;
      }
      if(s[0]=='0' and n>1) return false;
      int p=stoi(s);
      if(p>=0 and p<=255) return true;
      return false;
        }
    
    
        int isValid(string s) {
            string temp="";
            bool flag=true;
            int count=0;
            s+='.';
            for(int i=0; i<s.size(); i++){
                if((s[i]<='z' && s[i]>='a') or (s[i]<='Z' && s[i]>='a')) return 0;
                temp+=s[i];
                if(s[i]=='.'){
                    temp.pop_back();
                    //cout<<temp<<endl;
                    flag=flag and check(temp);
                    temp="";
                    count++;
                }
            }
            if(flag==true and count==4) return 1;
            else return 0;
        }
}; 

int main()
{
    Solution obj;
    string str;
    cin>>str;
    cout<< obj.isValid(str);
    return 0;
}
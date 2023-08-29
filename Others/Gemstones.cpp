#include<bits/stdc++.h>
using namespace std;
 
/* https://www.hackerrank.com/challenges/gem-stones/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign*/

int gemstones(vector<string> arr) {
    vector<int>mp(26,0);
    for(int i=0; i<arr.size(); i++){
        string temp=arr[i];
        sort(temp.begin(), temp.end());
        char prev='$';
        for(int j=0; j<temp.size(); j++){
            char ch= temp[j];
            if(ch!=prev){
                mp[ch-'a']+=1;
                prev=ch;
            }
        }
    }

    int count=0;
    for(int i=0; i<26; i++){
        if(mp[i]>=arr.size()){
            count++;
        }
    }
    return count;
}

int main()
{
 vector<string>arr={"abcdde", "baccd", "eeabg"};
 cout<<gemstones(arr);
    return 0;
}
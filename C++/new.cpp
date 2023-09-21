#include <iostream>
using namespace std;

#include <map>


void solve(string sentence)
{
    // map to store word and the frequency-
    map<string, int>mp;
    string word = "";
    for(int i=0; i<sentence.size(); i++)
    {
        if(sentence[i]==' ' or sentence[i]=='.')
        {
            mp[word]++;
            word="";
        }
        else
        {
            word.push_back(sentence[i]);
        }
    }
    //printing the repeated words-
    for(auto it: mp)
    {
        string word=it.first;
        int count= it.second;
        if(count>1){
            cout<<word<<"-occur-"<<count<<" times\n";
        }
    }
}

int main()
{
    
 string sentence;
 getline(cin, sentence);
 solve(sentence);

 return 0;
}
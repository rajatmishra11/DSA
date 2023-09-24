/*
    What is a Trie-
        1.  is a type of serch tree for sorting and searching
            a specific key from a set.
        2.  multi-way tree used for storing strings over an alphabet.
        3.  Terminal node- (last node- word)
            */

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    private:
        char data;
        TrieNode* children[26];
        bool isTerminal;
    public:
    TrieNode(char ch)
    {
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

int main()
{

 
 
 
    return 0;
}
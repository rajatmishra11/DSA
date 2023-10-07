#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    // Data structures used here-
    // 1. (node)-> (key , val , left pointer, right pointer)
    class node
    {
    public:
        int key;
        int val;
        node *prev;
        node *next;

    public:
        node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    // 2. map of <key , node>
    unordered_map<int, node *> mp;
    // max capacity of cache->
    int capacity;
    // dummy nodes
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    // Function to return value corresponding to the key.
    int GET(int key)
    {
        if (mp.find(key) != mp.end())
        {
            node *resnode = mp[key];
            int res = resnode->val;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            node *existingnode = mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        if (mp.size() == capacity)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key] = head->next;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

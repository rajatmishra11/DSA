class MyHashMap
{

private:
    vector<list<pair<int, int>>> mp;
    int size;

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        size = 100001;
        mp.resize(size);
    }

    // other fn
    int hash(int key)
    {
        return key % size;
    }
    list<pair<int, int>>::iterator search(int key)
    {
        int i = hash(key);
        auto it = mp[i].begin();
        while (it != mp[i].end())
        {
            if (it->first == key)
                return it;
        }
        return it;
    }

    /** value will always be non-negative. */

    void put(int key, int value)
    {
        int i = hash(key);
        remove(key);
        mp[i].push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it == mp[i].end())
            return -1;
        else
            return it->second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int i = hash(key);
        auto it = search(key);
        if (it != mp[i].end())
            mp[i].erase(it);
    }
};
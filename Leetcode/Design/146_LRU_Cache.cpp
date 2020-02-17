// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
// it should invalidate the least recently used item before inserting a new item.
// The cache is initialized with a positive capacity.
// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:
// LRUCache cache = new LRUCache( 2 /* capacity */ );
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

// https://leetcode.com/problems/lru-cache/

// *************************************************************************************************************
// Approach - list for LRU key ; Map for key and key Iter ; Map for Key and Val
// *************************************************************************************************************

typedef list<int>::iterator LI;

class LRUCache {
private:
    int cacheCapacity;
    list<int> keyList;                                          // List of keys MRU....LRU
    unordered_map<int, LI> keyIterMap;                          // map for key and key iter in keyList
    unordered_map<int, int> keyValMap;                          // map for key and value
    
    void updateCache(const int& key)
    {
        if(keyValMap.count(key) != 0)                           // if key found, erase entry in keyList
            keyList.erase(keyIterMap[key]);
        
        keyList.push_front(key);                                // Add key at front of keyList
        keyIterMap[key] = keyList.begin();                      // Update key Iter map
    }
    
    void evict()
    {
        int lruKey = keyList.back();                            // Get last key from keyList = LRU
        keyIterMap.erase(lruKey);                               // Remove entries from both maps
        keyValMap.erase(lruKey);
        keyList.pop_back();                                     // Remove entry from keyList
    }
    
public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        if(keyValMap.count(key) == 0)
            return -1;
        
        updateCache(key);
        return keyValMap[key];
    }
    
    void put(int key, int value) {
        if(keyValMap.count(key) == 0 && keyValMap.size() == cacheCapacity)
            evict();

        updateCache(key);
        keyValMap[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// *************************************************************************************************************
// Approach - list for LRU key ; Map for key and pair of value and key Iter
// *************************************************************************************************************

typedef list<int>::iterator LI;

class LRUCache {
private:
    int cacheCapacity;
    list<int> keyList;                                          // list of keys
    unordered_map<int, pair<int, LI>> cache;                    // key = key ; val = pair (value and iter from keyList)
    
    void updateCache(const int& key)
    {
        auto keyIter = cache[key].second;                       // Get keyList iterator for key from map
        keyList.erase(keyIter);                                 // Remove entry from keyList : O(1) operation
        keyList.push_front(key);                                // Add the key to front of keyList
        cache[key] = {cache[key].first, keyList.begin()};       // Update the cache map
    }
    
public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        updateCache(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            updateCache(key);
        }
        else
        {
            if(cache.size() == cacheCapacity)
            {
                int keyVal = keyList.back();
                cache.erase(keyVal);
                keyList.pop_back();
            }
            keyList.push_front(key);                            // Add the key to front of keyList
        }
        
        cache[key] = {value, keyList.begin()};                  // Update the cache map
    }
};
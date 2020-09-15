// Design a HashMap without using any built-in hash table libraries.

// To be specific, your design should include these functions:

// put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
// get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

// Example:
// MyHashMap hashMap = new MyHashMap();
// hashMap.put(1, 1);          
// hashMap.put(2, 2);         
// hashMap.get(1);            // returns 1
// hashMap.get(3);            // returns -1 (not found)
// hashMap.put(2, 1);          // update the existing value
// hashMap.get(2);            // returns 1 
// hashMap.remove(2);          // remove the mapping for 2
// hashMap.get(2);            // returns -1 (not found) 

// Note:
// All keys and values will be in the range of [0, 1000000].
// The number of operations will be in the range of [1, 10000].
// Please do not use the built-in HashMap library.

// https://leetcode.com/problems/design-hashmap/

#define SETSIZE 1000

int getHash(int x)
{
    return x % SETSIZE;
}

struct listNode{
    int key;
    int value;
    listNode* next;
    
    listNode(int k, int v) : key(k), value(v), next(NULL) {}
};

class MyHashMap {
    listNode* arr[SETSIZE];
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for(int i = 0; i < SETSIZE; i++)
            arr[i] = NULL;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = getHash(key);

        listNode* newNode = new listNode(key, value);

        if(arr[idx] == NULL)
            arr[idx] = newNode;
        else
        {
            listNode* iter = arr[idx];
            
            // check if key is already present. If yes, don't add again
            while(iter != NULL)
            {
                if(iter->key == key)
                {
                    iter->value = value;
                    delete newNode;
                    return;
                }
                
                iter = iter->next;
            }
            
            iter = arr[idx];

            while(iter->next != NULL)
                iter = iter->next;

            iter->next = newNode;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = getHash(key);
        
        listNode* iter = arr[idx];
        
        while(iter != NULL)
        {
            if(iter->key == key)
                return iter->value;
            
            iter = iter->next;
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = getHash(key);
        
        listNode* iter1 = arr[idx];
        listNode* iter2 = ( arr[idx] != NULL ) ? arr[idx]->next : NULL;
        
        // element is at head
        if(iter1 != NULL && iter1->key == key)
        {
            listNode* tmp = arr[idx];
            arr[idx] = arr[idx]->next;
            
            delete tmp;
            tmp = NULL;
        }
        // element is not at head
        else
        {
            while(iter2 != NULL && iter2->key != key)
            {
                iter2 = iter2->next;
                iter1 = iter1->next;
            }
            
            if(iter2 == NULL)
                return;
            
            listNode* tmp = iter2;
            iter1->next = iter2->next;
            
            delete tmp;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
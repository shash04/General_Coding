// Design a HashSet without using any built-in hash table libraries.

// To be specific, your design should include these functions:

// add(value): Insert a value into the HashSet. 
// contains(value) : Return whether the value exists in the HashSet or not.
// remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

// Example:

// MyHashSet hashSet = new MyHashSet();
// hashSet.add(1);         
// hashSet.add(2);         
// hashSet.contains(1);    // returns true
// hashSet.contains(3);    // returns false (not found)
// hashSet.add(2);          
// hashSet.contains(2);    // returns true
// hashSet.remove(2);          
// hashSet.contains(2);    // returns false (already removed)

// Note:
// All values will be in the range of [0, 1000000].
// The number of operations will be in the range of [1, 10000].
// Please do not use the built-in HashSet library.

// https://leetcode.com/problems/design-hashset/

#define SETSIZE 1000

int getHash(int x)
{
    return x % SETSIZE;
}

struct listNode{
    int data;
    listNode* next;
    
    listNode(int x) : data(x), next(NULL) {}
};

class MyHashSet {
    listNode* arr[SETSIZE];
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        for(int i = 0; i < SETSIZE; i++)
            arr[i] = NULL;
    }
    
    void add(int key) {
        int idx = getHash(key);

        listNode* newNode = new listNode(key);

        if(arr[idx] == NULL)
            arr[idx] = newNode;
        else
        {
            listNode* iter = arr[idx];
            
            // check if key is already present. If yes, don't add again
            while(iter != NULL)
            {
                if(iter->data == key)
                    return;
                
                iter = iter->next;
            }
            
            iter = arr[idx];

            while(iter->next != NULL)
                iter = iter->next;

            iter->next = newNode;
        }
    }
    
    void remove(int key) {
        int idx = getHash(key);
        
        listNode* iter1 = arr[idx];
        listNode* iter2 = ( arr[idx] != NULL ) ? arr[idx]->next : NULL;
        
        // element is at head
        if(iter1 != NULL && iter1->data == key)
        {
            listNode* tmp = arr[idx];
            arr[idx] = arr[idx]->next;
            
            delete tmp;
            tmp = NULL;
        }
        // element is not at head
        else
        {
            while(iter2 != NULL && iter2->data != key)
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
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = getHash(key);
        
        listNode* iter = arr[idx];
        
        while(iter != NULL)
        {
            if(iter->data == key)
                return true;
            
            iter = iter->next;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
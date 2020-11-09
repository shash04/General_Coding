// Design a data structure that supports all following operations in average O(1) time.
// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
// Example:

// // Init an empty set.
// RandomizedSet randomSet = new RandomizedSet();

// // Inserts 1 to the set. Returns true as 1 was inserted successfully.
// randomSet.insert(1);

// // Returns false as 2 does not exist in the set.
// randomSet.remove(2);

// // Inserts 2 to the set, returns true. Set now contains [1,2].
// randomSet.insert(2);

// // getRandom should return either 1 or 2 randomly.
// randomSet.getRandom();

// // Removes 1 from the set, returns true. Set now contains [2].
// randomSet.remove(1);

// // 2 was already in the set, so return false.
// randomSet.insert(2);

// // Since 2 is the only number in the set, getRandom always return 2.
// randomSet.getRandom();

// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
    // Insert and removal is O(1) for unordered_map / unordered_set
    // vector and map (number, index in vector) are required for O(1) getRandom 
    unordered_map<int, int> m1;
    vector<int> v1;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m1.count(val))
            return false;
        
        // insert at back of vector and add that index to map
        v1.push_back(val);
        m1[val] = v1.size() - 1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m1.count(val))
            return false;
        
        // remove that entry from map and update vector
        // NOTE - removal from vector is ideally not O(1)
        // As the order is not relevant, we can swap the val (index from map) with last element - O(1)
        // and pop back from vector - O(1)
        
        int valIdx = m1[val];
    
        m1[v1[v1.size() - 1]] = valIdx;
        
        swap(v1[valIdx], v1[v1.size() - 1]);
        
        m1.erase(val);
        v1.pop_back();
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int rIdx = rand() % v1.size();
        
        return v1[rIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
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
public:
    unordered_map<int,int> m1;                      // map to keep val as key and index as value
    vector<int> v1;                                 // vector for returning element at random index
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool flag = false;
        if(m1.find(val) == m1.end())
        { 
            flag = true;
            v1.push_back(val);
            m1[val] = v1.size() - 1;
        }
        return flag;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool flag = false;
        if(m1.find(val) != m1.end())
        {
            flag = true;
            int index = m1[val];                // Get index of val to be removed
            v1[index] = v1[v1.size()-1];        // Replace value at index in vector with val at last index of vector
            v1.pop_back();                      // Remove val at last index of vector
            m1[v1[index]] = index;              // Update index of value copied to index
            m1.erase(val);                      // Remove the val
        }
        return flag;
    }
    
    /** Get a random element from the set. */
    int getRandom() {       
        int random_num = rand() % v1.size();
        return v1[random_num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
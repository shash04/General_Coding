// Design a data structure that supports all following operations in average O(1) time.

// Note: Duplicate elements are allowed.
// insert(val): Inserts an item val to the collection.
// remove(val): Removes an item val from the collection if present.
// getRandom: Returns a random element from current collection of elements.
// The probability of each element being returned is linearly related to the number of same value the collection contains.

// Example:
// // Init an empty collection.
// RandomizedCollection collection = new RandomizedCollection();

// // Inserts 1 to the collection. Returns true as the collection did not contain 1.
// collection.insert(1);

// // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
// collection.insert(1);

// // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
// collection.insert(2);

// // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
// collection.getRandom();

// // Removes 1 from the collection, returns true. Collection now contains [1,2].
// collection.remove(1);

// // getRandom should return 1 and 2 both equally likely.
// collection.getRandom();

// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
    // Insert and removal is O(1) for unordered_map / unordered_set
    // vector and maps are required for O(1) getRandom 
    // map - val, set of indices in vector
    unordered_map<int, unordered_set<int>> valIdxMap;
    vector<int> v1;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = true;
        
        if(valIdxMap.count(val))
            flag = false;
        
        v1.push_back(val);
        
        valIdxMap[val].insert(v1.size() - 1);
        
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!valIdxMap.count(val))
            return false;
        
        // get first index from set of indices for element to be removed
        int idx = *valIdxMap[val].begin();
        
        // update the set of indices of the element removed
        valIdxMap[val].erase(idx);
        
        int end = v1.size() - 1;
        int lastElement = v1[end];
        
        // swapped val in vector with last element in the vector
        swap(v1[idx], v1[end]);

        //update the set of indices of the last element
        valIdxMap[lastElement].insert(idx);
        valIdxMap[lastElement].erase(end);
        
        v1.pop_back();
        
        if(valIdxMap[val].size() == 0)
        {
            valIdxMap.erase(val);
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int rIdx = rand() % v1.size();
        return v1[rIdx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
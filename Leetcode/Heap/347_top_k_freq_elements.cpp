// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

// https://leetcode.com/problems/top-k-frequent-elements/

// *******************************************************************************************************
// Concept - map + priority_queue (min heap)
// Time complexity = nlog(k)
// *******************************************************************************************************

// Adding new custom class for comparator overload
// Need to reverse sort the entry to priority queue
class sortByVal{
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        // Populate the frequency map
        for(int num : nums)
            freq[num]++;
        
        // Min Heap Priority queue
        // Format for min heap priority queue : priority_queue <int, vector<int>, greater<int>> pq;
        // Special case as each element is a pair
        priority_queue<pair<int,int>, vector<pair<int, int>>, sortByVal> pq;
        
        for(auto entry : freq)
        {
            pq.push({entry.first, entry.second});
            
            // For max heap, condition would be pq.size() > freq.size() - k indicating top element to 
            // get added to retVec as there are less than k elements left. Complexity = log(n-k)
            // However, here if size goes above k, remove top element as it is lowest freq till now
            // Thus comparisions are limited and complexity = log(k)
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> retVec(k);
        
        for(int i=k-1; i>=0; i--)
        {
            retVec[i] = pq.top().first;
            pq.pop();
        }
        
        return retVec;
    }
};
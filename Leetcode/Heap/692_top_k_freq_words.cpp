// Given a non-empty list of words, return the k most frequent elements.
// Your answer should be sorted by frequency from highest to lowest. If two words have the same
// frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.

// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.

// https://leetcode.com/problems/top-k-frequent-words/

// *******************************************************************************************************
// Concept - map + priority_queue (min heap)
// Time complexity = nlog(k)
// *******************************************************************************************************

// Adding new custom class for comparator overload
// Priority Queue is max heap by default. Thus the compartor is greater than.
class SortByVal{
public:
    bool operator()(pair<string, int>& a, pair<string, int>& b)
    {
        // if freq is same, then lower alphabetical order comes first
        if(a.second == b.second)
            return a.first < b.first;
        else
            return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        
        // Populate the frequency map
        for(string word : words)
            freq[word]++;
        
        // Min Heap Priority queue
        // Format for min heap priority queue : priority_queue <int, vector<int>, greater<int>> pq;
        // Special case as each element is a pair<string, int>
        //priority_queue<pair<string, int>, vector<pair<string, int>>, SortByVal> pq;
        
        // Alternate way to declare custom pq
        auto comp = [&](const pair<string, int>& a, const pair<string, int>& b){
            if(a.second == b.second)
                return a.first < b.first;
            else
                return a.second > b.second;
        };
        
        typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> PRIORITY_QUEUE;
        PRIORITY_QUEUE pq(comp);
        
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
          
        vector<string> retVec(k);
        
        for(int i=k-1; i>=0; i--)
        {
            retVec[i] = pq.top().first;
            pq.pop();
        }
        
        return retVec;
    }
};
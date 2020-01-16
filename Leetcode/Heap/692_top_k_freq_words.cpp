

// Concept - map + priority_queue (min heap)
// Time complexity = nlog(k)

// Adding new custom class for comparator overload
// Need to reverse sort the entry to priority queue
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
        priority_queue<pair<string, int>, vector<pair<string, int>>, SortByVal> pq;
        
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
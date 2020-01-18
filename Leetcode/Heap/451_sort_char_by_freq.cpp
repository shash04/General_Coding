// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:
// Input:
// "tree"
// Output:
// "eert"
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:
// Input:
// "cccaaa"
// Output:
// "cccaaa"
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:
// Input:
// "Aabb"
// Output:
// "bbAa"
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// https://leetcode.com/problems/sort-characters-by-frequency/

class SortByVal{
public:
    bool operator()(pair<char, int>& a, pair<char, int>& b)
    {
        if(a.second == b.second)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        for(char c : s)
            freq[c]++;
        
        priority_queue< pair<char, int>, vector<pair<char, int>>, SortByVal> pq;
        
        for(auto entry : freq)
        {
            pq.push({entry.first, entry.second});
        }
        
        string retStr;
        
        while(!pq.empty())
        {
            auto pq_entry = pq.top();
            pq.pop();
            
            for(int i=0; i<pq_entry.second; i++)
            {
                retStr += pq_entry.first;
            }
        }
        
        return retStr;
    }
};
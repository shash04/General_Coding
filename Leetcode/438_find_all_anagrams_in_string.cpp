// Example 1
// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2
// Input:
// s: "abab" p: "ab"

// Output:
// [0, 1, 2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s_vec (26,0), p_vec (26,0), res;
        
        if(p.size() > s.size())
            return res;
        
        for(int i=0; i<p.size(); i++)
        {
            ++s_vec[s[i] - 'a'];
            ++p_vec[p[i] - 'a'];
        }
        
        if( s_vec == p_vec )
            res.push_back(0);
        
        for(int i=p.size(); i<s.size(); i++)
        {
            ++s_vec[s[i] - 'a'];
            --s_vec[s[i-p.size()] - 'a'];
            
            if( s_vec == p_vec )
                res.push_back(i-p.size()+1);
        }
        
        return res;
    }
};
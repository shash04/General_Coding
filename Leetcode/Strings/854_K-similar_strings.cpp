// Strings A and B are K-similar (for some non-negative integer K) if we can swap the positions of two letters in A
// exactly K times so that the resulting string equals B.

// Given two anagrams A and B, return the smallest K for which A and B are K-similar.

// Example 1:
// Input: A = "ab", B = "ba"
// Output: 1

// Example 2:
// Input: A = "abc", B = "bca"
// Output: 2

// Example 3:
// Input: A = "abac", B = "baca"
// Output: 2

// Example 4:
// Input: A = "aabc", B = "abca"
// Output: 2

// Note:
// 1 <= A.length == B.length <= 20
// A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}

// https://leetcode.com/problems/k-similar-strings/

class Solution {
public:
    int kSimilarity(string A, string B) {
        if(A == B)
            return 0;
        
        int steps = 0;
        
        // bfsQ and visited to keep track of already visited words
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(A);
        visited.insert(A);        
        
        while(!q.empty())
        {
            // Increment num of steps
            steps++;
            
            int qSize = q.size();
            
            while(qSize--)
            {
                string cur = q.front();
                q.pop();
                
                // Check for first mismatched char in cur string 
                int index = 0;
                
                while(cur[index] == B[index])
                    index++;
                
                // starting from index + 1, look for matching char to swap
                for(int i = index + 1; i < A.size(); i++)
                {
                    // if char at i doesn't match or is correctly placed - continue
                    if(cur[i] != B[index] || cur[i] == B[i])
                        continue;
                    
                    // Matching char found - swap and check
                    swap(cur[i], cur[index]);
                    
                    if(cur == B)
                        return steps;
                    
                    // If new string is not visited, add to bfsQ
                    if(visited.count(cur) == 0)
                    {
                        q.push(cur);
                        visited.insert(cur);
                    }                    
                    
                    // swap back
                    swap(cur[i], cur[index]);
                }
            }
        }
        
        return steps;
    }
};
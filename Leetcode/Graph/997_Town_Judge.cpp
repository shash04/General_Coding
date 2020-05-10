// In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

// If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

// Example 1:
// Input: N = 2, trust = [[1,2]]
// Output: 2

// Example 2:
// Input: N = 3, trust = [[1,3],[2,3]]
// Output: 3

// Example 3:
// Input: N = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1

// Example 4:
// Input: N = 3, trust = [[1,2],[2,3]]
// Output: -1

// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size() < N - 1)            // Min trust edges required for town judge is N - 1
            return -1;
            
        vector<int> trustCount (N + 1, 0);
        
        for(auto& entry : trust)
        {
            trustCount[entry[0]]--;         // out degree (num of people this person trusts)
            trustCount[entry[1]]++;         // in degree (num of people that trust this person)
        }
        
        for(int i=1; i <= N; i++)
        {
            if(trustCount[i] == N - 1)      // Town judge is trusted by N - 1 people and doesn't trust anyone
                return i;
        }
        
        return -1;
    }
};
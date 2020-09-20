// You have a number of envelopes with widths and heights given as a pair of integers (w, h).
// One envelope can fit into another if and only if both the width and height of one envelope is greater
// than the width and height of the other envelope.

// What is the maximum number of envelopes can you Russian doll? (put one inside other)

// Note:
// Rotation is not allowed.

// Example:
// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3 
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

// https://leetcode.com/problems/russian-doll-envelopes/


// ***************************************************************************************************
// Use DP concept of longest increasing subsequence 
// Time Complexity - O(N2)
// ***************************************************************************************************
/*
sort the envelopes in descending order of width
merge smaller intervals into bigger intervals
return max merged size

[9,9],[8,8],[7,5],[6,4],[6,7],[5,4],[2,3]

[2,3],[5,4],[6,4],[6,7]

0 1 1 2

dp :: i = 1 to len and j = 0 to i
store max russian doll len

dp[i] = max(dp[i], 1 + dp[j])

*/
class Solution {
    static bool mySort(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        
        int result = 0;
        int n = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end(), mySort);
        
        vector<int> dp (n, 0);
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            result = max(result, dp[i]);
        }
        
        return result + 1;
    }
};

// ***************************************************************************************************
// Use DP concept of longest increasing subsequence 
// Time Complexity - O(N * Log(N)) assuming lower bound takes O(Log(N))
// Similar concept as LIS but have to custom sort due to width + height variables
// ***************************************************************************************************
class Solution {
    static bool mySort(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        
        int n = envelopes.size();
        
        // NOTE : sort according to width and if equal width then in decreasing order of height
        // Sorting takes care of increasing width and only height is considered for lower bound
        // Longetst Inc Subsequence doesn't require sorting as only one number and not vector of 2 numbers
        sort(envelopes.begin(), envelopes.end(), mySort);
        
        vector<int> v1;
        
        for(vector<int>& curEnv : envelopes)
        {
            auto iter = lower_bound(v1.begin(), v1.end(), curEnv[1]);
            
            if(iter == v1.end())
                v1.push_back(curEnv[1]);
            else
                *iter = curEnv[1];
        }            
        
        return v1.size();
    }
};
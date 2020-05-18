// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

// You have the following 3 operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// https://leetcode.com/problems/edit-distance/

// **************************************************************************************************
// Space optimal solution 
// **************************************************************************************************
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1Size = word1.size();
        int w2Size = word2.size();
        
        vector<int> dp (w2Size + 1, 0);
        
        for(int j=1; j <= w2Size; j++)
            dp[j] = j;
        
        for(int i=1; i <= w1Size; i++)
        {
            // pre keeps track of diagonally opp prev element dp[i-1][j-1]
            // for every row, initial value is prev i. Thus get dp[0] and update dp[0] for next iter
            int pre = dp[0];
            dp[0] = i;
            
            for(int j=1; j <= w2Size; j++)
            {
                // Store curr col val (dp[j]) as it will be used for updating pre
                // (diagonally opp for next iteration)
                int temp = dp[j];
                
                if(word1[i-1] == word2[j-1])
                    dp[j] = pre;
                
                else
                    dp[j] = 1 + min(pre, min(dp[j], dp[j-1]));
                
                pre = temp;
            }
        }
        
        return dp[w2Size];
    }
};

// **************************************************************************************************
// 2-D DP approach
// **************************************************************************************************

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1Size = word1.size();
        int w2Size = word2.size();
        
        vector<vector<int>> dp (w1Size + 1, vector<int>(w2Size + 1, 0));
        
        // Populate first row and column assuming empty strings.
        // So all the characters till curr char have to be replaced
        for(int i=0; i <= w1Size; i++)
            dp[i][0] = i;
        
        for(int j=0; j <= w2Size; j++)
            dp[0][j] = j;
        
        
        for(int i=1; i <= w1Size; i++)
        {
            for(int j=1; j <= w2Size; j++)
            {
                // Case 1: If char from word1 == char from word2 : take diagonally previous value dp[i-1][j-1]
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                
                // Case 2: If chars don't match minimum of 3 previous adjacent values + 1
                else
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
        
        return dp[w1Size][w2Size];
    }
};

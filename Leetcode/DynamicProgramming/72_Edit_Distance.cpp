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

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        int T[m + 1][n + 1] = {0};

        // Populate first row and column assuming empty strings.
        // So all the characters till curr char have to be replaced
        for (int i = 0; i <= m; i++)
            T[i][0] = i;
        for (int j = 0; j <= n; j++)
            T[0][j] = j;

        // Case 1: If char from word1 == char from word2 = take diagonally previous value T[i-1][j-1]
        // Case 2: Else minimum of 3 previous adjacent values + 1
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                if (word1[i - 1] == word2[j - 1])
                    T[i][j] = T[i - 1][j - 1];
                else
                    T[i][j] = min(min(T[i - 1][j], T[i][j - 1]), T[i - 1][j - 1]) + 1;
            }
        }

        return T[m][n];
    }
};
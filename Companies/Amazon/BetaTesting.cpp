// A new team at Amazon is doing an internal beta test before their first release.
// The testing consists of executing tasks in a particular order, with each task having an assigned complexity.
// The team has already planned the order in which the tasks have to be executed, but these now need to be scheduled across several days.
// The goal is to have at least one task sent to the beta testers every day and to plan the tasks in a way that minimizes the overall
// complexity of the test. The test is considered complete once all the tasks have been executed. Given the complexity of the tasks,
// as well as how many days the test is running, what is the overall minimum complexity that can be achieved with optimal planning?

// For example, let's say there are n = 5 tasks, where complexity = [1,5, 3, 2, 4), and the length of the test is days = 2.
// (Note that complexity denotes both the assigned complexity of each task as well as the order in which they need to be executed.)
// The best option is to execute the first task on the first day and the rest on the second day.
// The complexity of the first day would be 1, since that's the only task, and the complexity of the second day would be 5,
// because that's the complexity level of the most complex task that day. Therefore, the answer is 1 + 5 = 6.

// Example 1:
// 5 -> complexity[] size n = 5
// 30
// 10
// 40
// 20
// 50
// 2 -> Days =2

// Output: 80

// Example 2:
// 6 -> complexity[] size n = 6
// 74303
// 20452
// 66120
// 44483
// 5370
// 68585
// 5 -> Days =5

// Output: 234830
// Explanation: task 3 and 4 on same day

// Signature:
// int findMinComplexity(int[] complexity, int days) {
// }

// Related problems:
// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if(n < d)
            return -1;
        
        // dp[i][j] => Min difficulty to complete first (j + 1) jobs in (i + 1) days
        vector<vector<int>> dp (d, vector<int>(n, 0));
        
        dp[0][0] = jobDifficulty[0];
        
        // dp[0][j] => finish first (j + 1) jobs using exactly 1 day
        for(int j = 1; j < n; j++)
        {
            dp[0][j] = max(jobDifficulty[j], dp[0][j-1]);
        }
        
        for(int i = 1; i < d; i++)
        {
            for(int j = i; j < n; j++)
            {
                int localMax = jobDifficulty[j];
                dp[i][j] = INT_MAX;
                
                for(int k = j; k >= i; k--)
                {
                    localMax = max(localMax, jobDifficulty[k]);
                    
                    // localMax is max complexity of items in k to i
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + localMax);
                }
            }
        }
        
        return dp[d - 1][n - 1];
    }
};
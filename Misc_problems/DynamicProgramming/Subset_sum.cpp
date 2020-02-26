// Given an array of integers, determine if you could get the required sum by adding the elements of the array.
// Note: You can only add the elements once towards the sum.
// Also the elements included in the sum need not be contigous.

class Solution{
public:
    bool isSubsetSumPresent(vector<int> arr, int sum)
    {
        if(arr.size() == 0)
            return false;

        if(sum == 0)
            return true;

        int n = arr.size();
        vector<vector<bool>> dp (n, vector<int>(sum+1, false));

        // If the required sum is 0, return values are true
        for(int i=0; i<n; i++)
            dp[i][0] = true;

        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(j < arr[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
            }
        }

        return dp[n][sum+1];
    }
};
// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Example 1:
// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

// Example 2:
// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two conditions.

// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {        
        int n = ratings.size();
        
        vector<int> candies (n, 1);
        int count = 0;
        
        // Pass 1 to check forward incrementing nums
        for(int i=1; i < n; i++)
        {
            if(ratings[i] > ratings[i-1])
                candies[i] = 1 + candies[i-1];
        }
        
        // Pass 2 to check backward incrementing nums
        for(int i=n-1; i >= 1; i--)
        {
            // Additional check to avoid already considered cases (e.g. 2,3,5,2)
            if(ratings[i-1] > ratings[i] && !(candies[i-1] > candies[i]))
                candies[i-1] = 1 + candies[i];
        }
        
        for(int& num : candies)
            count += num;
        
        return count;
    }
};
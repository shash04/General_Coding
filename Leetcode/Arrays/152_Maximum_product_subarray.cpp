// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// https://leetcode.com/problems/maximum-product-subarray/

// Logic: It all depends on if there are odd negative numbers or even negative numbers
// If even, no worries == entire array would be max product (except 0)
// If odd, either the left end one or the right end one should be counted, so it will be revealed by scanning from left and from right and vice-versa
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        
        int maxProd = nums[0];
        int frontProd = 1;
        int rearProd = 1;
        for(int i=0; i<n; i++)
        {
            frontProd *= nums[i];
            rearProd *= nums[n-1-i];
            maxProd = max(maxProd, max(frontProd, rearProd));
            
            if(frontProd == 0)
                frontProd = 1;
            if(rearProd == 0)
                rearProd = 1;
        }
        return maxProd;
    }
};
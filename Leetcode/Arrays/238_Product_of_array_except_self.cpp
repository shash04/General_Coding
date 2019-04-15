// Given an array nums of n integers where n > 1,  return an array output such that output[i] is
// equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).

// https://leetcode.com/problems/product-of-array-except-self/

// Solution with constant space requirement - Optimized
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        int fromBegin = 1;
        int fromEnd = 1;
        vector<int> res(n,1);
        
        for(int i=0; i<n; i++)
        {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n-1-i] *= fromEnd;
            fromEnd *= nums[n-1-i];
        }
        
        return res;
    }
};

// Solution with O(n) space requirement - Not optimized
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> fromStart(n);
        vector<int> fromEnd(n);
        vector<int> res(n);
     
        fromStart[0] = 1;
        fromEnd[0] = 1;
        
        for(int i=1; i<n; i++)
        {
            fromStart[i] = nums[i-1] * fromStart[i-1];
            fromEnd[i] = nums[n-i] * fromEnd[i-1];
        }
        
        for(int j=0; j<n; j++)
        {
            res[j] = fromStart[j] * fromEnd[n-1-j];
        }
        
        return res;
    }
};
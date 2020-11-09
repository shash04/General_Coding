// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Note: The algorithm should run in linear time and in O(1) space.

// Example 1:
// Input: [3,2,3]
// Output: [3]

// Example 2:
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]

// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        
        if(nums.size() == 1)
            return {nums[0]};
        
        vector<int> result;
        
        // Max number of elements that will appear n/3 times is 2
        // Have two counters and two corresponding  potential numbers
        int counter1 = 0, counter2 = 0;
        int num1 = nums[0], num2 = nums[1];
        
        for(int i = 0; i < nums.size(); i++)
        {
            // if curr entry == num1, increment counter1
            if(nums[i] == num1)
                counter1++;
            else if(nums[i] == num2)
                counter2++;
            
            // If counter1 == 0, new potential ans number
            else if(counter1 == 0)
            {
                num1 = nums[i];
                counter1;
            }
            // If counter2 == 0, new potential ans number
            else if(counter2 == 0)
            {
                num2 = nums[i];
                counter2++;
            }
            // Curr mismatch with both nums and both counters > 0 => decrement both counters
            else
            {
                counter1--;
                counter2--;
            }
        }
        
        // 2nd pass to verify if the ans found are correct as there is possibility of no answer
        counter1 = 0;
        counter2 = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == num1)
                counter1++;
            if(nums[i] == num2)
                counter2++;
        }
        
        if(counter1 > nums.size() / 3)
            result.push_back(num1);
        
        if(counter2 > nums.size() / 3 && num1 != num2)
            result.push_back(num2);
        
        return result;
    }
};
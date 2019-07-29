// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

// Note:
// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may not use the same element twice.

// Example:
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int start_index = 0;
        int end_index = numbers.size() - 1;
        
        while(start_index<end_index)
        {
            int sum = numbers[start_index] + numbers[end_index];
            if(sum == target)
            {
                ans.push_back(start_index+1);
                ans.push_back(end_index+1);
                break;
            }
            else if(sum > target)
                end_index--;
            else
                start_index++;
        }
        return ans;
    }
};
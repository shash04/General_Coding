// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findOccurence(nums, target, 0);
        int last = findOccurence(nums, target, 1);
        
        vector<int> result = {first, last};
        return result; 
    }
    
    int findOccurence(vector<int>& nums, int target, int firstOrLast)
    {
        int start = 0;
        int end = nums.size()-1;
        int index = -1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                index = mid;
                if(firstOrLast == 0)
                    end = mid-1;
                else
                    start = mid+1;
            }
            else if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return index;
    }
};
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        
        while(start <= end)
        {
            int mid = (start + end)/2;  
            // Case 1: found the element
            if(nums[mid] == target)
                return mid;
            // Case 2: Second half of array is sorted
            // Case 2a: Element lies in second half
            // Case 2b: Element doesn't lie in second half
            else if(nums[mid] <= nums[end])
            {
                if(nums[mid] <= target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            // Case 3: first half of array is sorted
            // Case 3a: Element lies in first half
            // Case 3b: Element doesn't lie in first half
            else if(nums[start] <= nums[mid])
            {
                if(nums[start] <= target && target <= nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return -1;
    }
};
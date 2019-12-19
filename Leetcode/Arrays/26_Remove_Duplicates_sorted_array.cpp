// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// Example 1:
// Given nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the returned length.

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i-1])
                s++;
            else
                nums[i-s] = nums[i];
        }
        return nums.size() - s;
    }
};

// Solution 2:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        
        int index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[index])
            {
                if (i > index + 1)
                    nums[index + 1] = nums[i];
                index++;
            }
        }
        return index + 1;
    }
};

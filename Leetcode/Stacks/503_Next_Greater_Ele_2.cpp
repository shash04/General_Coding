// Given a circular array (the next element of the last element is the first element of the array),
// print the Next Greater Number for every element. The Next Greater Number of a number x is the first
// greater number to its traversing-order next in the array, which means you could search circularly
// to find its next greater number. If it doesn't exist, output -1 for this number.

// Example 1:
// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number; 
// The second 1's next greater number needs to search circularly, which is also 2.
// Note: The length of given array won't exceed 10000.

// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> retVec (nums.size() , -1);
        
        // stack storing index of elements in nums
        stack<int> s1;
        
        // First pass from right to left
        for(int i = nums.size() - 1; i >= 0; i--)
        {
             // pop elements from stack till smaller than curr elem as we are looking for greater than curr ele
            while(!s1.empty() && nums[i] >= nums[s1.top()])
                    s1.pop();
            
            // if stack isnt empty and top ele is greater than curr, that is ans for curr index
            retVec[i] = (s1.empty()) ? -1 : nums[s1.top()];
            
            // Push curr index for elements
            s1.push(i);
        }
        
        // Second pass to fix entries for circular array
        // stack would be having indexes of elements in increasing order of value
        // Repeat same logic as first pass
        for(int i = nums.size() - 1; i >= 0; i--)
        {            
            while(!s1.empty() && nums[i] >= nums[s1.top()])
                    s1.pop();
            
            retVec[i] = (s1.empty()) ? -1 : nums[s1.top()];
            
            s1.push(i);
        }
        
        return retVec;
    }
};
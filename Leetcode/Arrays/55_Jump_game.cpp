// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.

// Example 1:
// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.

// Solution - Greedy algorithm
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(!nums.size())
            return false;
        
        int reach = nums[0];                    // Max reach for first element
        for(int i=1; i<nums.size(); i++)
        {
            reach--;                            // Decrement reach for each increment in index
            if(reach < 0)                       // If reach isn't updated and turns < 0 => end cant be reached 
                return false;
            reach = max(reach, nums[i]);        // Update reach to max index that can be reached
        }
        return true;                            // End of array can be reached
    }
};
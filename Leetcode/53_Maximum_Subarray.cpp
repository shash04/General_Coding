// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6

// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTotal = INT_MIN;
        int total = 0;
        
        for(int i=0; i < nums.size(); i++){
            total += nums[i];
            
            if( maxTotal < total)
                maxTotal = total;
            
            if( total < 0 )
                total = 0;
        }
        
        return maxTotal;
    }
};
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
// 6 units of rain water (blue section) are being trapped.

// Example:
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

// https://leetcode.com/problems/trapping-rain-water/

// **************************************************************************************
// Concept : leftMaxHeight - vector with max height while traversing left to right
// rightMaxHeight - vector with max height while traversing right to left
// totalWater += min(leftMaxHeight[i], rightMaxHeight[i]) - height[i];
// Time Complexity - O(N)
// Space Complexity - O(N)
// **************************************************************************************
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        
        int totalWater = 0;
        int n = height.size();
        
        // left and right vec for indicating max height till index from left and right
        vector<int> leftMaxHeight (n, 0);
        vector<int> rightMaxHeight (n, 0);
        
        // initialize the max height
        leftMaxHeight[0] = height[0];
        rightMaxHeight[n-1] = height[n-1];
        
        for(int i=1; i < n; i++)
            leftMaxHeight[i] = max(leftMaxHeight[i-1], height[i]);
        
        for(int i=n-2; i >= 0; i--)
            rightMaxHeight[i] = max(rightMaxHeight[i+1], height[i]);
        
        for(int i=0; i < n; i++)
        {
            totalWater += min(leftMaxHeight[i], rightMaxHeight[i]) - height[i];
        }
        
        return totalWater;
    }
};

// **************************************************************************************
// Alternate solution - Maintaining two pointers l and r. Keeping track of lMax and rMax
// Time Complexity - O(N)
// Space Complexity - O(1)
// **************************************************************************************
class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size())
            return 0;
      
        int l = 0;
        int r = height.size() - 1;

        int lMax = height[l];
        int rMax = height[r];
        int totalVol = 0;
        
        while(l <= r)
        {
            if(lMax < rMax)
            {
                lMax = max(lMax, height[l]);
                totalVol += lMax - height[l];
                l++;
            }
            else
            {
                rMax = max(rMax, height[r]);
                totalVol += rMax - height[r];
                r--;
            }
        }
        
        return totalVol;
    }
};

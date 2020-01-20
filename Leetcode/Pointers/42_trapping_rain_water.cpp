// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
// 6 units of rain water (blue section) are being trapped.

// Example:
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

// https://leetcode.com/problems/trapping-rain-water/

// **************************************************************************************
// Concept : h1 - vector with max height while traversing left to right
// h2 - vector with max height while traversing right to left
// vol[i] = min(h1, h2) - height[i];
// **************************************************************************************
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        
        vector<int> h1(n), h2(n);
        int totalVol = 0;
        
        int iter1_max = 0;
        int iter2_max = 0;
        
        for(int i=0; i<n; i++)
        {
            iter1_max = max(height[i], iter1_max);
            iter2_max = max(height[n-1-i], iter2_max);
            
            h1[i] = iter1_max;
            h2[n-1-i] = iter2_max;
        }
        
        for(int i=0; i<n; i++)
        {
            int validWaterHeight = min(h1[i], h2[i]);
            totalVol += validWaterHeight - height[i];
        }
        
        return totalVol;
    }
};


// **************************************************************************************
// Alternate solution - Maintaining two pointers l and r. Keeping track of lMax and rMax
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

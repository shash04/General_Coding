// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn
// such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container,
// such that the container contains the most water.

// Example:
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int waterVol = 0;
        int start = 0, end = height.size() - 1;
        
        while (start < end)
        {
            int h = min(height[start], height[end]);
            waterVol = max(waterVol, (end - start) * h);
            
            while (height[start] <= h && start < end)
                start++;
            while (height[end] <= h && start < end)
                end--;
        }
        return waterVol;
    }
};
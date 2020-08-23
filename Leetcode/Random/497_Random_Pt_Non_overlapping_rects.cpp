// Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an
// integer point in the space covered by the rectangles.

// Note:
// An integer point is a point that has integer coordinates. 
// A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
// ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
// length and width of each rectangle does not exceed 2000.
// 1 <= rects.length <= 100
// pick return a point as an array of integer coordinates [p_x, p_y]
// pick is called at most 10000 times.

// Example 1:
// Input: 
// ["Solution","pick","pick","pick"]
// [[[[1,1,5,5]]],[],[],[]]

// Output: 
// [null,[4,1],[4,1],[3,3]]

// Example 2:
// Input: 
// ["Solution","pick","pick","pick","pick","pick"]
// [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]

// Output: 
// [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]

// Explanation of Input Syntax:
// The input is two lists: the subroutines called and their arguments.
// Solution's constructor has one argument, the array of rectangles rects. pick has no arguments.
// Arguments are always wrapped with a list, even if there aren't any.

// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/


// Concept - for every rect add the pts (area) of that rect to cumulative areaSum and store with rect idx
// Pick random number between 0 and total area = r = Pick r-th point in the area
// use upper bound to get the area covering r-th point
// pick a random point between in that rectangle

class Solution {
    // Copy of rects
    vector<vector<int>> rectsCopy;
    // areaSum to keep track of total area
    int areaSum;
    // map to store area and rect idx
    map<int, int> areaIdxMap;
    
public:
    Solution(vector<vector<int>>& rects) {
        rectsCopy = rects;
        areaSum = 0;
        
        for(int i = 0; i < rects.size(); i++)
        {
            int currArea = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            
            areaSum += currArea;
            
            areaIdxMap[areaSum] = i;
        }
    }
    
    vector<int> pick() {
        int r = rand() % areaSum;
        auto rArea = areaIdxMap.upper_bound(r);
        
        int idx = (*rArea).second;
        
        vector<int> rectPicked = rectsCopy[idx];
        
        int xPts = rectPicked[2] - rectPicked[0] + 1;
        int yPts = rectPicked[3] - rectPicked[1] + 1;
        
        int xRet = rand() % xPts + rectPicked[0];
        int yRet = rand() % yPts + rectPicked[1];
        
        return {xRet, yRet};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

// Example 1:
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o  
// +------------->
// 0  1  2  3  4

// Example 2:
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6

// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
    int getGCD(int a, int b)
    {
        if(b == 0)
            return a;
        
        return getGCD(b, a % b);
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 2)
            return points.size();
        
        int result = 0;
        
        for(int i = 0; i < points.size() - 1; i++)
        {
            // map - key : slope in the form of a / b : val = count of points having same slope
            map<pair<int, int>, int> lines;
            
            int localMax = 0;
            int overlap = 0;
            
            for(int j = i + 1; j < points.size(); j++)
            {
                // check if i and j points overlap
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                {
                    overlap++;
                    continue;
                }
                
                // slope = xDiff / yDiff
                int a = points[j][0] - points[i][0];
                int b = points[j][1] - points[i][1];
                
                // get gcd to get a / b in lowest form
                // For vertical lines slope = make_pair(0, 1)
                // For horizontal lines slope = make_pair(1, 0)
                int gcd = getGCD(a, b);

                a /= gcd;
                b /= gcd;
                
                // increment the lines with current slope
                lines[make_pair(a, b)]++;
                
                // update localMax by comparing with num of lines with current slope
                localMax = max(localMax, lines[make_pair(a, b)]);
            }
            
            // max of result and localMax + overlapping points + 1 (current i-th point)
            result = max(result, localMax + overlap + 1);
        }
        
        return result;
    }
};
// Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

// Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2].
// (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).

// Example 1:
// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [3,2,4,4],
//   [1,3,2,4],
//   [2,3,3,4]
// ]
// Return true. All 5 rectangles together form an exact cover of a rectangular region.
 
// Example 2:
// rectangles = [
//   [1,1,2,3],
//   [1,3,2,4],
//   [3,1,4,2],
//   [3,2,4,4]
// ]
// Return false. Because there is a gap between the two rectangular regions.

// https://leetcode.com/problems/perfect-rectangle/

/*
Validate 2 conditions = 
1)
Get all y points for each x - map 1
Get all x points for each y - map 2
for every entry in m1 and m2 - sort vector - all values should be contiguous

2)
check for area sum == total area
*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.size() == 0)
            return false;
        
        map<int, vector<int>> m1;
        map<int, vector<int>> m2;
        
        int area = 0;
        int minX, minY, maxX, maxY;
        
        maxX = maxY = 0;
        minX = minY = INT_MAX;
        
        sort(rectangles.begin(), rectangles.end());
        for(int i=0; i<rectangles.size()-1; i++)
        {
            if(rectangles[i] == rectangles[i+1])
                return false;
        }
        
        for(auto rect : rectangles)
        {
            pair<int,int> leftBottom  = {rect[0], rect[1]};
            pair<int,int> rightTop    = {rect[2], rect[3]};
            
            int x1 = leftBottom.first;
            int x2 = rightTop.first;
            int y1 = leftBottom.second;
            int y2 = rightTop.second;
            
            m1[x1].push_back(y1);
            m1[x1].push_back(y2);
            
            m1[x2].push_back(y1);
            m1[x2].push_back(y2);
            
            m2[y1].push_back(x1);
            m2[y1].push_back(x2);
            
            m2[y2].push_back(x1);
            m2[y2].push_back(x2);
            
            area += abs((x2-x1) * (y2-y1));
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);
        }
        
        // cout<<"Printing M1"<<endl;
        // printMap(m1);
        // cout<<"Printing M2"<<endl;
        // printMap(m2);    
        // cout<<endl;
        
        if(area != ((maxX - minX) * (maxY - minY)))
            return false;
        
        return compare(m1) || compare(m2);
    }
    
    bool compare(map<int, vector<int>>& m1)
    {
        for(auto iter = m1.begin(); iter != m1.end(); iter++)
        {
            auto& vec = iter->second;
            
            sort(vec.begin(), vec.end());
            
            // seperate checks for first and last entry
            // e.g. 1 3 3 4 ; 1 2 2 4
            if(iter == m1.begin() || next(iter) == m1.end())
            {
                for(int i=1; i<vec.size() - 2; i += 2)
                {
                    if(vec[i] != vec[i+1])
                        return false;
                }
            }
            // seperate checks for all middle entries
            // e.g. 3 3 4 4 ;  1 1 2 2
            else
            {
                for(int i=0; i<vec.size() - 1; i += 2)
                {
                    if(vec[i] != vec[i+1])
                        return false;
                }
            }
        }
        return true;
    }
    
    void printMap(const map<int, vector<int>>& m1)
    {
        for(auto& entry : m1)
        {
            cout<<"Key = "<<entry.first<<" === ";
            auto vec = entry.second;
            
            sort(vec.begin(), vec.end());
            
            for(int i=0; i<vec.size(); i++)
                cout<<vec[i]<<" ";
            
            cout<<endl;
        }
    }
};
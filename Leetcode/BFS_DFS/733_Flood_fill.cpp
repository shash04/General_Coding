// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill,
// and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel
// of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same
// color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
// At the end, return the modified image.

// Example 1:
// Input: 
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: 
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.

// https://leetcode.com/problems/flood-fill/


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {      
        int oldColor = image[sr][sc];
        
        if(image[sr][sc] != newColor)
            markPixels(image, sr, sc, oldColor, newColor);
        
        return image;
    }
    
    void markPixels(vector<vector<int>>& image, int r, int c, int oldColor, int newColor)
    {
        int nR = image.size();
        int nC = image[0].size();
        
        if(image[r][c] != oldColor)
            return;
        
        image[r][c] = newColor;
        
        if(r-1 >= 0 && image[r-1][c] == oldColor)
            markPixels(image, r-1, c, oldColor, newColor);
        
        if(r+1 < nR && image[r+1][c] == oldColor)
            markPixels(image, r+1, c, oldColor, newColor);
        
        if(c-1 >= 0 && image[r][c-1] == oldColor)
            markPixels(image, r, c-1, oldColor, newColor);
        
        if(c+1 < nC && image[r][c+1] == oldColor)
            markPixels(image, r, c+1, oldColor, newColor);
    }
};


// Same solution but with an vector of directions
class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {      
        int oldColor = image[sr][sc];
        
        if(image[sr][sc] != newColor)
            markPixels(image, sr, sc, oldColor, newColor);
        
        return image;
    }
    
    void markPixels(vector<vector<int>>& image, int r, int c, int oldColor, int newColor)
    {        
        image[r][c] = newColor;
        
        int nR = image.size();
        int nC = image[0].size();
        
        for( auto dir : dirs )
        {
            int R = r + dir.first;
            int C = c + dir.second;
            
            if(R < 0 || R >= nR || C < 0 || C >= nC)
                continue;
            
            if(image[R][C] == oldColor)
                markPixels(image, R, C, oldColor, newColor);
        }
    }
};
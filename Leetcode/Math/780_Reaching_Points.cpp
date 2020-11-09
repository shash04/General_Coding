// A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

// Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists
// to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

// Examples:
// Input: sx = 1, sy = 1, tx = 3, ty = 5
// Output: True
// Explanation:
// One series of moves that transforms the starting point to the target is:
// (1, 1) -> (1, 2)
// (1, 2) -> (3, 2)
// (3, 2) -> (3, 5)

// Input: sx = 1, sy = 1, tx = 2, ty = 2
// Output: False

// Input: sx = 1, sy = 1, tx = 1, ty = 1
// Output: True

// Note:
// sx, sy, tx, ty will all be integers in the range [1, 10^9].

// https://leetcode.com/problems/reaching-points/

// ******************************************************************************************************
// Bottom - UP approach 
// Complexity - O(log(max(tx, ty)))
// ******************************************************************************************************
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // Bottom - up approach = reduce target till greater than start
        while(sx < tx && sy < ty)
        {
            if(ty > tx)
                ty = ty % tx;
            else
                tx = tx % ty;
        }
        
        // true only if (sx, sy + k * sx) == (tx , ty) || (sx + k * sy, sy) == (tx, ty)
        return (sx == tx && sy < ty && (ty - sy) % sx == 0) ||
            (sy == ty && sx < tx && (tx - sx) % sy == 0);
    }
};

// ******************************************************************************************************
// Easy recursive solution - stack overflow due to too many recursive calls
// Complexity - O (2^(tx + ty))
// ******************************************************************************************************
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx > tx || sy > ty)
            return false;
        
        if(sx == tx && sy == ty)
            return true;
        
        return reachingPoints(sx, sx + sy, tx, ty) || reachingPoints(sx + sy, sy, tx, ty);
    }
};
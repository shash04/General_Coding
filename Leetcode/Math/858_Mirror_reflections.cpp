// There is a special square room with mirrors on each of the four walls.  Except for the southwest corner,
// there are receptors on each of the remaining corners, numbered 0, 1, and 2.
// The square room has walls of length p, and a laser ray from the southwest corner first meets the east
// wall at a distance q from the 0th receptor.
// Return the number of the receptor that the ray meets first. 
// (It is guaranteed that the ray will meet a receptor eventually.)

// Example 1:
// Input: p = 2, q = 1
// Output: 2
// Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.

// Note:
// 1 <= p <= 1000
// 0 <= q <= p

// https://leetcode.com/problems/mirror-reflection/

// ********************************************************************************************************
// Concept : Assume additional rooms being added on top of this room till ray hits receptor
// So, this problem can be transformed into finding numRooms * p = k * q, where
// numRooms is number of rooms and k is a constant
// Case 1) if k is 1 (no reflection and numRooms is 1) : p = q : Ray hits 1
// Case 2) if k is 2 (1 reflection and numRooms is 1) : p = 2 * q : Ray hits 2
// Case 3) if k is 3 (2 reflections and numRooms is 2) : 2*p = 3*q : Ray hits 0
// Use this logic for generic odd and even cases of reflections
// ********************************************************************************************************

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int numRooms = 1;
        int k = 1;
        
        while(numRooms * p != k * q)
        {
            k++;
            numRooms = k * q / p;
        }
        
        // num Rooms is odd and k is odd - ray hits 1
        if (numRooms % 2 == 1 && k % 2 == 1) return 1;

        // num Rooms is odd and k is even - ray hits 2
        if (numRooms % 2 == 1 && k % 2 == 0) return 2;
        
        // num Rooms is even and k is odd - ray hits 0
        if (numRooms % 2 == 0 && k % 2 == 1) return 0;
        
        return -1;
    }
};
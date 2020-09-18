// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).

// Example 1:
// Input:
// 3
// Output:
// 3

// Example 2:
// Input:
// 11

// Output:
// 0

// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10)
            return n;
        
        long m = 9, d = 1;
        
        while( (n - m * d) > 0)
        {
            n -= m * d;
            m *= 10;
            d++;
        }
        
        int start = m / 9;
        
        int offset = (n - 1) / d;
        int index = (n - 1) % d;
        
        // return to_string(start + offset)[index] - '0';
        
        int nthNum = start + offset;
        
        for(int k = 0; k < d - 1 - index; k++)
            nthNum /= 10;
        
        return nthNum % 10;
    }
};
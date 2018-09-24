// Input: 11
// Output: 3
// Explanation: Integer 11 has binary representation 00000000000000000000000000001011 

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
            n &= n-1;
            count++;
        }
        return count;
    }
};

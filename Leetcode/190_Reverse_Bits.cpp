// Input: 43261596
// Output: 964176192
// Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
//              return 964176192 represented in binary as 00111001011110000010100101000000.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int revNum = 0;
        int numBits = sizeof(n) * 8;       
        for(int i=0; i<numBits; i++)
        {
            if(n & (1<<i))
            {
                revNum |= 1 << ((numBits - 1) - i);
            }
        }
        return revNum;
    }
};
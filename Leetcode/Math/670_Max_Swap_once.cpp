// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

// Example 1:
// Input: 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.

// Example 2:
// Input: 9973
// Output: 9973

// Explanation: No swap.
// Note:
// The given number is in the range [0, 108]

// https://leetcode.com/problems/maximum-swap/

/*
iterate through the num starting from 0th index
find max number greater than 0th index
- if found swap and be done
*/

class Solution {
public:
    int maximumSwap(int num) {
        if(num == 0)
            return num;
        
        string numStr = to_string(num);
        
        for(int idx = 0; idx < numStr.size(); idx++)
        {
            int curMax = numStr[idx] - '0';
            int swapIdx = idx;
            
            for(int i = idx + 1; i < numStr.size(); i++)
            {
                // NOTE - equal to sign is required for cases like 1993
                // without equal to - ans = 9193
                // with equal to - ans = 9913
                if(numStr[i] - '0' >= curMax)
                {
                    swapIdx = i;
                    curMax = numStr[i] - '0';
                }
            }
            
            if(curMax != numStr[idx] - '0')
            {
                swap(numStr[swapIdx], numStr[idx]);
                return stoi(numStr);
            }
        }
        
        return num;
    }
};
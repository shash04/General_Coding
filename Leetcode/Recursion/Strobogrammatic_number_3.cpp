// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

// Example:
// Input: low = "50", high = "100"
// Output: 3 
// Explanation: 69, 88, and 96 are three strobogrammatic numbers.
// Note:
// Because the range might be a large number, the low and high numbers are represented as string.

// https://leetcode.com/problems/strobogrammatic-number-iii/

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int smallSize = low.size();
        int largeSize = high.size();
        int retCount = 0;
        
        vector<string> strNums;
        for(int i=smallSize; i<=largeSize; i++)
        {
            strNums = getStrobogrammaticNums(i,i);          // Get all strobogrammatic nums for every size
            retCount += strNums.size();
            if(i == smallSize)                              // Decrement count for nums lower than low
            {
                for(int j=0; j<strNums.size(); j++)
                {
                    if(strNums[j] < low)
                        retCount--;
                }
            }
            if(i == largeSize)                              // Decrement count for nums higher than high
            {
                for(int j=0; j<strNums.size(); j++)
                {
                    if(strNums[j] > high)
                        retCount--;
                }
            }
        }
        return retCount;
    }
    
    vector<string> getStrobogrammaticNums(int m, int n)     // Reusing from strobogrammatic number II
    {
        vector<string> v1;
        if(m == 0)
        {
            v1.push_back("");
            return v1;
        }
        if(m == 1)
        {
            v1 = {{'0'}, {'1'}, {'8'}};
            return v1;
        }
        
        vector<string> curr = getStrobogrammaticNums(m-2, n);
        vector<string> ret;

        for(int i=0; i<curr.size(); i++)
        {
            if(m != n)
                ret.push_back("0" + curr[i] + "0");     // Middle chars can be 0. Applicable only for recursive calls
            ret.push_back("1" + curr[i] + "1");
            ret.push_back("6" + curr[i] + "9");
            ret.push_back("8" + curr[i] + "8");
            ret.push_back("9" + curr[i] + "6");
        }
        return ret;
    }
};
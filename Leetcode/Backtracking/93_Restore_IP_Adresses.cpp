// Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s.
// You can return them in any order.

// A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and
// cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses
// and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 


// Example 1:
// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]

// Example 2:
// Input: s = "0000"
// Output: ["0.0.0.0"]

// Example 3:
// Input: s = "1111"
// Output: ["1.1.1.1"]

// Example 4:
// Input: s = "010010"
// Output: ["0.10.0.10","0.100.1.0"]

// Example 5:
// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

// Constraints:
// 0 <= s.length <= 3000
// s consists of digits only.

// https://leetcode.com/problems/restore-ip-addresses/


// ********************************************************************************************************
// ITERATIVE SOLUTION with HACKY method
// ********************************************************************************************************

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> retVec;
        
        for(int a=1; a <= 3; a++)
        {
            for(int b=1; b <= 3; b++)
            {
                for(int c=1; c <= 3; c++)
                {
                    for(int d=1; d <= 3; d++)
                    {
                        // Ignore all the cases where the sum of all len doesn't add up to s.size()
                        if((a + b + c + d) != s.size())
                            continue;
                        
                        // Get int values for each segments
                        int A = stoi(s.substr(0, a));
                        int B = stoi(s.substr(a, b));
                        int C = stoi(s.substr(a+b, c));
                        int D = stoi(s.substr(a+b+c, d));
                        
                        // Check if each segment is valid
                        if(A <= 255 && B <= 255 && C <= 255 && D <= 255)
                        {
                            string ipStr = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                            
                            // Rules out the case where any of the segment starts with 0
                            if(ipStr.size() == s.size() + 3)
                                retVec.push_back(ipStr);
                        }
                    }
                }
            }
        }
        
        return retVec;
    }
};

// ********************************************************************************************************
// BACTRACKING SOLUTION
// ********************************************************************************************************
/*
backtracking :
- at every step
    - add a char
        - check if stoi <= 255
        - size of segment is <= 3
    - OR add a dot
        - same above conditions are met + segment doesn't have leading zeros
            - curStr += segment
        - segment.clear()
        
- recursive call with index + 1
*/

class Solution {
    bool isValidSegment(string& segment)
    {
        if((stoi(segment) > 255) || (segment.size() > 1 && segment[0] == '0'))
            return false;
        
        return true;
    }
    
    void backtrack(vector<string>& result, string& s, string curStr, string segment, int idx, int dotCount)
    {
        if(segment.size() > 3 || dotCount < 0)
            return;
        
        if(idx == s.size())
        {
            if(dotCount == 0 && isValidSegment(segment))
                result.push_back(curStr + segment);
            return;
        }
        
        string nextSeg = segment + s[idx];
        
        if(isValidSegment(nextSeg))
            backtrack(result, s, curStr, nextSeg, idx + 1, dotCount);
        
        if(segment.size() > 0)
        {
            if(!isValidSegment(segment))
                return;
            
            backtrack(result, s, curStr + segment + '.', "", idx, dotCount - 1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() == 0 || s.size() > 12)
            return {};
        
        vector<string> result;
        
        backtrack(result, s, "", "", 0, 3);
        
        return result;
    }
};
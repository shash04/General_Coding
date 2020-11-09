// Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.
// Since the answer may not fit in an integer data type, return the answer as a string.
// If there is no answer return an empty string.

// Example 1:
// Input: digits = [8,1,9]
// Output: "981"

// Example 2:
// Input: digits = [8,6,7,1,0]
// Output: "8760"

// Example 3:
// Input: digits = [1]
// Output: ""

// Example 4:
// Input: digits = [0,0,0,0,0,0]
// Output: "0"

// https://leetcode.com/contest/weekly-contest-177/problems/largest-multiple-of-three/

class Solution {
    void queueToVec(vector<int>& vec, queue<int>& q)
    {
        while(!q.empty())
        {
            vec.push_back(q.front());
            q.pop();
        }
    }
public:
    string largestMultipleOfThree(vector<int>& digits) {
        if(digits.size() == 0)
            return "";
        
        string retStr;
        
        sort(digits.begin(), digits.end());
        
        // Three queues for digits with remainder 0, 1, 2 after dividing by 3
        queue<int> q0, q1, q2;
        
        int sum = 0;
        
        for(int i; i<digits.size(); i++)
        {
            sum += digits[i];
            
            if(digits[i] % 3 == 0)
                q0.push(digits[i]);
            
            else if(digits[i] % 3 == 1)
                q1.push(digits[i]);
            
            else if(digits[i] % 3 == 2)
                q2.push(digits[i]);
        }
        
        // if sum % 3 == 1, remove one digit from q1 or 2 digits from q2
        // if not possible, return
        if(sum % 3 == 1)
        {
            if(!q1.empty())
                q1.pop();
            else
            {
                for(int i=0; i<2; i++)
                {
                    if(!q2.empty())
                        q2.pop();
                    else
                        return "";
                }
            }
        }
        
        // if sum % 3 == 1, remove one digit from q1 or 2 digits from q2
        // if not possible, return
        if(sum % 3 == 2)
        {
            if(!q2.empty())
                q2.pop();
            else
            {
                for(int i=0; i<2; i++)
                {
                    if(!q1.empty())
                        q1.pop();
                    else
                        return "";
                }
            }
        }
        
        // Make a vector of all valid digits
        vector<int> retDigits;
        
        queueToVec(retDigits, q0);
        queueToVec(retDigits, q1);
        queueToVec(retDigits, q2);
        
        sort(retDigits.begin(), retDigits.end(), greater<int>());
        
        // Corner case of all zeros. Return "0" instead of "0000"
        bool allZero = true;
        
        for(int i=0; i<retDigits.size(); i++)
        {
            retStr += to_string(retDigits[i]);
            if(retDigits[i] != 0)
                allZero = false;
        }
        
        if(allZero && retStr.size() > 0)
            return "0";
        
        return retStr;
    }
};
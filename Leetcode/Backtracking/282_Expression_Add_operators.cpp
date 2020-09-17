// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or *
// between the digits so they evaluate to the target value.

// Example 1:
// Input: num = "123", target = 6
// Output: ["1+2+3", "1*2*3"] 

// Example 2:
// Input: num = "232", target = 8
// Output: ["2*3+2", "2+3*2"]

// Example 3:
// Input: num = "105", target = 5
// Output: ["1*0+5","10-5"]

// Example 4:
// Input: num = "00", target = 0
// Output: ["0+0", "0-0", "0*0"]

// Example 5:
// Input: num = "3456237490", target = 9191
// Output: []

// Constraints:
// 0 <= num.length <= 10
// num only contain digits.

// https://leetcode.com/problems/expression-add-operators/

class Solution {
    void helper(vector<string>& result, long curVal, int prev, string curStr, int idx, string& num, int target)
    {
        if(idx == num.size())
        {
            if(target == curVal)
                result.push_back(curStr);
            
            return;
        }
        
        for(int i = 1; i <= num.size() - idx; i++)
        {
            // iterate and add consecutive num to form bigger num without operand in between
            string curNumStr = num.substr(idx, i);
            
            // ignore cases with preceding 0s
            if(i > 1 && curNumStr[0] == '0')
                continue;
            
            long curNum = stol(curNumStr, nullptr, 10);
            
            // special case for zero-th index as operand insertion starts from first index
            if(idx == 0)
            {
                helper(result, curNum, curNum, curNumStr, idx + i, num, target);
                continue;
            }
            
            helper(result, curVal + curNum, curNum, curStr + "+" + curNumStr, idx + i, num, target);
            helper(result, curVal - curNum, -curNum, curStr + "-" + curNumStr, idx + i, num, target);
            
            long mulAns = curVal - prev + prev * curNum;
            
            helper(result, mulAns, prev * curNum, curStr + "*" + curNumStr, idx + i, num, target);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        
        if(num.size() == 0)
            return result;
        
        // Optimization that makes it pass on leetcode - could be skipped in real interview
        if (stol(num) == (long)target && num[0] != '0')
        {
            result.push_back(num);
            return result;
        }
        
        helper(result, 0, 0, "", 0, num, target);
        
        return result;
    }
};
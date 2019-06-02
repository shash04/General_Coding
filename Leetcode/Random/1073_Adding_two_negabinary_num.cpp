// Given two numbers arr1 and arr2 in base -2, return the result of adding them together.
// Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.
// For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.
// A number arr in array format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.
// Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.

// Example 1:
// Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
// Output: [1,0,0,0,0]
// Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.

// Note:
// 1 <= arr1.length <= 1000
// 1 <= arr2.length <= 1000
// arr1 and arr2 have no leading zeros
// arr1[i] is 0 or 1
// arr2[i] is 0 or 1

// https://leetcode.com/contest/weekly-contest-139/problems/adding-two-negabinary-numbers/

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        if(!arr1.size())
            return arr2;
        if(!arr2.size())
            return arr1;

        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());

        vector<int> result;
        
        int i=0, j=0, carry=0;
        
        for (; i < arr1.size() && j < arr2.size(); i++, j++)
        {
            int sum = arr1[i] + arr2[j] + carry;
            carry = add(sum, result);
        }
        
        for (; i < arr1.size(); i++)
        {
            int sum = arr1[i] + carry;
            carry = add(sum, result);
        }
        
        for (; j < arr2.size(); j++)
        {
            int sum = arr2[j] + carry;
            carry = add(sum, result);
        }
        
        for (; carry != 0;)
        {
            carry = add(carry, result);
        }
        
        while (!result.empty() && result.back() == 0) 
            result.pop_back();
        
        if (result.empty())
            result.push_back(0);

        reverse(result.begin(), result.end());
        return result;
    }
    
    int add(int sum, vector<int>& ret)
    {
        if (sum == 0)                       // 0 == 0 
        {
            ret.push_back(0);
            return 0;
        }
        else if (sum == 1)                  // 1 == 1
        {
            ret.push_back(1);
            return 0;
        }
        else if (sum == 2)                  // 2 == 110
        {
            ret.push_back(0);
            return -1;                      // Carry = 11 = (-2)^1 + (-2)^0 = -1
        }
        else if (sum == -1)                 // -1 == 11
        {
            ret.push_back(1);
            return 1;
        }
        else if (sum == 3)                  // 3 == 111
        {
            ret.push_back(1);
            return -1;                      // Carry = 11 = (-2)^1 + (-2)^0 = -1
        }
        return 0;
    }
};

// ***********************************************************************************
// NOT A SOLUTION.... BUFFER OVERFLOW
// ***********************************************************************************
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        if(!arr1.size())
            return arr2;
        if(!arr2.size())
            return arr1;
        
        long long num1 = getNum(arr1);
        long long num2 = getNum(arr2);
        
        cout<<num1<<"  "<<num2<<endl;
        
        long long sum = num1 + num2;
        
        return getBaseNegTwo(sum);
    }
    
    long long getNum(vector<int>& arr1)
    {
        long long ret = 0;
        for(int i=0; i<arr1.size(); i++)
        {
            if(arr1[i])
                ret += pow(-2, i);
        }
        return ret;
    }
    
    vector<int> getBaseNegTwo(long long num)
    {
        vector<int> ans;
        if(num == 0)
            ans.push_back(0);
        while(num)
        {
            int bit = num % (-2);
            ans.push_back(bit);
            num = num / (-2);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

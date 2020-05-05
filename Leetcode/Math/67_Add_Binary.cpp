// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 

// Constraints:

// Each string consists only of '0' or '1' characters.
// 1 <= a.length, b.length <= 10^4
// Each string is either "0" or doesn't contain any leading zero.

// https://leetcode.com/problems/add-binary/

#define stoi(c) (c - '0')

class Solution {
public:
    string addBinary(string a, string b) {
        string sumAns;
        
        int lenA = a.size();
        int lenB = b.size();
        
        int idxA = lenA - 1, idxB = lenB - 1;
        int carry = 0;
        
        while(idxA >= 0 && idxB >= 0)
        {
            int A = stoi(a[idxA]);
            int B = stoi(b[idxB]);
            
            int sum =  A ^ B ^ carry;
            carry = (A & B) | (A & carry) | (B & carry);
            
            sumAns = to_string(sum) + sumAns;
            
            idxA--; idxB--;
        }
        
        while(idxA >= 0)
        {
            int A = stoi(a[idxA]);
            int sum =  A ^ carry;
            carry = A & carry;
            sumAns = to_string(sum) + sumAns;
            idxA--;
        }
        
        while(idxB >= 0)
        {
            int B = stoi(b[idxB]);
            int sum =  B ^ carry;
            carry = B & carry;
            sumAns = to_string(sum) + sumAns;
            idxB--;
        }
        
        if(carry)
            sumAns = to_string(carry) + sumAns;
        
        return sumAns;
    }
};
// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// https://leetcode.com/problems/ugly-number-ii/

// Solution 1 - Dynamic programming
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> ugly_no(n);
        ugly_no[0] = 1;
        
        for(int i=1; i<n ; i++)
        {
            ugly_no[i] = min(ugly_no[t2]*2, min(ugly_no[t3]*3, ugly_no[t5]*5));
            
            if(ugly_no[i] == ugly_no[t2]*2)
                t2++; 
            if(ugly_no[i] == ugly_no[t3]*3)
                t3++;
            if(ugly_no[i] == ugly_no[t5]*5)
                t5++;
        }
        return ugly_no[n-1];
    }
    
};

// Solution 2: Crude solution....very time consuming
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0)
            return 0;
        
        vector<int> prime_no;
        vector<int> ugly_no;
        for(int f=1; f<6; f++)
            ugly_no.push_back(f);
        
        for(int i=6; ugly_no.size()<n; i++)
        {
            if(isPrime(i))
            {
                prime_no.push_back(i);
            }
            else
            {
                bool isUgly = true;
                for(int k=0; k<prime_no.size(); k++)
                {
                    if(i % prime_no[k] == 0)
                        isUgly = false;
                }
                if(isUgly)
                    ugly_no.push_back(i);
            }
        }
        
        return ugly_no[n-1];
    }
    
    bool isPrime(int n)
    {
        for(int j=2; j<=sqrt(n); j++)
        {
            if(n%j == 0)
                return false;
        }
        return true;
    }
};
// Write a program that outputs the string representation of numbers from 1 to n.

// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”.
// For numbers which are multiples of both three and five output “FizzBuzz”.

// https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        
        for(int i=1; i<=n; i++)
        {
            if(i%15 == 0)
                ret.push_back("FizzBuzz");
            else if(i%5 == 0)
                ret.push_back("Buzz");
            else if(i%3 == 0)
                ret.push_back("Fizz");
            else
                ret.push_back(to_string(i));
        }
        return ret;
    }
};
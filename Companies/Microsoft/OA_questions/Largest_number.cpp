// Write a function that, given an array A of N integers, returns the lagest integer K > 0 such that
// both values K and -K exisit in array A. If there is no such integer, the function should return 0.

// Example 1:
// Input: [3, 2, -2, 5, -3]
// Output: 3

// Example 2:
// Input: [1, 2, 3, -4]
// Output: 0

// https://leetcode.com/discuss/interview-question/406031/

int getLargestK(vector<int>& nums)
{
    int maxVal = 0;
    unordered_set<int> s1;
    
    for (auto& n:nums)
        s1.insert(n);
    
    for (auto& n:nums)
    {
        if (s1.find(-n) != s1.end() && n > maxVal) 
        {
            maxVal = n;
        }
    }
    
    return maxVal;
}

int main() {
    vector<int> v1 = {3, 2, -2, 5, -3};
    cout<<getLargestK(v1)<<endl;
}
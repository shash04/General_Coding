// In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.
// Return the element repeated N times.

// Example 1:
// Input: [1,2,3,3]
// Output: 3

// Example 2:
// Input: [2,1,2,5,3,2]
// Output: 2

// Example 3:
// Input: [5,1,5,2,5,3,5,4]
// Output: 5

// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/


// Use this function if you want to incerase I/O speed
// Refer https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> num;
        for(int i=0; i<A.size(); i++)
        {
            if(num.find(A[i]) != num.end())
                return A[i];
            num.insert(A[i]);
        }
        return -1;
    }
};
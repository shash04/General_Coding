// Write a function:
// class Solution { public int solution(int[] A);)
// that, given an array A consisting of N integers, returns the maximum sum of two numbers whose digits add up to an equal sum.
// If there are no two numbers whose digits have an equal sum, the function should return -1.
// Examples:
// 1. Given A = [51, 71, 17,42), the function should return 93.
// There are two pairs of numbers whose digits add up to an equal sum: (51, 42) and (17,71). The first pair sums up to 93.

// 2. Given A = 142, 33, 60), the function should return 102.
// The digits of all numbers in A add up to the same sum, and choosing to add 42 and 60 gives the result 102.

// 3. Given A = [51, 32, 43], the function should return -1,
// since all numbers in A have digits that add up to different, unique sums.

// Write an efficient algorithm for the following assumptions:
// • N is an integer within the range [1..200,000];
// each element of array A is an integer within the range [1.. 1,000,000,000].

// https://leetcode.com/discuss/interview-question/365872/

typedef priority_queue<int> MAX_HEAP;

int findMaxSum(vector<int> arr)
{
    if(arr.size() == 0)
        return -1;

    unordered_map<int, MAX_HEAP> m1;
    int maxSum = -1;

    for(int num : arr)
    {
        int sum = 0;
        int temp = num;
        while(temp)
        {
            sum += temp % 10;
            temp = temp / 10;
        }
        m1[sum].push(num);
    }

    for(auto entry : m1)
    {
        auto currQ = entry.second;

        if(currQ.size() < 2)
            continue;
        
        int n1 = currQ.top(); currQ.pop();
        int n2 = currQ.top(); currQ.pop();

        maxSum = max(maxSum, (n1 + n2));
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {65, 31, 17, 42};
    int ans = findMaxSum(arr);
    cout<<"Max Sum is = "<<ans<<endl;
}
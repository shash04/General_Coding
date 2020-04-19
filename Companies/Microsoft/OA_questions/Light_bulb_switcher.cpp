// There are N bulbs, numbered from 1 to N, arranged in a row. Initially, all the bulbs are turned off.
// At moment K (for K from 0 to N - 1), we turn on the A[K]-th bulb. A bulb shines if it is on and all the previous bulbs are turned on too.
// Return the number of moments for which every turned on bulb shines.

// Example 1:
// Input: A = [2, 1, 3, 5, 4]
// Output: 3

// Example 2:
// Input: A = [2, 3, 4, 1, 5]
// Output: 2

// Example 3:
// Input: A = [5, 4, 3, 2, 1]
// Output: 1

// N is an integer within the range [1..100,000]
// the elements of A are all distinct
// each element of array A is an integer within the range [1..N]

// https://leetcode.com/discuss/interview-question/502549/

int countNumShines(const vector<int>& arr)
{
    if(arr.size() == 0)
        return 0;

    int ans = 0;
    int sum = 0, target = 0;

    for(int i=1; i <= arr.size(); i++)
    {
        sum += arr[i-1];
        target += i;

        if(sum == target)
            ans++;
    }

    return ans;
}

/*
Faster way to do same thing - 

int countNumShines(const vector<int>& light)
{
    int numTimes = 0;
    int rightMostLitBulb = 0;

    for(int i=0; i < light.size(); i++)
    {
        rightMostLitBulb = max(rightMostLitBulb, light[i]);

        if(rightMostLitBulb == i+1)
            numTimes++;
    }

    return numTimes;
}

*/

int main() {
    vector<int> arr1 = {2,1,3,4,5};
    vector<int> arr2 = {2,3,4,1,5};
    vector<int> arr3 = {5,4,3,2,1};
    
    int ans1 = countNumShines(arr1);
    int ans2 = countNumShines(arr2);
    int ans3 = countNumShines(arr3);
    
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
}

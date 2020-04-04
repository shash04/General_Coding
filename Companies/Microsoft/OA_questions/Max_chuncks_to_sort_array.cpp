// We are given an array A consisting of N distinct integers. We would like to sort array A into ascending order using a simple algorithm.
// First, we divide it into one or more slices (a slice is a contiguous subarray). Then we sort each slice.
// After that, we join the sorted slices in the same order.
// Write a function solution that returns the maximum number of slices for which the algorithm will return a correctly sorted array

// Examples: 1. Given A = 12.4.1.6.5.9. 71. the function should return 3.
// The array can be split into three slices: (2,4, 1), (6,5) and (9,7).
// Then, after sorting each slice and joining them together, the whole array will be sorted into ascending order.

// 2. Given A = [4.3, 2, 6, 1), the function should return 1.
// The array cannot be split into smaller slices; it has to be sorted all at once.

// 3. Given A = 12, 1, 6,4,3,7). the function should return 3.

// Write an efficient algorithm for the following assumptions:
// • N is an integer within the range [1..100,000);
// • each element of array A is an integer within the range (1..1,000,000,000 • the elements of A are all distinct.

// https://leetcode.com/discuss/interview-question/524146/

// Simliar to https://leetcode.com/problems/max-chunks-to-make-sorted/

int maxChunksToSortArr(vector<int>& arr)
{
    int arrSize = arr.size();
    if (arrSize < 3)
        return 1;
    
    int maxChunks = 0;
    vector<int> minIdxToRight(arrSize, 0);
    int currMin = arr[arrSize - 1];
    int minIdx = arrSize - 1;
    
    // Populate minIdxToRight vec with indices of min val to the right of curr index
    for (int i=arrSize-1; i >= 0; i--)
    {
        minIdxToRight[i] = minIdx;
        if (arr[i] < currMin)
        {
            currMin = arr[i];
            minIdx = i;
        }
    }
    
    // Jump to every min Idx and increment max chunks counter
    int currIdx = 0;
    while (currIdx != arrSize - 1)
    {
        maxChunks++;
        currIdx = minIdxToRight[currIdx];
    }
    
    return maxChunks;
}

int main(){
    vector<int> v1 = {2,4,1,6,5,9,7};
    vector<int> v2 = {4,3,2,6,1};
    vector<int> v3 = {2,1,6,4,3,7};
    cout<<maxChunksToSortArr(v1)<<endl;
    cout<<maxChunksToSortArr(v2)<<endl;
    cout<<maxChunksToSortArr(v3)<<endl;
}
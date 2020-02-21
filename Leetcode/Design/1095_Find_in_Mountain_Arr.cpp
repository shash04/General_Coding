// (This problem is an interactive problem.)
// You may recall that an array A is a mountain array if and only if:

// A.length >= 3
// There exists some i with 0 < i < A.length - 1 such that:
// A[0] < A[1] < ... A[i-1] < A[i]
// A[i] > A[i+1] > ... > A[A.length - 1]
// Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.
// If such an index doesn't exist, return -1.

// You can't access the mountain array directly.  You may only access the array using a MountainArray interface:

// MountainArray.get(k) returns the element of the array at index k (0-indexed).
// MountainArray.length() returns the length of the array.
// Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. 
// Also, any solutions that attempt to circumvent the judge will result in disqualification.


// Example 1:
// Input: array = [1,2,3,4,5,3,1], target = 3
// Output: 2
// Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

// Example 2:
// Input: array = [0,1,2,4,2,1], target = 3
// Output: -1
// Explanation: 3 does not exist in the array, so we return -1.

// https://leetcode.com/problems/find-in-mountain-array/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// Concept :
// 1) find the pivot element index - pIdx = arr[pIdx] > arr[pIdx-1] && arr[pIdx] > arr[pIdx+1]
// 2a) Do binary search in arr before and till pIdx
// 2b) if 2a returns -1, do binary search in arr after pIdx till end of arr
// 3) if found return index or return -1

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if(mountainArr.length() < 3)
            return -1;
        
        int pIdx = 0;
        int low = 0;
        int high = mountainArr.length() - 1;
        
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            
            int midVal = mountainArr.get(mid);
            int preVal = mountainArr.get(mid-1);
            int postVal = mountainArr.get(mid+1);
            
            if(midVal > preVal && midVal > postVal)
            {
                pIdx = mid;
                break;
            }
            else if(midVal > preVal)
                low = mid + 1;
            else
                high = mid;
        }
        
        int retIdx = findTarget(mountainArr, target, 0, pIdx, true);
        
        if(retIdx == -1)
            retIdx = findTarget(mountainArr, target, pIdx+1, mountainArr.length() - 1, false);
        
        return retIdx;
    }
    
    int findTarget(MountainArray &mountainArr, const int& target, int low, int high, const bool& isIncrementing)
    {
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int midVal = mountainArr.get(mid);
            
            if(midVal == target)
                return mid;
            else
            {
                if(isIncrementing)
                {
                    if(midVal > target)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                else
                {
                    if(midVal > target)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }
        return -1;
    }
};
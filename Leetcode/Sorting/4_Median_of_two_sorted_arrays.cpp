// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// You may assume nums1 and nums2 cannot be both empty.

// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0

// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5

// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Logic from https://www.youtube.com/watch?v=LPFhl65R7ww&feature=youtu.be

// Take minimum size of two array. Possible number of partitions are from 0 to m in m size array.
// Try every cut in binary search way. When you cut first array at i then you cut second array at (m + n + 1)/2 - i
// Now try to find the i where a[i-1] <= b[j] and b[j-1] <= a[i]. So this i is partition around which lies the median.
// Time complexity is O(log(min(x,y))
// Space complexity is O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        if(x > y)
            return findMedianSortedArrays(nums2, nums1);
        
        int low = 0;
        int high = x;
        
        while(low <= high)
        {
            int partitionX = (low + high) / 2;
            int partitionY = ((x + y + 1) / 2) - partitionX;                        // +1 as it plays well for both odd and even arrays
            
            int maxLeftX    = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];  // val == 0 indicates all elements on right side
            int minRightX   = (partitionX == x) ? INT_MAX : nums1[partitionX];      // val == x indicates all elements on left side
            
            int maxLeftY    = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];  // val == 0 indicates all elements on right side
            int minRightY   = (partitionY == y) ? INT_MAX : nums2[partitionY];      // val == y indicates all elements on left side
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX)                      // If true == Perfect partitions found
            {
                // If combined array has even num of elements == avg of max of left side and min of right side for both arrays
                if((x + y) % 2 == 0)
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                else
                    return (double)max(maxLeftX, maxLeftY);                         // If odd num of elements max of left side for both arrays
            }
            else if(maxLeftX > minRightY)
                high = partitionX - 1;
            else
                low = partitionX + 1;
        }
        return 0;
    }
};
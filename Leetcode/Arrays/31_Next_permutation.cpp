// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place and use only constant extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

// https://leetcode.com/problems/next-permutation/

// Step1 = Start from its last element, traverse backward to find the first one with index i that satisfy num[i-1] < num[i].
// So, elements from num[i] to num[n-1] is reversely sorted.
// Step 2 = To find the next permutation, we have to swap some numbers at different positions, to minimize the increased amount,
// we have to make the highest changed position as high as possible. Notice that index larger than or equal to i is not possible
// as num[i,n-1] is reversely sorted. So, we want to increase the number at index i-1, clearly, swap it with the smallest number
// between num[i,n-1] that is larger than num[i-1]. For example, original number is 121543321, we want to swap the '1' at position 2 with '2' at position 7.
// Step 3 = The last step is to make the remaining higher position part as small as possible, we just have to reversely sort the num[i,n-1]

// **********************************************************************************
// Refactored code
// **********************************************************************************

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = 0;
    
        for(int i=nums.size() - 1; i > 0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                index = i;
                break;
            }
        }
        
        if(index == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=nums.size() - 1; i >= index; i--)
        {
            if(nums[i] > nums[index-1])
            {
                swap(nums[i], nums[index-1]);
                break;
            }
        }
        
        reverse(nums.begin() + index, nums.end());
    }
};

// **********************************************************************************
// Original code
// **********************************************************************************
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if( len < 2 )
            return;

        int i = len - 1;
        int index;
        for(; i>0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                index = i;
                break;
            }
        }
        
        if(i == 0)
        {
            reverseOrder(nums, 0, len-1);
            return;
        }
        
        for(int j=len-1; j>=index; j--)
        {
            if(nums[j] > nums[index-1])
            {
                swap(nums, index-1, j);
                break;
            }
        }
        
        reverseOrder(nums, index, len-1);
    }
    
    void swap(vector<int>& nums, int pos1, int pos2)
    {
        int temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }
    
    void reverseOrder(vector<int>& nums, int start, int end)
    {
        if(start>end)
            return;
        for(int i=start; i<=(start+end)/2; i++)
        {
            swap(nums, i, start+end-i);
        }
    }
};

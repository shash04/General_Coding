// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Example 1:
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5

// Example 2:
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4

// https://leetcode.com/problems/kth-largest-element-in-an-array/

// ****************************************************************************
// Using default C++ nth_element function
// ****************************************************************************
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        nth_element(nums.begin(), nums.begin()+index, nums.end(), compare);
        return nums[index];
    }
    
    static bool compare(int& a, int& b)
    {
        return a < b;
    }
};

// ****************************************************************************
// Max Heap using priority_queue
// ****************************************************************************
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        
        for (int i = 0; i < k - 1; i++)
        {
            pq.pop();
        }
        
        return pq.top();
    }
};

// ****************************************************************************
// Min heap using priority queue
// ****************************************************************************
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

// ****************************************************************************
// Max Heap using multiset
// ****************************************************************************
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> mset(nums.begin(), nums.end());

        for (int i = 0; i < k - 1; i++)
        {
            mset.erase(mset.begin());
        }
        return *mset.begin();
    }
};

// ****************************************************************************
// Min heap using multiset
// ****************************************************************************
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;

        for (int num : nums)
        {
            mset.insert(num);
            if (mset.size() > k)
            {
                mset.erase(mset.begin());
            }
        }
        return *mset.begin();
    }
};
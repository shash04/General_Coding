// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        
        while(nums[end] == 0)
        {
            end--;
        }
        
        for(int i=end-1; i>=0; i--)
        {
            if(nums[i] == 0)
            {
                for(int j=i; j<end; j++)
                {
                    nums[j] = nums[j+1];
                }
                nums[end] = 0;
                end--;
            }
        }
    }
};
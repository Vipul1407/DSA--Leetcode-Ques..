class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        sort(begin(nums),end(nums));
        int n= nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i])
            {
                return nums[i];
            }
        }
        return -1;
    }
};
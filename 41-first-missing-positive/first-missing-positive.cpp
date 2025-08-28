class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};
// 8 5 -1 1 2 3 6 4   ,n=8
// 4 5 -1 1 2 3 6 8   ,swap(8,4)
// 1 5 -1 4 2 3 6 8   
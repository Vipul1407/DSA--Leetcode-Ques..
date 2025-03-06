class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int n= nums.size();
        int k=0;
        int ans=nums[0];
        int sum= nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                sum+= nums[i];
                ans = max(ans,sum);
            }
            else
            {
                sum= nums[i];
            }
        }
        return ans;
    }
};
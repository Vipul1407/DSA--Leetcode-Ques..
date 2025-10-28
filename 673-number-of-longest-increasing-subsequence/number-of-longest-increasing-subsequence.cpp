class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        vector<int>dp(n,1);
        int LIS=-1;
        vector<int>cnt(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[i]< 1+dp[j])
                    {
                        dp[i]= 1+dp[j];
                        cnt[i]= cnt[j];
                    }
                    else if(dp[i]==1+dp[j])
                    {
                        cnt[i]+= cnt[j];
                    }
                }
            }
            LIS= max(LIS,dp[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==LIS)
            {
                ans+= cnt[i];
            }
        }
        return ans;
    }
};
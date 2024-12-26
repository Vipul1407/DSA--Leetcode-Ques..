class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int tar) 
    {
        int n= nums.size();
        int S= accumulate(nums.begin(),nums.end(),0);
        if(tar<-S || tar>S)
        {
            return 0;
        }
        vector<vector<int>>dp(n+1,vector<int>(2*S+1,0));

        dp[n][S]=1;//base case..
        for(int i=n-1;i>=0;i--)
        {
            for(int sum=-S;sum<=S;sum++)
            {
                int plus=0;
                int minus=0;
                if(sum+nums[i]+S<=2*S)
                {
                    plus= dp[i+1][sum+nums[i]+S];
                }
                if(sum-nums[i]+S>=0)
                {
                    minus= dp[i+1][sum-nums[i]+S];
                }
                dp[i][sum+S]= plus+minus;
            }
        }
        return dp[0][tar+S]; 
    }
};

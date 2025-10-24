class Solution {
public:
    //METHOD-3
    //BUA..
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int previdx=n-1;previdx>=-1;previdx--)
            {
                int take=0;
                if(previdx==-1 || nums[previdx]<nums[i])
                {
                    take= 1+dp[i+1][i+1];//making it y= i+1 
                }
                int notake= dp[i+1][previdx+1];
                dp[i][previdx+1]= max(take,notake);
            }
        }
        return dp[0][0];
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i, int previdx, vector<int>& nums)
    {
        if(i>= nums.size())
        {
            return 0;
        }
        int take=0;
        if(previdx==-1 || nums[previdx]<nums[i])
        {
            take= 1+rec(i+1,i,nums);
        }
        int notake= rec(i+1,previdx,nums);
        return max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        return rec(0,-1,nums);
    }

    //METHOD-2
    //TDA..
    int rec(int i, int previdx, vector<int>& nums, vector<vector<int>>&dp)
    {
        if(i>= nums.size())
        {
            return 0;
        }
        if(dp[i][previdx+1]!=-1)
        {
            return dp[i][previdx+1];
        }
        int take=0;
        if(previdx==-1 || nums[previdx]<nums[i])
        {
            take= 1+rec(i+1,i,nums,dp);
        }
        int notake= rec(i+1,previdx,nums,dp);
        return dp[i][previdx+1]= max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return rec(0,-1,nums,dp);
    }
*/
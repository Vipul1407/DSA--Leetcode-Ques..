class Solution {
public:
    //METHOD-2
    //TDA
    int tda(int i,vector<int>& nums, vector<int>&dp)
    {
        if(i>= nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int take= nums[i]+tda(i+2,nums,dp);
        int notake= tda(i+1,nums,dp);
        return dp[i]= max(take,notake);
    }
    int rob(vector<int>& nums) 
    {
        vector<int>dp(nums.size(),-1);
        return tda(0,nums,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,vector<int>& nums)
    {
        if(i>= nums.size())
        {
            return 0;
        }
        int take= nums[i]+rec(i+2,nums);
        int notake= rec(i+1,nums);
        return max(take,notake);
    }
    int rob(vector<int>& nums) 
    {
        return rec(0,nums);
    }
*/
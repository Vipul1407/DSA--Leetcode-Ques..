class Solution {
public:
    //METHOD-2
    //TDA..
    int s=0;
    int rec(int i,vector<int>& nums,int tar,vector<vector<int>>&dp)
    {
        if(tar>s || tar<-s)
        {
            return 0;
        }
        if(i>=nums.size())
        {
            return tar==0;
        }
        if(dp[i][tar+s]!=-1)
        {
            return dp[i][tar+s];
        }
        //cannot take duplicates==> i+1
        int plus= rec(i+1,nums,tar-nums[i],dp);
        int neg= rec(i+1,nums,tar+nums[i],dp);
        return dp[i]  [tar+s]= plus + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        for(auto i:nums)
        {
            s+=i;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(2*s+1,-1));
        return rec(0,nums,target,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,vector<int>& nums,int tar)
    {
        if(i>=nums.size())
        {
            return tar==0;
        }
        //cannot take duplicates==> i+1
        int plus= rec(i+1,nums,tar-nums[i]);
        int neg= rec(i+1,nums,tar+nums[i]);
        return plus + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return rec(0,nums,target);
    }
*/
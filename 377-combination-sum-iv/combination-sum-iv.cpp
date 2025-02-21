class Solution {
public:
    int tda(int i,vector<int>& nums, int tar, vector<vector<int>>&dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(tar<0)
        {
            return 0;
        }
        if(tar==0)
        {
            return 1;
        }
        if(dp[tar][i]!=-1)
        {
            return dp[tar][i];
        }
        int take= tda(0,nums,tar-nums[i],dp);
        int notake= tda(i+1,nums,tar,dp);
        return dp[tar][i]= take+notake;
    }
    int combinationSum4(vector<int>& nums, int tar) 
    {
        vector<vector<int>>dp(1001,vector<int>(nums.size(),-1));
        return tda(0,nums,tar,dp);
    }
};
/*
// DP NOT BACKTRACKING..

// METHOD-1
int rec(int i, vector<int> &nums, int tar)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (tar < 0)
    {
        return 0;
    }
    if (tar == 0)
    {
        return 1;
    }
    // again start from 0 index as we can take that index again..
    int take = rec(0, nums, tar - nums[i]);
    int notake = rec(i + 1, nums, tar);
    return take + notake;
}
int combinationSum4(vector<int> &nums, int tar)
{
    return rec(0, nums, tar);
}
*/
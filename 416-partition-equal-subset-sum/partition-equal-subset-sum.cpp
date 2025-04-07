class Solution {
public:
    bool solve(int i,vector<int>& nums,int tar,vector<vector<int>>&dp)
    {
        if(i>=nums.size())
        {
            return false;
        }
        if(tar==0)
        {
            return true;
        }
        if(tar<0)
        {
            return false;
        }
        if(dp[i][tar]!=-1)
        {
            return dp[i][tar];
        }
        return dp[i][tar]= solve(i+1,nums,tar-nums[i],dp) || solve(i+1,nums,tar,dp);
    }
    bool canPartition(vector<int>& nums) 
    {
        int n= nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
        {
            return false;
        }
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        return solve(0,nums,sum/2,dp)? true:false;
    }
};
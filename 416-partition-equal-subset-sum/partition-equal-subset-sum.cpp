class Solution {
public:
    //METHOD-1
    //TDA..
    bool tda(int i,vector<int>& nums,int tar,vector<vector<int>>&dp)
    {
        if(tar==0)
        {
           return true; 
        }
        if(i>=nums.size() || tar<0)
        {
            return false;
        }
        if(dp[i][tar]!=-1)
        {
            return dp[i][tar];
        }
        //cannot take duplicates==> i+1
        bool take= tda(i+1,nums,tar-nums[i],dp);
        bool notake= tda(i+1,nums,tar,dp);
        return dp[i][tar]= take || notake;
    }
    bool canPartition(vector<int>& nums) 
    {
        int s= accumulate(begin(nums),end(nums),0);
        if(s%2!=0)
        {
            return false;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(s/2+1,-1));
        return tda(0,nums,s/2,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    bool rec(int i,vector<int>& nums,int tar)
    {
        if(tar==0)
        {
           return true; 
        }
        if(i>=nums.size() || tar<0)
        {
            return false;
        }
        //cannot take duplicates==> i+1
        bool take= rec(i+1,nums,tar-nums[i]);
        bool notake= rec(i+1,nums,tar);
        return take || notake;
    }
    bool canPartition(vector<int>& nums) 
    {
        int s= accumulate(begin(nums),end(nums),0);
        if(s%2!=0)
        {
            return false;
        }
        return rec(0,nums,s/2);
    }
*/
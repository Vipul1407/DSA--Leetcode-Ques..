class Solution {
public:
    //METHOD-3
    //BUA..
    int findTargetSumWays(vector<int>& nums, int tar) 
    {
        int s=0;
        int n= nums.size();
        for(auto i:nums)
        {
            s+=i;
        }
        if(tar>s || tar<-s)
        {
            return 0;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*s+1,0));
        //base case..
        //tar==0 return 1;
        // so we do target+s= 0+s= s to avoid runtime ..
        for(int i=0;i<=n;i++)
        {
            dp[i][s]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=-s;j<=s;j++)
            {
                int plus= (j-nums[i]>=-s)? dp[i+1][j-nums[i]+s]:0;
                int neg= (j+nums[i]<=s)? dp[i+1][j+nums[i]+s]:0;
                dp[i][j+s]= plus + neg;
            }
        }
        return dp[0][tar+s];
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
*/
class Solution {
public:
    //METHOD-2
    //TDA APPROACH..
    long long rec(int i,vector<int>& nums, int k, vector<long long>&dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        long long a= nums[i]+ rec(i+1,nums,k,dp);
        long long b= nums[i]+ rec(i+2,nums,k,dp);
        long long c= nums[i]+ rec(i+3,nums,k,dp);
        return dp[i]= min(a,min(b,c));
    }
    long long minIncrementOperations(vector<int>& nums, int k)
    {
        int n= nums.size();
    
        vector<long long>dp(n,-1);
        for(int i=0;i<n;i++)
        {
            nums[i]= max(0,k-nums[i]);
        }
        long long ans= rec(0,nums,k,dp);
        ans= min(ans,rec(1,nums,k,dp));
        ans= min(ans,rec(2,nums,k,dp));
        return ans;
    }
};
/*
    //METHOD-1
    //RECUSIVE APPROACH..
    long long rec(int i,vector<int>& nums, int k)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        long long a= nums[i]+ rec(i+1,nums,k);
        long long b= nums[i]+ rec(i+2,nums,k);
        long long c= nums[i]+ rec(i+3,nums,k);
        return min(a,min(b,c));
    }
    long long minIncrementOperations(vector<int>& nums, int k)
    {
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]= max(0,k-nums[i]);
        }
        long long ans= rec(0,nums,k);
        ans= min(ans,rec(1,nums,k));
        ans= min(ans,rec(2,nums,k));
        return ans;
    }
*/
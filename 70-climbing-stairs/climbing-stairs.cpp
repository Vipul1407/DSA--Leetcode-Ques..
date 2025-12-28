class Solution {
public:
    //METHOD-2
    //TDA..
    int tda(int i,int n, vector<int>&dp)
    {
        if(i==n)
        {
            return 1;
        }
        if(i>n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i]= tda(i+1,n,dp)+tda(i+2,n,dp);
    }
    int climbStairs(int n) 
    {
        vector<int>dp(n,-1);
        return tda(0,n,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,int n)
    {
        if(i==n)
        {
            return 1;
        }
        if(i>n)
        {
            return 0;
        }
        return rec(i+1,n)+rec(i+2,n);
    }
    int climbStairs(int n) 
    {
        return rec(0,n);
    }
*/
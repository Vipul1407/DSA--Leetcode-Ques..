class Solution {
public:
    //METHOD-3
    //BUA..
    int climbStairs(int n) 
    {
        vector<int>dp(n+2,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            dp[i]= dp[i+1]+dp[i+2];
        }
        return dp[0];
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
*/
class Solution {
public:
    //METHOD-1
    //TDA APPROACH..
    const int mod= 1000000007;
    int rec(int num,int n,int x, vector<vector<int>>&dp)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return 1;
        }
        long long curr= pow(num,x);
        if((int)curr>n)
        {
            return 0;
        }
        if(dp[num][n]!=-1)
        {
            return dp[num][n];
        }
        //go to next number..
        int take= rec(num+1,n-curr,x,dp);
        int skip= rec(num+1,n,x,dp);
        return dp[num][n]= (skip+take)%mod;
    }
    int numberOfWays(int n, int x) 
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec(1,n,x,dp)%mod;
    }
};
/*
    //METHOD-1
    //RECUSIVE APPROACH..
    int rec(int num,int n,int x)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return 1;
        }
        int curr= pow(num,x);
        if(curr>n)
        {
            return 0;
        }
        //go to next number..
        int take= rec(num+1,n-curr,x);
        int skip= rec(num+1,n,x);
        return skip+take;
    }
    int numberOfWays(int n, int x) 
    {
        return rec(1,n,x);
    }
*/
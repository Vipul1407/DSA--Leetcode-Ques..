class Solution {
public:
    int tda(int n, vector<int>&dp)
    {
        if(n==0 || n==1)
        {
            return n;
        }
        int ans=0;
        ans+= tda(n-1,dp)+tda(n-2,dp);
        return dp[n]= ans;
    }
    int fib(int n) 
    {
        vector<int>dp(n+1,-1);
        return tda(n,dp);
    }
};
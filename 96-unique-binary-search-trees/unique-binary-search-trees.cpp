class Solution {
public:
    int tda(int n,vector<int>&dp)
    {
        if(n<=1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans=0;
        for(int i=0;i<=n-1;i++)
        {
            ans+= tda(i,dp)*tda(n-i-1,dp);
        }
        return dp[n]= ans;
    }
    int numTrees(int n) 
    {
        vector<int>dp(n+1,-1);
        return tda(n,dp);
    }
};
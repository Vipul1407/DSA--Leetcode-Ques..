class Solution {
public:
    //METHOD-2
    //TDA APPROACH..
    int tda(int i,int j,vector<int>& val, vector<vector<int>>&dp)
    {
        if(i+1==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans= INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            ans= min(ans,val[i]*val[j]*val[k] + tda(i,k,val,dp) + tda(k,j,val,dp));
        }
        return dp[i][j]= ans;
    }
    int minScoreTriangulation(vector<int>& val) 
    {
        int n= val.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return tda(0,n-1,val,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE APPROACH..
    int rec(int i,int j,vector<int>& val)
    {
        if(i+1==j)
        {
            return 0;
        }
        int ans= INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            ans= min(ans,val[i]*val[j]*val[k] + rec(i,k,val) + rec(k,j,val));
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& val) 
    {
        int n= val.size();
        return rec(0,n-1,val);
    }
*/
class Solution {
public:
    //METHOD-2
    //TDA..
    int tda(int i,int j,int &m, int &n, vector<vector<int>>&dp)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int left= tda(i,j+1,m,n,dp);
        int right= tda(i+1,j,m,n,dp);
        return dp[i][j]= left+right;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return tda(0,0,m,n,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,int j,int &m, int &n)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        int left= rec(i,j+1,m,n);
        int right= rec(i+1,j,m,n);
        return left+right;
    }
    int uniquePaths(int m, int n) 
    {
        return rec(0,0,m,n);
    }
*/
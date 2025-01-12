class Solution {
public:
    int solve(int i,int j,int rob,vector<vector<int>>& coins,vector<vector<vector<int>>>&dp)
    {
        int m= coins.size();
        int n= coins[0].size();
        if(i>=m || j>=n)
        {
            return INT_MIN;
        }
        if(i==m-1 && j==n-1)
        {
            if(coins[i][j]<0 && rob>0)
            {
                return 0;
            }
            return coins[i][j];
        }
        if(dp[i][j][rob]!=-1)
        {
            return dp[i][j][rob];
        }
        int down= solve(i+1,j,rob,coins,dp);
        int right= solve(i,j+1,rob,coins,dp);
        int profit= coins[i][j]+ max(down,right);

        if(coins[i][j]<0 && rob>0)
        {
            int d2= solve(i+1,j,rob-1,coins,dp);
            int r2= solve(i,j+1,rob-1,coins,dp);
            int b2= max(d2,r2);
            profit= max(profit,b2);
        }
        return dp[i][j][rob]= profit;
    }
    int maximumAmount(vector<vector<int>>& coins) 
    {
        int m= coins.size();
        int n= coins[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(3,-1)));
        return solve(0,0,2,coins,dp);
    }
};
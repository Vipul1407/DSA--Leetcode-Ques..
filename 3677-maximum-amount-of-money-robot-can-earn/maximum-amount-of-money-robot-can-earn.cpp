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
            if(coins[i][j]>=0)
            {
                return coins[i][j];
            }
            else
            {
                return rob>0? 0:coins[i][j];
            }
        }
        if(dp[i][j][rob]!=-1)
        {
            return dp[i][j][rob];
        }
        int c= coins[i][j];
        int down= solve(i+1,j,rob,coins,dp);
        int right= solve(i,j+1,rob,coins,dp);
        int best= max(down,right);
        if(c>=0)
        {
            return dp[i][j][rob]= c+best;
        }
        else
        {
            if(rob>0)
            {
                int d2= solve(i+1,j,rob-1,coins,dp);
                int r2= solve(i,j+1,rob-1,coins,dp);
                int b2= max(d2,r2);
                return dp[i][j][rob]= max(c+best,b2);
            }
            else
            {
                return dp[i][j][rob]= c+best;
            }
        }
    }
    int maximumAmount(vector<vector<int>>& coins) 
    {
        int m= coins.size();
        int n= coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,-1)));
        return solve(0,0,2,coins,dp);
    }
};
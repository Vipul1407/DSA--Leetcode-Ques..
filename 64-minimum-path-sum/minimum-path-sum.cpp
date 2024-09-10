class Solution {
public:

    int tda(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        int n= grid[0].size();
        int m= grid.size();
        if(i==m-1 && j==n-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //can either go right or down..
        //if in last row then can go only right
        if(i==m-1)
        {
            return dp[i][j]= grid[i][j] + tda(i,j+1,grid,dp);
        }
        //if in last col then can go only down
        if(j==n-1)
        {
            return dp[i][j]= grid[i][j] + tda(i+1,j,grid,dp);
        }
        else
        {
            return dp[i][j]= grid[i][j] + min(tda(i+1,j,grid,dp),tda(i,j+1,grid,dp));
        }
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n= grid[0].size();
        int m= grid.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return tda(0,0,grid,dp);
    }
};
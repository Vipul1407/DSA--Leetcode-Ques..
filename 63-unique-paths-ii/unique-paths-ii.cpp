class Solution {
public:
    //METHOD-1
    //TDA..
    int tda(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        int m= grid.size();
        int n= grid[0].size();
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(i>=m || j>=n || grid[i][j]==1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right= tda(i,j+1,grid,dp);
        int left= tda(i+1,j,grid,dp);
        return dp[i][j]= right+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        //not possible to reach..
        if(grid[m-1][n-1]==1)
        {
            return 0;
        }
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return tda(0,0,grid,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,int j,vector<vector<int>>& grid)
    {
        int m= grid.size();
        int n= grid[0].size();
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(i>=m || j>=n || grid[i][j]==1)
        {
            return 0;
        }
        int right= rec(i,j+1,grid);
        int left= rec(i+1,j,grid);
        return right+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        return rec(0,0,grid);
    }
*/
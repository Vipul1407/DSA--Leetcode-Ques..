class Solution {
public:
    //METHOD-2
    //TDA..
    int rec(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&dp)
    {
        int m= grid.size();
        int n= grid[0].size();
        if(i==m-1 && j==n-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans= INT_MAX;
        //last row=> can go only right.. j+1
        if(i==m-1)
        {
            ans= min(ans, rec(i,j+1,grid,dp));
        }
        //last col=> can gol only down.. i+1
        else if(j==n-1)
        {
            ans= min(ans, rec(i+1,j,grid,dp));
        }
        else
        {
            //take min of right or down..
            ans= min(ans,min(rec(i+1,j,grid,dp),rec(i,j+1,grid,dp)));
        }
        return dp[i][j]= grid[i][j]+ans;//addign curr grid element to ans..
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return rec(0,0,grid,dp);
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
            return grid[i][j];
        }
        int ans= INT_MAX;
        //last row=> can go only right.. j+1
        if(i==m-1)
        {
            ans= min(ans, rec(i,j+1,grid));
        }
        //last col=> can gol only down.. i+1
        else if(j==n-1)
        {
            ans= min(ans, rec(i+1,j,grid));
        }
        else
        {
            ans= min(ans,min(rec(i+1,j,grid),rec(i,j+1,grid)));
        }
        return grid[i][j]+ans;
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        return rec(0,0,grid);
    }
*/
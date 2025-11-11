class Solution {
public:
    //METHOD-4
    //SPACE OPTIMIZED..
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);

        curr[n-1]= grid[m-1][n-1];
    
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int ans= INT_MAX;
                //last row=> can go only right.. j+1
                if(i==m-1)
                {
                    ans= min(ans, curr[j+1]);
                    //can simply take this..
                    //ans= curr[j+1]);
                }
                //last col=> can gol only down.. i+1
                else if(j==n-1)
                {
                    ans= min(ans, next[j]);
                    //can simply take this..
                    //ans= next[j];
                }
                else
                {
                    //take min of right or down..
                    ans= min(ans,min(next[j],curr[j+1]));
                }
                curr[j]= grid[i][j]+ans;//addign curr grid element to ans..;
            }
            next= curr;
        }
        return next[0];
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
            //can simply take..
            //ans= rec(i,j+1,grid,dp);
        }
        //last col=> can gol only down.. i+1
        else if(j==n-1)
        {
            ans= min(ans, rec(i+1,j,grid,dp));
            //can simply take..
            //ans= rec(i+1,j,grid,dp);
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

    //METHOD-3
    //BUA..
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        dp[m-1][n-1]= grid[m-1][n-1];
    
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int ans= INT_MAX;
                //last row=> can go only right.. j+1
                if(i==m-1)
                {
                    ans= min(ans, dp[i][j+1]);
                    //can simply take this..
                    //ans= dp[i][j+1]);
                }
                //last col=> can gol only down.. i+1
                else if(j==n-1)
                {
                    ans= min(ans, dp[i+1][j]);
                    //can simply take this..
                    //ans= dp[i+1][j];
                }
                else
                {
                    //take min of right or down..
                    ans= min(ans,min(dp[i+1][j],dp[i][j+1]));
                }
                dp[i][j]= grid[i][j]+ans;//addign curr grid element to ans..;
            }
        }
        return dp[0][0];
    }
*/
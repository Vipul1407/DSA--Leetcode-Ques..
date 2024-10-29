class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid, int ele, vector<vector<int>>&dp)
    {
        int m= grid.size();//row
        int n=grid[0].size();//col
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return 0;
        }
        if(ele>=grid[i][j])
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int prev= 1+solve(i-1,j+1,grid,grid[i][j],dp);
        int curr= 1+solve(i,j+1,grid,grid[i][j],dp);
        int next= 1+solve(i+1,j+1,grid,grid[i][j],dp);
        return dp[i][j]= max(prev,max(curr,next));
    }
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m= grid.size();//row
        int n=grid[0].size();//col
        int ele=INT_MIN;
        int ans=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        //can start from any cell in first col(i,0)
        for(int i=0;i<m;i++)
        {
            ans= max(ans,solve(i,0,grid,ele,dp));
        }
        return ans-1;
    }
};
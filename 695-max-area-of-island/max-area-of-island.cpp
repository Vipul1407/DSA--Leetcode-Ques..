class Solution {
public:
    
    vector<int>dx= {-1,0,1,0};
    vector<int>dy= {0,1,0,-1};
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis)
    {
        int m= grid.size();
        int n= grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n)
        {
            return 0;
        }
        if(vis[i][j]==1 || grid[i][j]==0)
        {
            return 0;
        }
        int sum= grid[i][j];
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nx= i+dx[k];
            int ny= j+dy[k];
            sum+= dfs(nx,ny,grid,vis);
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    ans= max(ans,dfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};
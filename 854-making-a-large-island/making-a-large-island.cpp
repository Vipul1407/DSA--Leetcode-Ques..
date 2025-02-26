class Solution {
public:
    // METHOD-2
    // OPTIMIZED USING UNORDERED MAP..
    vector<int>dx= {-1,0,1,0};
    vector<int>dy= {0,1,0,-1};
    int dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid, int &id)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        {
            return 0;
        }
        if(vis[i][j]==1 || grid[i][j]==0)
        {
            return 0;
        }
        vis[i][j]=1;
        grid[i][j]= id;
        int size=1;
        for(int k=0;k<4;k++)
        {
            int x= i+dx[k];
            int y= j+dy[k];
            size+= dfs(x,y,vis,grid,id);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n= grid.size();
        int ans=0;
        unordered_map<int,int>mp;
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        int id=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int size=0;
                    size+= dfs(i,j,vis,grid,id);
                    mp[id]= size;
                    id++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int>st;
                    if(i-1>=0)
                    {
                        st.insert(grid[i-1][j]);
                    }
                    if(j-1>=0)
                    {
                        st.insert(grid[i][j-1]);
                    }
                    if(i+1<n)
                    {
                        st.insert(grid[i+1][j]);
                    }
                    if(j+1<n)
                    {
                        st.insert(grid[i][j+1]);
                    }
                    int size=1;
                    for(auto i:st)
                    {
                        size+= mp[i];
                    }
                    ans= max(ans,size);
                }
            }
        }
        return (ans==0)? n*n: ans;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
int dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
    {
        return 0;
    }
    if (vis[i][j] == 1 || grid[i][j] == 0)
    {
        return 0;
    }
    vis[i][j] = 1;
    int size = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        size += dfs(x, y, vis, grid);
    }
    return size;
}
int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int ans = 0;
    // vector<vector<int>>vis(n,vector<int>(n,0));
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(grid[i][j]==1 && !vis[i][j])
    //         {
    //             vector<vector<int>>vis(n,vector<int>(n,0));
    //             ans=max(ans,dfs(i,j,vis,grid));
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                vector<vector<int>> vis(n, vector<int>(n, 0));
                grid[i][j] = 1;
                ans = max(ans, dfs(i, j, vis, grid));
                grid[i][j] = 0;
            }
        }
    }
    return (ans == 0) ? n * n : ans;
}
*/
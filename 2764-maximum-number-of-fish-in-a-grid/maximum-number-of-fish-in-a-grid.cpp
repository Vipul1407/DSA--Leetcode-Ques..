class Solution {
public:
    //METHOD-2
    //BFS..
    vector<int>dx= {0,0,1,-1};
    vector<int>dy= {1,-1,0,0};
    int bfs(vector<vector<int>>& grid, int i,int j,vector<vector<int>>&vis)
    {
        int m= grid.size();
        int n= grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int sum=grid[i][j];
        while(q.size())
        {
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx= x+dx[k];
                int ny= y+dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n)
                {   
                    if(!vis[nx][ny] && grid[nx][ny]>=1)
                    {
                        sum+= grid[nx][ny];
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]>=1)
                {
                    ans= max(ans,bfs(grid,i,j,vis));
                }
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    //DFS..
    vector<int>dx= {0,0,1,-1};
    vector<int>dy= {1,-1,0,0};
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&vis)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
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
            int x= i+dx[k];
            int y= j+dy[k];
            sum+= dfs(grid,x,y,vis);
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]>=1)
                {
                    ans= max(ans,dfs(grid,i,j,vis));
                }
            }
        }
        return ans;
    }
*/
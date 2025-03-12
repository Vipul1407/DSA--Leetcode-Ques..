class Solution {
public:
    int findupar(int node, vector<int>&parent)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]= findupar(parent[node],parent);
    }
    void unionbysize(int u,int v, vector<int>&size, vector<int>&parent)
    {
        int up_u= findupar(u,parent);
        int up_v= findupar(v,parent);
        if(up_u==up_v)
        {
            return;
        }
        //small wla bde wle ke sath merge hoga,,
        if(size[up_u]>size[up_v])
        {
            parent[up_v]= up_u;
            size[up_u]+= size[up_v];
        }
        else 
        {
            parent[up_u]= up_v;
            size[up_v]+= size[up_u];
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        vector<int>parent(m*n);
        vector<int>size(m*n,0);
        for(int i=0;i<m*n;i++)
        {
            parent[i]= i;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int idx= i*n+j;
                    size[idx]= 1;
                }
            }
        }
        vector<int>dx= {-1,0,1,0};
        vector<int>dy= {0,1,0,-1};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int idx= i*n+j;
                    for(int k=0;k<4;k++)
                    {
                        int newi= i+dx[k];
                        int newj= j+dy[k];
                        if(newi>=0 && newj>=0 && newi<m && newj<n && grid[newi][newj]==1)
                        {
                            int newidx= newi*n+newj;
                            if(findupar(idx,parent)!= findupar(newidx,parent))
                            {
                                unionbysize(idx,newidx,size,parent);
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<m*n;i++)
        {
            ans= max(ans,size[i]);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //DFS..
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

    //METHOD-2
    //BFS..
    vector<int>dx= {-1,0,1,0};
    vector<int>dy= {0,1,0,-1};
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis)
    {
        int m= grid.size();
        int n= grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int sum= grid[i][j];
        while(q.size())
        {
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx= x+ dx[k];
                int ny= y+ dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n)
                {
                    if(!vis[nx][ny] && grid[nx][ny]==1)
                    {
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                        sum+= grid[nx][ny];
                    }
                }
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    ans= max(ans,bfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
*/
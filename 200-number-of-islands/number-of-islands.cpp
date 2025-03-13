class Solution {
public:
    //METHOD-3
    //DISJOINT SET (DSU..)
    int findupar(int node, vector<int> &parent)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findupar(parent[node], parent);
    }
    void unionbysize(int u, int v, vector<int> &size, vector<int> &parent)
    {
        int up_u = findupar(u, parent);
        int up_v = findupar(v, parent);
        if (up_u == up_v)
        {
            return;
        }
        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, 1, 0, -1};
        vector<int>size(m*n,0);
        vector<int>parent(m*n);
        for(int i=0;i<m*n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    int idx= i*n+j;
                    size[idx]= 1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    int idx= i*n+j;
                    for(int k=0;k<4;k++)
                    {
                        int newi= i+dx[k];
                        int newj= j+dy[k];
                        if (newi >= 0 && newj >= 0 && newi < m && newj < n && grid[newi][newj]=='1')
                        {
                            int newidx = newi * n + newj;
                            if (findupar(idx, parent) != findupar(newidx, parent))
                            {
                                unionbysize(idx, newidx, size, parent);
                            }
                        }
                    }
                }
            }
        }
        unordered_set<int>st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    int idx= i*n+j;
                    int par= findupar(idx,parent);
                    st.insert(par);
                }
            }
        }
        return st.size();
    }
};
/*
// METHOD-1
// DFS..
void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = row + dx[i];
        int ny = col + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] == '1')
        {
            dfs(nx, ny, grid, vis);
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                c++;
                dfs(i, j, grid, vis);
            }
        }
    }
    return c;
}

//METHOD-2
    //BFS..
    vector<int>dx = {-1, 0, 1, 0};
    vector<int>dy = {0, 1, 0, -1};
    void bfs(int i,int j, vector<vector<int>>&vis, vector<vector<char>>& grid)
    {
        int m= grid.size();
        int n= grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(q.size())
        {
            auto x= q.front().first;
            auto y= q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx>= 0 && ny>= 0 && nx<m && ny<n && !vis[nx][ny] && grid[nx][ny] == '1')
                {
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
*/
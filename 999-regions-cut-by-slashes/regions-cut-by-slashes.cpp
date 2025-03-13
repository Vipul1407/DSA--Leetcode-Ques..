class Solution {
public:
    // METHOD-3
    // USING DISJOINT SET (DSU..)
    vector<int>dx= {-1, 0, 1, 0};
    vector<int>dy= {0, 1, 0, -1};
    int findupar(int node, vector<int> &parent)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findupar(parent[node], parent);
    }
    void unionbyrank(int u, int v, vector<int> &rank, vector<int> &parent)
    {
        int up_u = findupar(u, parent);
        int up_v = findupar(v, parent);
        if (up_u == up_v)
        {
            return;
        }
        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if(rank[up_v] < rank[up_u])
        {
            parent[up_v] = up_u;
        }
        else
        {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
    int regionsBySlashes(vector<string>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int newn= n*3;
        int newm= m*3;
        vector<vector<int>>mat(newm,vector<int>(newn,0));
        vector<int> rank(newm * newn , 0);
        vector<int> parent(newm * newn);
        for (int i = 0; i < newm*newn; i++)
        {
            parent[i] = i;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    mat[i*3+2][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3][j*3]=1;
                }
            }
        }

        for (int i = 0; i < newm; i++)
        {
            for (int j = 0; j < newn; j++)
            {
                //call dfs for 0 not 1...
                int idx= i*newn+j;
                if(mat[i][j] == 0)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int newi = i + dx[k];
                        int newj = j + dy[k];
                        if (newi >= 0 && newj >= 0 && newi < newm && newj < newn && mat[newi][newj]==0)
                        {
                            int newidx = newi * newn + newj;
                            if (findupar(idx, parent) != findupar(newidx, parent))
                            {
                                unionbyrank(idx, newidx, rank, parent);
                            }
                        }
                    }
                }
            }
        }
        unordered_set<int>st;
        for(int i=0;i<newm;i++)
        {
            for(int j=0;j<newn;j++)
            {
                int idx= i*newn+j;
                if(mat[i][j]==0)
                {
                    st.insert(findupar(idx,parent));
                }
            }
        }
        return st.size();
    }
};
/*
//METHOD-1
    //SAME AS NO. OF ISLAND QUES..
    //USING DFS..
    vector<int>dx= {-1, 0, 1, 0};
    vector<int>dy= {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        mat[row][col] = -1;
        for (int i = 0; i < 4; i++)
        {
            int nx = row + dx[i];
            int ny = col + dy[i];
            //we have to traverse all 0 not 1...
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&  mat[nx][ny] == 0)
            {
                dfs(nx, ny, mat);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>mat(m*3,vector<int>(n*3,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    mat[i*3+2][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3][j*3]=1;
                }
            }
        }

        int cnt=0;
        for (int i = 0; i < m*3; i++)
        {
            for (int j = 0; j < n*3; j++)
            {
                //call dfs for 0 not 1...
                if(mat[i][j] == 0)
                {
                    cnt++;
                    dfs(i, j, mat);
                }
            }
        }
        return cnt;
    }

// METHOD-2
    // SAME AS NO. OF ISLAND QUES..
    // USING BFS..
    vector<int>dx= {-1, 0, 1, 0};
    vector<int>dy= {0, 1, 0, -1};
    void bfs(int row, int col, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        mat[row][col] = -1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(q.size())
        {
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                //we have to traverse all 0 not 1...
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&  mat[nx][ny] == 0)
                {
                    mat[nx][ny]=-1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>>mat(m*3,vector<int>(n*3,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    mat[i*3+2][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3][j*3]=1;
                }
            }
        }

        int cnt=0;
        for (int i = 0; i < m*3; i++)
        {
            for (int j = 0; j < n*3; j++)
            {
                //call dfs for 0 not 1...
                if(mat[i][j] == 0)
                {
                    cnt++;
                    bfs(i, j, mat);
                }
            }
        }
        return cnt;
    }
*/
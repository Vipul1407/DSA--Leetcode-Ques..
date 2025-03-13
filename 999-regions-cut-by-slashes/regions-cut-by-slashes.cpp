class Solution {
public:
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
*/
class Solution {
public:

    //TC= O((N*M)^2)
    int n,m;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&vis)
    {
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]==0)
        {
            return;
        }
        vis[i][j]= true;
        dfs(grid,i+1,j,vis);
        dfs(grid,i-1,j,vis);
        dfs(grid,i,j+1,vis);
        dfs(grid,i,j-1,vis);
    }
    int island(vector<vector<int>>& grid)
    {
        int cnt=0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    dfs(grid,i,j,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) 
    {
        //reinitialize it as we have make it global above
        m= grid.size();
        n= grid[0].size();

        int iland= island(grid);
        if(iland>1 || iland==0)
        {
            return 0;
        }
        else
        {
            //we have only 1 iland and now we have to make it disconnected by changing 1grid each time
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1)
                    {
                        grid[i][j]=0;//convert to water
                        //now again calculate number of iland
                        iland= island(grid);
                        if(iland>1 || iland==0)
                        {
                            return 1;
                        }
                        //backtracking..
                        grid[i][j]=1;
                    }
                }
            }
        }
        return 2;
    }
};
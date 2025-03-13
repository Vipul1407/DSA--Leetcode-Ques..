class Solution {
public:
    //METHOD-1
    //DFS..
    vector<int>dx= {-1,0,1,0};
    vector<int>dy= {0,1,0,-1};
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        int m= grid.size();
        int n= grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n ||grid[i][j]==0)
        {
            return 1;
        }
        if(grid[i][j]==-1)
        {
            return 0;
        }
        grid[i][j]=-1;//mark visted..
        int peri=0;
        for(int k=0;k<4;k++)
        {
            int nx= i+dx[k];
            int ny= j+dy[k];
            peri+= dfs(nx,ny,grid);
        }
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int peri=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    peri+= dfs(i,j,grid);
                }
            }
        }
        return peri;
    }
};
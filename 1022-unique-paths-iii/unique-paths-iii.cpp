class Solution {
public:

    vector<int>dx={0,-1,1,0};
    vector<int>dy={-1,0,0,1};
    int rec(int i, int j, int cnt, vector<vector<int>>& grid)
    {
        int m= grid.size();
        int n= grid[0].size();
        if (i >= m || j >= n || i<0 || j<0 || grid[i][j]==-1)
        {
            return 0;
        }
        if(grid[i][j]==2)
        {
            return cnt==0;
        }

        grid[i][j]=-1;//mark as visted..

        int ways=0;
        for(int k=0;k<4;k++)
        {
            int newx= i+dx[k];
            int newy= j+dy[k];
            if(newx<0 || newy<0 || newx>=m || newy>=n || grid[newx][newy]==-1)
            {
                continue;
            }
            ways+= rec(newx,newy,cnt-1,grid);
        }
        //backtracking..
        grid[i][j]= 0;
        return ways;
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        pair<int,int>start;

        int cnt=1;//starting point will also be a non obstacle..

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    cnt++;
                }
                else if(grid[i][j]==1)
                {
                    start= {i,j};
                }
            }
        }
    
        return rec(start.first,start.second,cnt,grid);
    }
};
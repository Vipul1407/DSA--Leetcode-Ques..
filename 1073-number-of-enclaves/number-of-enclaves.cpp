class Solution {
public:
    //Multi-Level BFS...
    //Push all boundary 1's in queue then find cnt of connected 1's with it
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        queue<pair<int,int>>q;

        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        //pushing multiple sources to call for bfs..
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                grid[i][0]=-1;
            }
            if(grid[i][n-1]==1)
            {
                q.push({i,n-1});
                grid[i][n-1]=-1;
            }
        }
        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==1)
            {
                q.push({0,j});
                grid[0][j]=-1;
            }
            if(grid[m-1][j]==1)
            {
                q.push({m-1,j});
                grid[m-1][j]=-1;
            }
        }


        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        //applying bfs to find boundary connected 1's
        int ones= 0;
        while(!q.empty())
        {
            int x= q.front().first;
            int y= q.front().second;
            q.pop();

            grid[x][y]=-1;
            ones++;

            for(int k=0;k<4;k++)
            {
                int nx= x+dx[k];
                int ny= y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1)
                {
                    q.push({nx,ny});
                    grid[nx][ny]=-1;//to mark it as visited..
                }
            }
        }
        return cnt-ones;
    }
};
class Solution {
public:
    //METHOD-2
    //BETTER APPROACH
    //TC= O(M*N)  SC=O(M+N)
    int countServers(vector<vector<int>>& grid) 
    {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    if(row[i]>=2 || col[j]>=2)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
/*
// BRUTE FORCE
// BEATS 100%
// TC= O(M*N)*(M+N)
// Checking each cell and then checking if it has any other server in same row or col..
int countServers(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                bool flag = false;
                // check same row...
                for (int col = 0; col < n; col++)
                {
                    if (grid[i][col] == 1 && col != j)
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    // check same col..
                    for (int row = 0; row < m; row++)
                    {
                        if (grid[row][j] == 1 && row != i)
                        {
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag == true)
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}
*/
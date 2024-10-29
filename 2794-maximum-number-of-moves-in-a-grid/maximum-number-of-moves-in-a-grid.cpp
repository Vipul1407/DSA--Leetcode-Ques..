class Solution {
public:
    //METHOD-3
    //BUA
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m= grid.size();//row
        int n=grid[0].size();//col
        vector<vector<int>>dp(m,vector<int>(n,0));
        //start from col j=n-2 in Bottom-up manner..
        for(int j=n-2;j>=0;j--)
        {
            //then go for row i=0 in Top-down manner..
            for(int i=0;i<m;i++)
            {
                //prev..
                if(i-1>=0 &&j+1<n && grid[i][j]<grid[i-1][j+1])
                {
                    dp[i][j]= max(dp[i][j], 1+dp[i-1][j+1]);
                }
                //curr..
                if(j+1<n && grid[i][j]<grid[i][j+1])
                {
                    dp[i][j]= max(dp[i][j], 1+dp[i][j+1]);
                }     
                //next..
                if(i+1<m &&j+1<n && grid[i][j]<grid[i+1][j+1])
                {
                    dp[i][j]= max(dp[i][j], 1+dp[i+1][j+1]);
                }
            }
        }
        int ans=0;
        //can start from any cell in first col(i,0) hence will take max form this only
        for(int i=0;i<m;i++)
        {
            ans=max(ans,dp[i][0]);
        }
        return ans;
    }
};


// /*
// // METHOD-1
// // RECURSIVE
// int solve(int i, int j, vector<vector<int>> &grid, int ele)
// {
//     int m = grid.size();    // row
//     int n = grid[0].size(); // col
//     if (i < 0 || i >= m || j < 0 || j >= n)
//     {
//         return 0;
//     }
//     if (ele >= grid[i][j])
//     {
//         return 0;
//     }
//     int prev = 1 + solve(i - 1, j + 1, grid, grid[i][j]);
//     int curr = 1 + solve(i, j + 1, grid, grid[i][j]);
//     int next = 1 + solve(i + 1, j + 1, grid, grid[i][j]);
//     return max(prev, max(curr, next));
// }
// int maxMoves(vector<vector<int>> &grid)
// {
//     int m = grid.size();    // row
//     int n = grid[0].size(); // col
//     int ele = INT_MIN;
//     int ans = 0;
//     // can start from any cell in first col(i,0)
//     for (int i = 0; i < m; i++)
//     {
//         ans = max(ans, solve(i, 0, grid, ele));
//     }
//     return ans - 1;
// }


// // METHOD-2
// // TDA
// // BEATS 78%
// int solve(int i, int j, vector<vector<int>> &grid, int ele, vector<vector<int>> &dp)
// {
//     int m = grid.size();    // row
//     int n = grid[0].size(); // col
//     if (i < 0 || i >= m || j < 0 || j >= n)
//     {
//         return 0;
//     }
//     if (ele >= grid[i][j])
//     {
//         return 0;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int prev = 1 + solve(i - 1, j + 1, grid, grid[i][j], dp);
//     int curr = 1 + solve(i, j + 1, grid, grid[i][j], dp);
//     int next = 1 + solve(i + 1, j + 1, grid, grid[i][j], dp);
//     return dp[i][j] = max(prev, max(curr, next));
// }
// */

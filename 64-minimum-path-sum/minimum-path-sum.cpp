class Solution 
{
public:

    int minPathSum(vector<vector<int>>& grid) 
    {
        int n= grid[0].size();
        int m= grid.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1)
                {
                    dp[i][j]= grid[i][j]+ dp[i][j+1];
                }
                else if(j==n-1)
                {
                    dp[i][j]= grid[i][j]+ dp[i+1][j];
                }
                else
                {
                    dp[i][j]= grid[i][j]+ min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    
};


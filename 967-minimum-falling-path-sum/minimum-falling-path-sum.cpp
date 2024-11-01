class Solution {
public:
 
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,1e9));

        // if(i>=m)
        // {
        //     return 0;
        // }
        for(int j=0;j<n;j++)
        {
            dp[m-1][j]= mat[m-1][j];
        }
        // if(j>=n || j<0)
        // {
        //     return 1e5;
        // }
        //Already handled by initializing dp table by 1e5

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(j-1>=0 && i+1<m)
                {
                    dp[i][j]= min(dp[i][j], mat[i][j]+ dp[i+1][j-1]);
                }
                if(i+1<m)
                {
                    dp[i][j]= min(dp[i][j], mat[i][j]+ dp[i+1][j]);
                }
                if(i+1<m && j+1<n)
                {
                    dp[i][j]= min(dp[i][j], mat[i][j]+ dp[i+1][j+1]);
                }
            }
        }
        int ans=INT_MAX;
        //starting form any cell in 1st row..
        for(int j=0;j<n;j++)
        {
            ans= min(ans, dp[0][j]);
        }
        return ans;
    }
};
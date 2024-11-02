class Solution {
public:
 
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        vector<int>next(n,1e5);

        // if(i>=m)
        // {
        //     return 0;
        // }
        for(int j=0;j<n;j++)
        {
            next[j]= mat[m-1][j];
        }
        // if(j>=n || j<0)
        // {
        //     return 1e5;
        // }
        //Already handled by initializing dp table by 1e5

        //starting last second row as we have alreay used i=m-1 row to fill dp in base case..
        for(int i=m-2;i>=0;i--)
        {
            vector<int>curr(n,1e5);
            for(int j=n-1;j>=0;j--)
            {
                if(j-1>=0 && i+1<m)
                {
                    curr[j]= min(curr[j], mat[i][j]+ next[j-1]);
                }
                if(i+1<m)
                {
                    curr[j]= min(curr[j], mat[i][j]+ next[j]);
                }
                if(i+1<m && j+1<n)
                {
                    curr[j]= min(curr[j], mat[i][j]+ next[j+1]);
                }
            }
            next=curr;
        }
        int ans=INT_MAX;
        //starting form any cell in 1st row..
        for(int j=0;j<n;j++)
        {
            ans= min(ans, next[j]);
        }
        return ans;
    }
};

/*
// TDA APPROACH
// TLE.. \U0001f43b\U0001f43b\U0001f43b\U0001f43b
int ans = INT_MAX;
int rec(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    int m = mat.size();
    int n = mat[0].size();
    // becoz we are traversing row-wise..
    if (i >= m)
    {
        return 0;
    }
    if (j >= n || j < 0)
    {
        return 1e5;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int left = mat[i][j] + rec(i + 1, j - 1, mat, dp);
    int down = mat[i][j] + rec(i + 1, j, mat, dp);
    int right = mat[i][j] + rec(i + 1, j + 1, mat, dp);
    return dp[i][j] = min(left, min(down, right));
}
int minFallingPathSum(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // starting form any cell in 1st row..
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, rec(0, j, mat, dp));
    }
    return ans;
}

// BUA APPROACH
// BEATS 32%
int minFallingPathSum(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 1e9));

    // if(i>=m)
    // {
    //     return 0;
    // }
    for (int j = 0; j < n; j++)
    {
        dp[m - 1][j] = mat[m - 1][j];
    }
    // if(j>=n || j<0)
    // {
    //     return 1e5;
    // }
    // Already handled by initializing dp table by 1e5

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (j - 1 >= 0 && i + 1 < m)
            {
                dp[i][j] = min(dp[i][j], mat[i][j] + dp[i + 1][j - 1]);
            }
            if (i + 1 < m)
            {
                dp[i][j] = min(dp[i][j], mat[i][j] + dp[i + 1][j]);
            }
            if (i + 1 < m && j + 1 < n)
            {
                dp[i][j] = min(dp[i][j], mat[i][j] + dp[i + 1][j + 1]);
            }
        }
    }
    int ans = INT_MAX;
    // starting form any cell in 1st row..
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, dp[0][j]);
    }
    return ans;
}

*/
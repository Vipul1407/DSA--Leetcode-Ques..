class Solution {
public:
    //METHOD-4
    //Space Optimized APPROACH 2..
    int countSquares(vector<vector<int>>& mat) 
    {
        int cnt=0;
        int m= mat.size();
        int n= mat[0].size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(mat[i][j]==1)
                {
                    curr[j]= 1+min({next[j],curr[j+1],next[j+1]});
                }   
                else
                {
                    curr[j]=0;
                }
                cnt+= curr[j];
            }
            next=curr;
        }
        return cnt;
    }
};
/*
    // METHOD-1
// RECURSIVE
int rec(int i, int j, vector<vector<int>> &mat)
{
    if (i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0)
    {
        return 0;
    }
    int right = rec(i, j + 1, mat);
    int bottom = rec(i + 1, j, mat);
    int dia = rec(i + 1, j + 1, mat);
    return 1 + min(right, min(bottom, dia)); // adding 1 as square of size 1 is also a square matrix..
}
int countSquares(vector<vector<int>> &mat)
{
    int m = mat.size();    // row
    int n = mat[0].size(); // col
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                ans += rec(i, j, mat);
            }
        }
    }
    return ans;
}

// METHOD-2
// TDA
// BEATS 9%
int rec(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = rec(i, j + 1, mat, dp);
    int bottom = rec(i + 1, j, mat, dp);
    int dia = rec(i + 1, j + 1, mat, dp);
    return dp[i][j] = 1 + min(right, min(bottom, dia)); // adding 1 as square of size 1 is also a square matrix..
}
int countSquares(vector<vector<int>> &mat)
{
    int m = mat.size();    // row
    int n = mat[0].size(); // col
    int ans = 0;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                ans += rec(i, j, mat, dp);
            }
        }
    }
    return ans;
}

// METHOD-2 PART2 TDA ANOTHER WAY....
// Striver Way..
int countSquares(vector<vector<int>> &mat)
{
    int cnt = 0;
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
    {
        dp[0][j] = mat[0][j];
        cnt += mat[0][j];
    }
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = mat[i][0];
        cnt += mat[i][0];
    }
    cnt -= mat[0][0];

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
            cnt += dp[i][j];
        }
    }
    return cnt;
}

// METHOD-3
// BUA
// BEATS 52%
int countSquares(vector<vector<int>> &mat)
{
    int m = mat.size();    // row
    int n = mat[0].size(); // col
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (mat[i][j] == 1)
            {
                int right = dp[i][j + 1];
                int bottom = dp[i + 1][j];
                int dia = dp[i + 1][j + 1];
                dp[i][j] = 1 + min(right, min(bottom, dia)); // adding 1 as square of size 1 is also a square matrix..
                ans += dp[i][j];
            }
        }
    }
    return ans;
}

// METHOD-4
// SPACE OPTIMIZED
int countSquares(vector<vector<int>> &mat)
{
    int m = mat.size();    // row
    int n = mat[0].size(); // col

    // both will have size of n+1
    vector<int> next(n + 1, 0);
    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        vector<int> curr(n + 1, 0); // reinitailzied after each iteration for each row...
        for (int j = n - 1; j >= 0; j--)
        {
            if (mat[i][j] == 1)
            {
                int right = curr[j + 1];
                int bottom = next[j];
                int dia = next[j + 1];
                curr[j] = 1 + min(right, min(bottom, dia)); // adding 1 as square of size 1 is also a square matrix..
                ans += curr[j];
            }
        }
        next = curr;
    }
    return ans;
}
*/
class Solution {
public:
    //METHOD-3
    //BUA
    int minimumTotal(vector<vector<int>>& tri) 
    {
        int n= tri.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        //base case..
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]= tri[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                //down,diagonal
                dp[i][j]= tri[i][j]+ min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
/*
// METHOD-1
// RECURSIVE APPROACH..
int rec(int i, int j, vector<vector<int>> &tri)
{
    if (i == tri.size() - 1)
    {
        return tri[i][j];
    }
    // No need to explicitly handle this as j can go from 0 to i as only max i+1 cols in a row
    //  if(j>=tri[i].size())
    //  {
    //      return 0;
    //  }
    return tri[i][j] + min(rec(i + 1, j, tri), rec(i + 1, j + 1, tri));
}
int minimumTotal(vector<vector<int>> &tri)
{
    return rec(0, 0, tri);
}

// METHOD-2
// TDA APPROACH
int tda(int i, int j, vector<vector<int>> &tri, vector<vector<int>> &dp)
{
    // last row then return the value..
    // no need to handle for j as j max go to i+1 i.e 0<=j<=i
    if (i == tri.size() - 1)
    {
        return tri[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // down,diagonal
    return dp[i][j] = tri[i][j] + min(tda(i + 1, j, tri, dp), tda(i + 1, j + 1, tri, dp));
}
int minimumTotal(vector<vector<int>> &tri)
{
    int n = tri.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return tda(0, 0, tri, dp);
}
*/
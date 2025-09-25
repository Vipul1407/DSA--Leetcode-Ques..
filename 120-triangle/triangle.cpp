class Solution {
public:
    //METHOD-3
    //BUA
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n= triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //base case..
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]= triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                dp[i][j]= triangle[i][j]+ min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
/*
    //METHOD-1
    //RECURSIVE APPROACH..
    int solve(int i,int j,vector<vector<int>>& triangle)
    {
        if(i== triangle.size()-1)
        {
            return triangle[i][j];
        }
        return triangle[i][j]+ min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        return solve(0,0,triangle);
    }

    //METHOD-2
    //TDA
    //Gving TLE...
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp)
    {
        if(i== triangle.size()-1)
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]= triangle[i][j]+ min(solve(i+1,j,triangle,dp),solve(i+1,j+1,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n= triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp);
    }
*/
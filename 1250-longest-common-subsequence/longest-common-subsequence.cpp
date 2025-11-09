class Solution {
public:
    //METHOD-1
    //TDA..
    int rec(int i,int j,string &a, string &b, vector<vector<int>>&dp)
    {
        if(i==a.length() || j==b.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(a[i]==b[j])
        {
            return dp[i][j]= 1+rec(i+1,j+1,a,b,dp);
        }
        else
        {
            return dp[i][j]= max(rec(i+1,j,a,b,dp),rec(i,j+1,a,b,dp));
        }
    }
    int longestCommonSubsequence(string a, string b) 
    {
        vector<vector<int>>dp(a.length(),vector<int>(b.length(),-1));
        return rec(0,0,a,b,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,int j,string &a, string &b)
    {
        if(i==a.length() || j==b.length())
        {
            return 0;
        }
        if(a[i]==b[j])
        {
            return 1+rec(i+1,j+1,a,b);
        }
        else
        {
            return max(rec(i+1,j,a,b),rec(i,j+1,a,b));
        }
    }
    int longestCommonSubsequence(string a, string b) 
    {
        return rec(0,0,a,b);
    }
*/
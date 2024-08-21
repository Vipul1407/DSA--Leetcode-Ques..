class Solution {
public:

    int rec(int i, int j, string &s, vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int steps= INT_MAX;
        for(int k=i;k<j;k++)
        {
            steps= min(steps, (rec(i,k,s,dp)+rec(k+1,j,s,dp)));
        }
        return dp[i][j]= (s[i]==s[j])? steps-1: steps;
    }
    int strangePrinter(string s) 
    {
        int n= s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return rec(0,n-1,s,dp);
    }
};
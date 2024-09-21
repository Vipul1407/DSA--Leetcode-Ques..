class Solution {
public:
    int lcs(int i,int j,string &s, string &rev, vector<vector<int>>&dp)
    {
        int n= s.length();
        if(i==n || j==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else if(s[i]==rev[j])
        {
            return dp[i][j]= 1+lcs(i+1,j+1,s,rev,dp);
        }
        else
        {
            return dp[i][j]= max(lcs(i+1,j,s,rev,dp),lcs(i,j+1,s,rev,dp));
        }
    }
    //DIRECTLY SAME AS LONGEST COMMOM SUBSEQUENCE....
    int minInsertions(string s)
    {
        int n= s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        //to get min operations..
        return n-lcs(0,0,s,rev,dp);
    }
};
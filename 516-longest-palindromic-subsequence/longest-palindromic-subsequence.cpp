class Solution {
public:
    int lcs(int i,int j,string &a, string &b,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==a.length() || j==b.length())
        {
            return 0;
        }
        if(a[i]==b[j])
        {
            return dp[i][j]= 1+lcs(i+1,j+1,a,b,dp);
        }
        else
        {
            return dp[i][j]= max(lcs(i+1,j,a,b,dp),lcs(i,j+1,a,b,dp));
        }
    }
    //same as longest common subsequence with s1= s and s2= rev(s)
    int longestPalindromeSubseq(string s) 
    {
        int n=s.length();
        string rev= s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return lcs(0,0,s,rev,dp);
    }
};
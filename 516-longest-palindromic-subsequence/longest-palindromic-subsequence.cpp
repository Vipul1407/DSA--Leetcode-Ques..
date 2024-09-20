class Solution {
public:

    //same as longest common subsequence with s1= s and s2= rev(s)
    int longestPalindromeSubseq(string s) 
    {
        int n= s.length();
        string rev= s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(n+11,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(s[i]==rev[j])
                {
                    dp[i][j]= 1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
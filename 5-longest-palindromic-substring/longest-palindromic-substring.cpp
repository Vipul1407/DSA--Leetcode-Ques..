class Solution {
public: 
    //METHOD-2
    //TDA..
    bool solve(int i,int j,string &s,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i>=j)
        {
            return 1;
        }
        if(s[i]==s[j])
        {
            return dp[i][j]= solve(i+1,j-1,s,dp);
        }
        else
        {
            return dp[i][j]= 0;
        }
    }
    string longestPalindrome(string s) 
    {
        int n= s.size();
        int maxlen=0;
        int start=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(solve(i,j,s,dp))
                {
                    if(j-i+1>maxlen)
                    {
                        maxlen= j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
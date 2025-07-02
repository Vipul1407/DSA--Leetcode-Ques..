class Solution {
public:
    //METHOD-1
    //TDA..
    bool palindrome(int i,int j, string &s, vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i>=j)
        {
            return true;
        }
        if(s[i]!=s[j])
        {
            return false;
        }
        return dp[i][j]= palindrome(i+1,j-1,s,dp);
    }
    string longestPalindrome(string s) 
    {
        int n= s.size();
        int maxlen=0;
        int start=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(palindrome(i,j,s,dp) && j-i+1> maxlen)
                {
                    start=i;
                    maxlen= max(maxlen,j-i+1);
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    bool palindrome(int i,int j, string &s)
    {
        if(i>=j)
        {
            return true;
        }
        if(s[i]!=s[j])
        {
            return false;
        }
        return palindrome(i+1,j-1,s);
    }
    string longestPalindrome(string s) 
    {
        int n= s.size();
        int maxlen=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(palindrome(i,j,s) && j-i+1> maxlen)
                {
                    start=i;
                    maxlen= max(maxlen,j-i+1);
                }
            }
        }
        return s.substr(start,maxlen);
    }
*/
class Solution {
public:
    bool solve(int i, int open, string s, vector<vector<int>>&dp)
    {
        int n=s.length();
        //base case
        if(i>=n)
        {
            return open==0;
        }
        if(dp[i][open]!=-1)
        {
            return dp[i][open];
        }
        bool ans=false;
        if(s[i]=='(')
        {
            ans=solve(i+1,open+1,s,dp);
        }
        else if(s[i]==')')
        {
            if(open>0)
            {
                ans=ans || solve(i+1,open-1,s,dp);
            }
        }
        //when s[i]=='*' then 3cases arises
        else
        {
            //assuming open
            bool case1=solve(i+1,open+1,s,dp);
            //assuming close 
            bool case2=false;
            if(open>0)
            {
                case2=solve(i+1,open-1,s,dp);
            }
            //assuming ""
            bool case3=solve(i+1,open,s,dp);
            ans=case1 || case2 || case3;
        }
        return dp[i][open]=ans;
    }
    bool checkValidString(string s) 
    {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,s,dp);
    }
};
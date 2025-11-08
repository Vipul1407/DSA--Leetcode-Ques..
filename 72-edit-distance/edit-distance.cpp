class Solution {
public:
    //METHOD-2
    //TDA..
    int rec(int i,int j,string &a, string &b, vector<vector<int>>&dp)
    {
        if(i==a.size())
        {
            return b.size()-j;//delete all char in word2
        }
        if(j==b.size())
        {
            return a.size()-i; //delete all char in word1
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(a[i]==b[j])
        {
            return dp[i][j]= rec(i+1,j+1,a,b,dp);
        }
        else
        {
            //insert
            int insert= rec(i,j+1,a,b,dp);
            //delete
            int del= rec(i+1,j,a,b,dp);
            //replace
            int replace= rec(i+1,j+1,a,b,dp);
            return dp[i][j]= 1+ min(insert,min(del,replace));
        }
    }
    int minDistance(string a, string b) 
    {
        vector<vector<int>>dp(a.size(),vector<int>(b.size(),-1));
        return rec(0,0,a,b,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,int j,string &a, string &b)
    {
        if(i==a.size())
        {
            return b.size()-j;//delete all char in word2
        }
        if(j==b.size())
        {
            return a.size()-i; //delete all char in word1
        }
        if(a[i]==b[j])
        {
            return rec(i+1,j+1,a,b);
        }
        else
        {
            //insert
            int insert= rec(i,j+1,a,b);
            //delete
            int del= rec(i+1,j,a,b);
            //replace
            int replace= rec(i+1,j+1,a,b);
            return 1+ min(insert,min(del,replace));
        }
    }
    int minDistance(string a, string b) 
    {
        return rec(0,0,a,b);
    }
*/
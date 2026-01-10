class Solution {
public: 
    //METHOD-1
    //TDA..
    int tda(int i,int j,string &s1, string &s2,vector<vector<int>>&dp)
    {
        int m= s1.size();
        int n= s2.size();
        if(i>=m && j>=n)
        {
            return 0;
        }
        if(i==m)
        {
            int cnt=0;
            while(j<n)
            {
                cnt+= s2[j];
                j++;
            }
            return cnt;
        }
        if(j==n)
        {
            int cnt=0;
            while(i<m)
            {
                cnt+= s1[i];
                i++;
            }
            return cnt;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            return dp[i][j]= tda(i+1,j+1,s1,s2,dp);
        }
        else
        {
            return dp[i][j]= min(s1[i]+tda(i+1,j,s1,s2,dp),s2[j]+tda(i,j+1,s1,s2,dp));
        }
    }
    int minimumDeleteSum(string s1, string s2) 
    {
        int m= s1.size();
        int n= s2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return tda(0,0,s1,s2,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,int j,string s1, string s2)
    {
        int m= s1.size();
        int n= s2.size();
        if(i>=m && j>=n)
        {
            return 0;
        }
        if(i==m)
        {
            int cnt=0;
            while(j<n)
            {
                cnt+= s2[j];
                j++;
            }
            return cnt;
        }
        if(j==n)
        {
            int cnt=0;
            while(i<m)
            {
                cnt+= s1[i];
                i++;
            }
            return cnt;
        }
        if(s1[i]==s2[j])
        {
            return rec(i+1,j+1,s1,s2);
        }
        else
        {
            return min(s1[i]+rec(i+1,j,s1,s2),s2[j]+rec(i,j+1,s1,s2));
        }
    }
    int minimumDeleteSum(string s1, string s2) 
    {
        return rec(0,0,s1,s2);
    }
*/
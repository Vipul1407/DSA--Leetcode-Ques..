class Solution {
public:
    int rec(int i,int k,string &s,vector<vector<int>>&dp)
    {
        int n= s.size();
        //not possible case..
        if(k<0)
        {
            return 1e5;
        }
        if(i>=n || n-i<=k)
        {
            return 0;
        }
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        int notkeep= rec(i+1,k-1,s,dp);
        int keep= INT_MAX;
        char ch= s[i];
        int freq=0;
        int deleted=0;
        int add=0;
        for(int j=i;j<n;j++)
        {
            if(s[j]==ch)
            {
                freq++;
                if(freq==2 || freq==10 || freq==100)
                {
                    add++;
                }
            }
            else
            {
                deleted++;
            }
            if(k-deleted>=0)
                keep= min(keep, 1+add+rec(j+1,k-deleted,s,dp));
        }
        return dp[i][k]= min(keep,notkeep);
    }
    int getLengthOfOptimalCompression(string s, int k) 
    {
        int n= s.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return rec(0,k,s,dp);
    }
};
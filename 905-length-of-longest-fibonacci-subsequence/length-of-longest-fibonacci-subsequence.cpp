class Solution {
public:
    //METHOD-2
    //TDA
    int tda(int j,int k,unordered_map<int,int>&mp,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(dp[j][k]!=-1)
        {
            return dp[j][k];
        }
        int tar= arr[k]-arr[j];
        if(mp.find(tar)!=mp.end())
        {
            int i= mp[tar];
            if(i<j)
            {
                return dp[j][k]= 1+tda(i,j,mp,arr,dp);
            }
        }
        return dp[j][k]= 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int n= arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=0;
        for(int j=1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int len= tda(j,k,mp,arr,dp);
                if(len>=3)
                {
                    ans= max(ans,len);
                }
            }
        }
        return ans;
    }
};
/*
// METHOD-1
// RECURSIVE
int rec(int j, int k, unordered_map<int, int> &mp, vector<int> &arr)
{
    int tar = arr[k] - arr[j];
    if (mp.find(tar) != mp.end())
    {
        int i = mp[tar];
        if (i < j)
        {
            return 1 + rec(i, j, mp, arr);
        }
    }
    return 2;
}
int lenLongestFibSubseq(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    int ans = 0;
    for (int j = 1; j < n - 1; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            int len = rec(j, k, mp, arr);
            if (len >= 3)
            {
                ans = max(ans, len);
            }
        }
    }
    return ans;
}
*/
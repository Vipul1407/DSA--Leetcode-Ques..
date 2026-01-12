class Solution {
public:
    //METHOD-2
    //TDA..
    int tda(int i, vector<int>& arr, int k, vector<int>&dp)
    {
        int n= arr.size();
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans= 0;
        int maxi= 0;
        for(int j=i; j<n && j-i+1<=k; j++)
        {
            maxi= max(maxi,arr[j]);
            ans= max(ans, maxi*(j-i+1)+ tda(j+1,arr,k,dp));
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        vector<int>dp(arr.size(),-1);
        return tda(0,arr,k,dp);
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(int i,vector<int>& arr, int k)
    {
        int n= arr.size();
        if(i>=n)
        {
            return 0;
        }
        int ans= 0;
        int maxi= 0;
        for(int j=i; j<n && j-i+1<=k; j++)
        {
            maxi= max(maxi,arr[j]);
            ans= max(ans, maxi*(j-i+1)+ rec(j+1,arr,k));
        }
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        return rec(0,arr,k);
    }
*/
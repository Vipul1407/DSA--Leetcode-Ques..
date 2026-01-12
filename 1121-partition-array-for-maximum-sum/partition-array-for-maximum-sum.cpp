class Solution {
public:
    //METHOD-3
    //BUA..
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int maxi=0;
            int ans=0;
            for(int j=i;j<n && j-i+1<=k;j++)
            {
                maxi= max(maxi,arr[j]);
                ans= max(ans, maxi*(j-i+1)+ dp[j+1]);
            }
            dp[i]= ans;
        }
        return dp[0];
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
*/
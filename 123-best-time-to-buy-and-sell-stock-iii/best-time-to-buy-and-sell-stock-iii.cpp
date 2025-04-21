class Solution {
public:
    //METHOD-3
    //BUA..
    int maxProfit(vector<int>& arr) 
    {
        int n= arr.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //i=0 ,canbuy=1 and limit=2 initially..
        int profit=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int canbuy=0;canbuy<=1;canbuy++)
            {
                for(int limit=1;limit<=2;limit++)
                {
                    if(canbuy)
                    {
                        int buy= -arr[i]+dp[i+1][0][limit];
                        int skip= dp[i+1][1][limit];
                        profit= max(buy,skip);
                    }
                    else
                    {
                        int sell= arr[i]+dp[i+1][1][limit-1];
                        int skip= dp[i+1][0][limit];
                        profit= max(sell,skip);
                    }
                    dp[i][canbuy][limit]= profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
/*
    //METHOD-1
    //RECUSIVE..
    int rec(int i,vector<int>& arr, int canbuy, int limit)
    {
        if(i>= arr.size() || limit==0)
        {
            return 0;
        }
        int profit=0;
        if(canbuy)
        {
            int buy= -arr[i]+rec(i+1,arr,0,limit);
            int skip= rec(i+1,arr,1,limit);
            profit= max(buy,skip);
        }
        else
        {
            int sell= arr[i]+rec(i+1,arr,1,limit-1);
            int skip= rec(i+1,arr,0,limit);
            profit= max(sell,skip);
        }
        return profit;
    }
    int maxProfit(vector<int>& arr) 
    {
        int n= arr.size();
        //i=0 ,canbuy=1 and limit=2 initially..
        return rec(0,arr,1,2);
    }

    //METHOD-2
    //TDA..
    int tda(int i,vector<int>& arr, int canbuy, int limit, vector<vector<vector<int>>>&dp)
    {
        if(i>= arr.size() || limit==0)
        {
            return 0;
        }
        if(dp[i][canbuy][limit]!=-1)
        {
            return dp[i][canbuy][limit];
        }
        int profit=0;
        if(canbuy)
        {
            int buy= -arr[i]+tda(i+1,arr,0,limit,dp);
            int skip= tda(i+1,arr,1,limit,dp);
            profit= max(buy,skip);
        }
        else
        {
            int sell= arr[i]+tda(i+1,arr,1,limit-1,dp);
            int skip= tda(i+1,arr,0,limit,dp);
            profit= max(sell,skip);
        }
        return dp[i][canbuy][limit]= profit;
    }
    int maxProfit(vector<int>& arr) 
    {
        int n= arr.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        //i=0 ,canbuy=1 and limit=2 initially..
        return tda(0,arr,1,2,dp);
    }
*/
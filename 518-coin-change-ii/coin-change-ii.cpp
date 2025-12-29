class Solution {
public:

    //METHOD-3
    //BUA..
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += (long long)dp[j - coin];
            }
        }
        
        return (int)dp[amount];
    }
};
/*
    //METHOD-1
    int rec(int i,int amount, vector<int>& coins)
    {
        if(amount==0)
        {
            return 1;
        }
        if(i>= coins.size() || amount<0)
        {
            return 0;
        }
        //can reuse coin..   so stay on same i..
        int take= rec(i,amount-coins[i],coins);
        int notake= rec(i+1,amount,coins);
        return take+notake;
    }
    int change(int amount, vector<int>& coins) 
    {
        return rec(0,amount,coins);
    }

    //METHOD-2
    //TDA..
    int tda(int i,int amount, vector<int>& coins,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }
        if(i>= coins.size() || amount<0)
        {
            return 0;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        //can reuse coin..   so stay on same i..
        int take= tda(i,amount-coins[i],coins,dp);
        int notake= tda(i+1,amount,coins,dp);
        return dp[i][amount]= take+notake;
    }
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return tda(0,amount,coins,dp);
    }
*/
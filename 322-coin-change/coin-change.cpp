class Solution {
public:
    //METHOD-3
    //BUA..
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
/*
    //METHOD-1
    //RECURSIVE..
    int rec(vector<int>& coins, int amount)
    {
        if(amount==0)
        {
            return 0;
        }
        if(amount<0)
        {
            return INT_MAX;
        }
        int ans= INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int mini= rec(coins,amount-coins[i]);
            if(mini!=INT_MAX)
            {
                ans= min(ans, 1+mini);
            }
        }
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int ans= rec(coins,amount);
        return ans==INT_MAX ? -1:ans;
    }

    //METHOD-2
    //TDA..
    int tda(vector<int>& coins, int amount, vector<int>&dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(amount<0)
        {
            return INT_MAX;
        }
        if(dp[amount]!=-1)
        {
            return dp[amount];
        }
        int ans= INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int mini= tda(coins,amount-coins[i],dp);
            if(mini!=INT_MAX)
            {
                ans= min(ans, 1+mini);
            }
        }
        return dp[amount]= ans;
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int>dp(amount+1,-1); 
        int ans= tda(coins,amount,dp);
        return ans==INT_MAX ? -1:ans;
    }
*/
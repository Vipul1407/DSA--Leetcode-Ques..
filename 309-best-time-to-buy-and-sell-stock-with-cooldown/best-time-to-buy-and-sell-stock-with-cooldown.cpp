class Solution {
public:

    // METHOD-4
    // SPACE OPTIMIZED..
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        vector<int>curr(2, 0);
        vector<int>next1(2, 0);
        vector<int>next2(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int canbuy = 0; canbuy <= 1; canbuy++)
            {
                if (canbuy == 1)
                {
                    int buy = -nums[i] + next1[0];
                    int skip = next1[1];
                    profit = max(buy, skip);
                }
                else
                {
                    //add 1 day cooldown period..
                    int sell = nums[i] + next2[1];
                    int skip = next1[0];
                    profit = max(sell, skip);
                }
                curr[canbuy] = profit;
            }
            next2=next1;
            next1= curr;
        }
        return curr[1];
    }
};
/*
    // COOLDOWN PERIOD...
    // METHOD-1
    // RECURSIVE..
    int rec(int i, int canbuy, vector<int> &nums)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        int profit = 0;
        if (canbuy)
        {
            int buy = -nums[i] + rec(i + 1, 0, nums);
            int skip = rec(i + 1, 1, nums);
            profit = max(buy, skip);
        }
        else
        {
            //add 1 day cooldown period..
            int sell = nums[i] + rec(i + 2, 1, nums);
            int skip = rec(i + 1, 0, nums);
            profit = max(sell, skip);
        }
        return profit;
    }
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        return rec(0, 1, nums);
    }

        // METHOD-2
    // TDA..
    int tda(int i, int canbuy, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (dp[i][canbuy] != -1)
        {
            return dp[i][canbuy];
        }
        int profit = 0;
        if (canbuy)
        {
            int buy = -nums[i] + tda(i + 1, 0, nums, dp);
            int skip = tda(i + 1, 1, nums, dp);
            profit = max(buy, skip);
        }
        else
        {
            //add 1 day cooldown period..
            int sell = nums[i] + tda(i + 2, 1, nums, dp);
            int skip = tda(i + 1, 0, nums, dp);
            profit = max(sell, skip);
        }
        return dp[i][canbuy] = profit;
    }
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return tda(0, 1, nums, dp);
    }

    // METHOD-3
    // BUA..
    int maxProfit(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            int profit = 0;
            for (int canbuy = 0; canbuy <= 1; canbuy++)
            {
                if (canbuy == 1)
                {
                    int buy = -nums[i] + dp[i + 1][0];
                    int skip = dp[i + 1][1];
                    profit = max(buy, skip);
                }
                else
                {
                    //add 1 day cooldown period..
                    int sell = nums[i] + dp[i + 2][1];
                    int skip = dp[i + 1][0];
                    profit = max(sell, skip);
                }
                dp[i][canbuy] = profit;
            }
        }
        return dp[0][1];
    }
*/
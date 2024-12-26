class Solution {
public:
    //METHOD-4
    //SPACE OPTIMIZATION APPROACH..
    int findTargetSumWays(vector<int>& nums, int tar) 
    {
        int n= nums.size();
        int S= accumulate(nums.begin(),nums.end(),0);
        if(tar<-S || tar>S)
        {
            return 0;
        }
        vector<int>curr(2*S+1,0);
        vector<int>next(2*S+1,0);

        next[S]=1;//base case..
        for(int i=n-1;i>=0;i--)
        {
            for(int sum=-S;sum<=S;sum++)
            {
                int plus=0;
                int minus=0;
                if(sum+nums[i]+S<=2*S)
                {
                    plus= next[sum+nums[i]+S];
                }
                if(sum-nums[i]+S>=0)
                {
                    minus= next[sum-nums[i]+S];
                }
                curr[sum+S]= plus+minus;
            }
            next=curr;
        }

        return curr[tar+S]; 
    }
};

/*
// METHOD-1
// RECURSIVE
int rec(int i, vector<int> &nums, int sum, int tar)
{
    if (i >= nums.size())
    {
        if (sum == tar)
        {
            return 1;
        }
        return 0;
    }
    int plus = rec(i + 1, nums, sum + nums[i], tar);
    int minus = rec(i + 1, nums, sum - nums[i], tar);
    return plus + minus;
}
int findTargetSumWays(vector<int> &nums, int tar)
{
    return rec(0, nums, 0, tar);
}

// METHOD-2
//  TDA
// BEATS 52%
// USING index+S in dp table to avoid -ve index...
int S = 0;
int rec(int i, vector<int> &nums, int sum, int tar, vector<vector<int>> &dp)
{
    if (i >= nums.size())
    {
        if (sum == tar)
        {
            return 1;
        }
        return 0;
    }
    if (dp[i][sum + S] != -1)
    {
        return dp[i][sum + S];
    }
    int plus = rec(i + 1, nums, sum + nums[i], tar, dp);
    int minus = rec(i + 1, nums, sum - nums[i], tar, dp);
    return dp[i][sum + S] = plus + minus;
}
int findTargetSumWays(vector<int> &nums, int tar)
{
    int n = nums.size();
    for (auto i : nums)
    {
        S += i;
    }
    // to account for (-S,+S) => size must be (2*S)+1
    // to avoid for -ve sum index in dp table => we must do sum+S....
    vector<vector<int>> dp(n + 1, vector<int>((2 * S) + 1, -1));
    return rec(0, nums, 0, tar, dp);
}

// TDA APPROACH..
// BEATS 32%
// USING UNORDERED_MAP TO AVOID -VE INDEX...
int rec(int i, vector<int> &nums, int sum, int tar, unordered_map<string, int> &mp)
{
    if (i >= nums.size())
    {
        if (sum == tar)
        {
            return 1;
        }
        return 0;
    }
    string key = to_string(i) + "_" + to_string(sum);
    if (mp.count(key))
    {
        return mp[key];
    }
    int plus = rec(i + 1, nums, sum + nums[i], tar, mp);
    int minus = rec(i + 1, nums, sum - nums[i], tar, mp);
    return mp[key] = plus + minus;
}
int findTargetSumWays(vector<int> &nums, int tar)
{
    int n = nums.size();
    unordered_map<string, int> mp;
    return rec(0, nums, 0, tar, mp);
}

// METHOD-3
// BUA
// BEATS 52%
int findTargetSumWays(vector<int> &nums, int tar)
{
    int n = nums.size();
    int S = accumulate(nums.begin(), nums.end(), 0);
    if (tar < -S || tar > S)
    {
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(2 * S + 1, 0));

    dp[n][S] = 1; // base case..
    for (int i = n - 1; i >= 0; i--)
    {
        for (int sum = -S; sum <= S; sum++)
        {
            int plus = 0;
            int minus = 0;
            if (sum + nums[i] + S <= 2 * S)
            {
                plus = dp[i + 1][sum + nums[i] + S];
            }
            if (sum - nums[i] + S >= 0)
            {
                minus = dp[i + 1][sum - nums[i] + S];
            }
            dp[i][sum + S] = plus + minus;
        }
    }
    return dp[0][tar + S];
}
*/
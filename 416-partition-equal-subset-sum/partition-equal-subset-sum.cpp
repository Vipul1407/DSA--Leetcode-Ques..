class Solution {
public:
    // METHOD-4
    // SPACE OPTIMIZED
    bool canPartition(vector<int>& nums) 
    {
        int n= nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
        {
            return false;
        }
        int tar= sum/2;
        vector<bool>curr(tar+1,false);
        vector<bool>next(tar+1,false);
        //base case: tar==0 return true;
        for(int i=0;i<=n;i++)
        {
            next[0]= true;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=tar;j++)
            {
                bool take= j-nums[i]>=0? next[j-nums[i]]:false;
                bool notake= next[j];
                curr[j]= take || notake;
            }
            next=curr;
        }
        return curr[tar];
    }
};
/*

// METHOD-1
// RECURSIVE..
bool solve(int i, vector<int> &nums, int tar)
{
    if (i >= nums.size())
    {
        return false;
    }
    if (tar == 0)
    {
        return true;
    }
    if (tar < 0)
    {
        return false;
    }
    return solve(i + 1, nums, tar - nums[i]) || solve(i + 1, nums, tar);
}
bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
    {
        return false;
    }
    return solve(0, nums, sum / 2) ? true : false;
}

// METHOD-2
// TDA
bool solve(int i, vector<int> &nums, int tar, vector<vector<int>> &dp)
{
    if (i >= nums.size())
    {
        return false;
    }
    if (tar == 0)
    {
        return true;
    }
    if (tar < 0)
    {
        return false;
    }
    if (dp[i][tar] != -1)
    {
        return dp[i][tar];
    }
    return dp[i][tar] = solve(i + 1, nums, tar - nums[i], dp) || solve(i + 1, nums, tar, dp);
}
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
    {
        return false;
    }
    vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));
    return solve(0, nums, sum / 2, dp) ? true : false;
}

// METHOD-3
// BUA
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
    {
        return false;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>((sum / 2) + 1, false));
    // base case: tar==0 return true;
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    int tar = sum / 2;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= tar; j++)
        {
            bool take = j - nums[i] >= 0 ? dp[i + 1][j - nums[i]] : false;
            bool notake = dp[i + 1][j];
            dp[i][j] = take || notake;
        }
    }
    return dp[0][tar];
}

*/
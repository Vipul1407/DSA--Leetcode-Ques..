class Solution {
public:
    //TC= O(NLOGN + NLOGN)
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        //[w,h]
        int n= envelopes.size();
        //sort in increasing order by w and  if w same then in descending order of h..
        //apply LIS on h..
        sort(begin(envelopes),end(envelopes),[](auto &a, auto &b)
        {
            return a[0]!=b[0]? a[0]<b[0]: a[1]>b[1];
        });
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++)
        {
           if(envelopes[i][1]>ans.back())
           {
                ans.push_back(envelopes[i][1]);
           }
           else
           {
                //lower bound nikal nums[i] ka ans vector me..
                int just_greater_index= lower_bound(begin(ans),end(ans),envelopes[i][1])- begin(ans);
                ans[just_greater_index]= envelopes[i][1];
           }
        }
        //only length is corect but the order is wrong...
        return ans.size();
    }
};
/*
// METHOD-1
// RECURSIVE..
// TC= O(2^N)
// TLE..
int rec(int i, int previdx, vector<vector<int>> &nums)
{
    if (i >= nums.size())
    {
        return 0;
    }
    int take = 0;
    if (previdx == -1 || nums[i] > nums[previdx])
    {
        take = 1 + rec(i + 1, i, nums);
    }
    int notake = rec(i + 1, previdx, nums);
    return max(take, notake);
}
int maxEnvelopes(vector<vector<int>> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end(), [](auto &a, auto &b)
         {
            if(a[0]!=b[0])
            {
                return a[0]<b[0];
            }
            return a[1]>b[1]; });
    return rec(0, -1, nums);
}

// METHOD-2
// TDA..
// TC= O(N^2+ NLOGN)
// TLE.....
int tda(int i, int previdx, vector<vector<int>> &nums, vector<vector<int>> &dp)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (dp[i][previdx + 1] != -1)
    {
        return dp[i][previdx + 1];
    }
    int take = 0;
    if (previdx == -1 || nums[i][1] > nums[previdx][1])
    {
        take = 1 + tda(i + 1, i, nums, dp);
    }
    int notake = tda(i + 1, previdx, nums, dp);
    return dp[i][previdx + 1] = max(take, notake);
}
int maxEnvelopes(vector<vector<int>> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end(), [](auto &a, auto &b)
         {
            if(a[0]!=b[0])
            {
                return a[0]<b[0];
            }
            return a[1]>b[1]; });
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return tda(0, -1, nums, dp);
}

// METHOD-3
// BUA..
// MEMORY LIMIT EXCEEDED...
int maxEnvelopes(vector<vector<int>> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end(), [](auto &a, auto &b)
         {
            if(a[0]!=b[0])
            {
                return a[0]<b[0];
            }
            return a[1]>b[1]; });
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int take = 0;
            if (j == -1 || nums[i][1] > nums[j][1])
            {
                // here in col we take i+1 as coordinate of row changes so we have to change this also..
                take = 1 + dp[i + 1][i + 1];
            }
            int notake = dp[i + 1][j + 1];
            dp[i][j + 1] = max(take, notake);
        }
    }
    return dp[0][0];
}

// METHOD-4
// SPACE OPTIMIZED..
// TLE..
int maxEnvelopes(vector<vector<int>> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end(), [](auto &a, auto &b)
         {
            if(a[0]!=b[0])
            {
                return a[0]<b[0];
            }
            return a[1]>b[1]; });
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int take = 0;
            if (j == -1 || nums[i][1] > nums[j][1])
            {
                // here in col we take i+1 as coordinate of row changes so we have to change this also..
                take = 1 + next[i + 1];
            }
            int notake = next[j + 1];
            curr[j + 1] = max(take, notake);
        }
        next = curr;
    }
    return next[0];
}
*/
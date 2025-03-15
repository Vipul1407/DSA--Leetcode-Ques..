class Solution {
public:
    // METHOD-3
    // OPTIMIZED USING BINARY SEARCH...
    bool possi(int mid, vector<int>& nums, int k)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
            {
                cnt++;
                i++;//to skip the adjacent
            }
        }
        return cnt>=k;//atleast k houses..
    }
    int minCapability(vector<int>& nums, int k) 
    {
        int l= *min_element(nums.begin(),nums.end());
        int r= *max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(possi(mid,nums,k))
            {
                ans= mid;
                r= mid-1;//to get min ans..
            }
            else
            {
                l= mid+1;
            }
        }
        return ans;
    }
};
/*
// METHOS-1
// RECURSIVE
// TLE...
int rec(int i, vector<int> &nums, int k)
{
    if (k == 0)
    {
        return 0;
    }
    if (i >= nums.size())
    {
        // invalid case returning INT_MAX
        return 1e9;
    }
    int take = max(nums[i], rec(i + 2, nums, k - 1));
    int notake = rec(i + 1, nums, k);
    return min(take, notake);
}
int minCapability(vector<int> &nums, int k)
{
    int n = nums.size();
    return rec(0, nums, k);
}

// METHOD-2
// TDA
// TLE...
int rec(int i, vector<int> &nums, int k, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return 0;
    }
    if (i >= nums.size())
    {
        // invalid case returning INT_MAX
        return 1e9;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    int take = max(nums[i], rec(i + 2, nums, k - 1, dp));
    int notake = rec(i + 1, nums, k, dp);
    return dp[i][k] = min(take, notake);
}
int minCapability(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return rec(0, nums, k, dp);
}
*/
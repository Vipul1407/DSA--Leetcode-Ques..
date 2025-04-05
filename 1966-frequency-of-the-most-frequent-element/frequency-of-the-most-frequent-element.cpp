class Solution {
public:
    // METHOD-1
    // BINARY SEARCH..
    int solve(vector<int> &nums, vector<long> &prefsum, int k, int i)
    {
        int l=0;
        int r=i;
        int best_idx=i;
        int tar= nums[i];
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            long size= i-mid+1;
            long expectedsum= size*tar;
            long originalsum= prefsum[i]-prefsum[mid]+nums[mid];
            if(expectedsum-originalsum<=k)
            {
                best_idx= mid;
                r= mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        return i-best_idx+1;
    }
    int maxFrequency(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<long> prefsum(n, 0);
        prefsum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefsum[i] = prefsum[i - 1] + nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, solve(nums, prefsum, k, i));
        }
        return ans;
    }
};
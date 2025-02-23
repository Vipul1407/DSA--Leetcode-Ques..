class Solution {
public:
    // METHOD-3
    // OPTIMIZED APPROACH..
    long long countBadPairs(vector<int>& nums) 
    {
        int n= nums.size();
        long long ans=0;
        unordered_map<int,int>mp;
        mp[nums[0]]++;
        for(int i=1;i<n;i++)
        {
            ans+= i-mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        return ans;
    }
};
/*

// METHOD-1
// OPTIMIZED BRUTE APPROACH..
// TLE
long long countBadPairs(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums[i] -= i;
    }
    unordered_map<int, int> mp;
    mp[nums[0]]++;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int curr = nums[i];
        for (auto j : mp)
        {
            if (curr == j.first)
            {
                continue;
            }
            ans += j.second;
        }
        mp[curr]++;
    }

    return ans;
}

// METHOD-2
// BETTER APPROACH..
long long countBadPairs(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums[i] -= i;
    }
    unordered_map<int, int> mp;
    mp[nums[0]]++;
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += (i - mp[nums[i]]);
        mp[nums[i]]++;
    }
    return ans;
}

*/
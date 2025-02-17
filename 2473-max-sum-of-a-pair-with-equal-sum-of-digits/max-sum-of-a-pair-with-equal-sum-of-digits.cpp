class Solution {
public:
    // METHOD-3
    // USING VECTOR..
    int maximumSum(vector<int>& nums) 
    {
        vector<int>arr(82,-1);
        int ans=-1;
        for(auto i:nums)
        {
            int temp=i;
            int sum=0;
            while(temp)
            {
                sum+= temp%10;
                temp/=10;
            }
            if(arr[sum]==-1)
            {
                arr[sum]= i;
            }
            else
            {
                ans= max(ans,arr[sum]+i);
                arr[sum]= max(arr[sum],i);
            }
        }
        return ans;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
int maximumSum(vector<int> &nums)
{
    int n = nums.size();
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = nums[i];
            int sumx = 0;
            int temp = x;
            while (temp)
            {
                sumx += temp % 10;
                temp /= 10;
            }
            int y = nums[j];
            int sumy = 0;
            temp = y;
            while (temp)
            {
                sumy += temp % 10;
                temp /= 10;
            }
            if (sumx == sumy)
            {
                ans = max(ans, x + y);
            }
        }
    }
    return ans;
}

// METHOD-2
// USING UNORDERED MAP
int maximumSum(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int ans = -1;
    for (auto i : nums)
    {
        int temp = i;
        int sum = 0;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (mp.find(sum) != mp.end())
        {
            ans = max(ans, mp[sum] + i);
            mp[sum] = max(mp[sum], i);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return ans;
}
*/
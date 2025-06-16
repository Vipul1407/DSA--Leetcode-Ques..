class Solution {
public:
    const int MOD= 1000000007;
    int specialTriplets(vector<int>& nums) 
    {
        long long ans=0;
        int n= nums.size();
        unordered_map<int,long long>rightmp;
        for(auto i:nums)
        {
            rightmp[i]++;
        }
        unordered_map<int,long long>leftmp;
        for(int i=0;i<n;i++)
        {
            rightmp[nums[i]]--;
            int ele= 2*nums[i];
            ans= (ans+ (rightmp[ele]*leftmp[ele])%MOD)%MOD;
            leftmp[nums[i]]++;
        }
        return (int)ans;
    }
};
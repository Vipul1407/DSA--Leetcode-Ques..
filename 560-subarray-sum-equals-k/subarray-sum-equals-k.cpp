class Solution {
public:
    //OPTIMIZED...
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(auto i:nums)
        {
            sum+= i;
            ans+= mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};
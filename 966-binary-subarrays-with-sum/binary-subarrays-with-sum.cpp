class Solution {
public:
    //METHOD-1
    //PREFIXSUM APPROACH..
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefsum=0;
        int ans=0;
        for(auto i:nums)
        {
            prefsum+= i;
            int remove= prefsum-k;
            ans+= mp[remove];
            mp[prefsum]++;
        }
        return ans;
    }
};
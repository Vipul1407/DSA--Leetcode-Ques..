class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int n= nums.size();
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto i:nums)
        {
            mp[i]++;
            maxi= max(maxi,mp[i]);
        }
        int ans=0;
        for(auto i:mp)
        {
            if(i.second==maxi)
            {
                ans++;
            }
        }
        return ans*maxi;
    }
};
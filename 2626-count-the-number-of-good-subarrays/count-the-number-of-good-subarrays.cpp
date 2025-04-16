class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        int n= nums.size();
        long long pairs=0;
        long long ans=0;
        unordered_map<int,int>mp;
        int i=0;
        for(int j=0;j<n;j++)
        {
            pairs+= mp[nums[j]];
            mp[nums[j]]++;
            while(pairs>=k)
            {
                ans+= n-j;
                mp[nums[i]]--;
                pairs-=mp[nums[i]];
                i++;
            }
        }
        return ans;
    }
};
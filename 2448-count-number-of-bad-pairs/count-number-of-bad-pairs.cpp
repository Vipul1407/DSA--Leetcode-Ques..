class Solution {
public:
    //METHOD-2
    //BETTER APPROACH..
    long long countBadPairs(vector<int>& nums) 
    {
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]-=i;
        }
        unordered_map<int,int>mp;
        mp[nums[0]]++;
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            ans+= (i-mp[nums[i]]);
            mp[nums[i]]++;
        }
        return ans;
    }
};
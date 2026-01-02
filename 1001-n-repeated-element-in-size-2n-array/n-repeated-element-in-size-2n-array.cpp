class Solution {
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int n= nums.size();
        for(auto i:nums)
        {
            mp[i]++;
            if(mp[i]==n/2)
            {
                return i;
            }
        }
        return nums[0];
    }
};
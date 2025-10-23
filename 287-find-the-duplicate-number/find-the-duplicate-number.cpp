class Solution {
public:
    //METHOD-2
    //Unordered Map..
    int findDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
            if(mp[i]>1)
            {
                return i;
            }
        }
        return -1;
    }
};
/*
    //METHOD-1
    //SORTING..
    int findDuplicate(vector<int>& nums) 
    {
        sort(begin(nums),end(nums));
        int n= nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i])
            {
                return nums[i];
            }
        }
        return -1;
    }
*/
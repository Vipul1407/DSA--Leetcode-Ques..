class Solution {
public:
    //METHOD-4
    //Cycle detection in directed graph..
    int findDuplicate(vector<int>& nums) 
    {
        int n= nums.size();
        int slow=0,fast=0;
        do
        {
            slow= nums[slow];
            fast= nums[nums[fast]];
        }
        while(slow!=fast);
        
        slow=0;
        while(slow!=fast)
        {
            slow= nums[slow];
            fast= nums[fast];
        }
        return slow;
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

    //METHOD-3
    //Modifying the array..
    int findDuplicate(vector<int>& nums) 
    {
        int n= nums.size();
        int idx=0;
        while(true)
        {
            //if already negative value..
            if(nums[idx]<0)
            {
                return idx;
            }
            nums[idx]= -nums[idx];
            idx= -nums[idx];
        }
        return -1;
    }
*/
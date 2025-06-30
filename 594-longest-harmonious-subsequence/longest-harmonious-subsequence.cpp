class Solution {
public:
    //METHOD-2
    //Using Sliding Window..
    int findLHS(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        
        int l=0,r=0;
    
        while(r<n)
        {
            while(l<r && nums[r]-nums[l]>1)
            {
                l++;
            }
            if(nums[r]-nums[l]==1)
            {
                ans= max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};
/*
    //METHOD-1
    //Using Unordered_Map
    int findLHS(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        for(auto i:mp)
        {
            int next= 0;
            //do not use mp[i.first+1]>0 as it will create new entry in it...
            if(mp.count(i.first+1))
            {
                next= i.second+ mp[i.first+1];
                ans= max(ans,next);
            }
        }
        return ans;
    }
*/
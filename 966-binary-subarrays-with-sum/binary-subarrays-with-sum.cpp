class Solution {
public:
    //METHOD-2
    //SLIDING WINDOW APPROACH..
    int solve(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int l=0,r=0,ans=0,sum=0;
        while(r<n)
        {
            sum+= nums[r];
            while(l<r && sum>k)
            {
                sum-= nums[l];
                l++;
            }
            if(sum<=k)
                ans+= r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        return solve(nums,k)-solve(nums,k-1);
    }
};
/*
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
*/
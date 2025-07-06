class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int n= nums.size();
        unordered_map<int,int>mp;
        int l=0,r=0,ans=0;
        while(r<n)
        {
            mp[nums[r]]++;
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+= r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return solve(nums,k)-solve(nums,k-1);
    }
};
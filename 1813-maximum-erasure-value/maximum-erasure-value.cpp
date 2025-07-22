class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n= nums.size();
        int l=0,r=0;
        int ans=0,sum=0;
        unordered_map<int,int>mp;
        while(r<n)
        {
            while(l<r && mp[nums[r]]>0)
            {
                mp[nums[l]]--;
                sum-= nums[l];
                l++;
            }
            mp[nums[r]]++;
            sum+= nums[r];
            ans= max(ans,sum);
            r++;
        }
        return ans;
    }
};
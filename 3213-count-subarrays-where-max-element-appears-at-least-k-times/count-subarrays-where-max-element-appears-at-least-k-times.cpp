class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int n= nums.size();
        long long ans=0;
        int cnt=0;
        int maxele= *max_element(nums.begin(),nums.end());
        int l=0,r=0;
        while(r<n)
        {
            if(nums[r]==maxele)
            {
                cnt++;
            }
            while(l<=r && cnt>=k)
            {
                ans+= n-r;
                if(nums[l]==maxele)
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
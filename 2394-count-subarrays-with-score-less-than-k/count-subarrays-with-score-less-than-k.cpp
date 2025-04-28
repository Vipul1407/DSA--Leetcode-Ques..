class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        long long ans=0;
        long long sum=0;
        int l=0,r=0;
        int n= nums.size();
        while(r<n)
        {
            sum+= nums[r];
            while(l<=r && sum*(r-l+1)>=k)
            {
                sum-= nums[l];
                l++;
            }
            ans+= (r-l+1);
            r++;
        }
        return ans;
    }
};
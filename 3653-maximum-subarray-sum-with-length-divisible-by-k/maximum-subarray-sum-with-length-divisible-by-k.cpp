class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) 
    {
        vector<long long>mp(k+1,1e18);
        long long sum=0;
        long long ans= LLONG_MIN;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            //remainder of length...
            int rem= (i+1)%k;
            if(rem==0)
            {
                ans= max(ans,sum);
            }
            ans= max(ans,sum-mp[rem]);
            mp[rem]= min(mp[rem],sum);
        }
        return ans;
    }
};
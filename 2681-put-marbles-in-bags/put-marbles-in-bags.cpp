class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<long long>pairsum(n-1,0);
        for(int i=0;i<n-1;i++)
        {
            pairsum[i]= nums[i]+nums[i+1];
        }
        sort(pairsum.begin(),pairsum.end());
        long long minsum=0;
        long long maxsum=0;
        for(int i=0;i<k-1;i++)
        {
            minsum+= pairsum[i]; 
            maxsum+= pairsum[n-i-2]; 
        }
        return maxsum-minsum;
    }

};
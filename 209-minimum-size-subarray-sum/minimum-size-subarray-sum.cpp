class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) 
    {
        int n= nums.size();
        int l=0,r=0,sum=0;
        int ans=n+1;//why not n? as we have a valid subbarray of length n==> then return n not 0 
        while(r<n)
        {
            sum+= nums[r];
            while(l<=r && sum>=k)
            {
                ans= min(ans,r-l+1);
                sum-= nums[l];
                l++;
            }
            r++;
        }
        return ans==n+1? 0:ans;
    }
};
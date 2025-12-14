class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int ans=0,zeros=0,l=0;
        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
            {
                zeros++;
            }
            while(zeros>k)
            {
                if(nums[l]==0)
                {
                    zeros--;
                }
                l++;
            }
            if(zeros<=k)
            {
                ans= max(ans, r-l+1);
            }
        }
        return ans;
    }
};
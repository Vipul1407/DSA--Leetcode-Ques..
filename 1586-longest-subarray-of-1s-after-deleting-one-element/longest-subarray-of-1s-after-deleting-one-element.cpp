class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int k=1;
        int n= nums.size();
        int l=0,r=0,ans=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                k--;
            }
            while(l<r && k<0)
            {
                if(nums[l]==0)
                {
                    k++;
                }
                l++;
            }
            if(k>=0)
            {
                ans= max(ans,r-l);//becoz we not need to count 0
            }
            r++;
        }
        return ans==n? ans-1:ans;
    }
};
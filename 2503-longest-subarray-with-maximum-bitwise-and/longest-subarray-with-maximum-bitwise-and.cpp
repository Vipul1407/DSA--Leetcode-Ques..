class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int streak=0;//to find max contigous occurrence of same number..
        int maxi=0;
        int ans=0;//to find max length of longest subarray
        for(auto i:nums)
        {
            if(i>maxi)
            {
                maxi=i;
                streak=1;
                ans=1;//reset ans to 1 
            }
            else if(maxi==i)
            {
                streak++;
            }
            //element small h mtlb no contribution to ans so its streak=0
            else
            {
                streak=0;
            }
            ans= max(ans,streak);
        }
        return ans;
    }
};
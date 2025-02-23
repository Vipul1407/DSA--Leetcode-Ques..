class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int n= nums.size();
        int inc=1;
        int maxinc=1;
        int dec=1;
        int maxdec=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                inc++;
                dec=1;
                maxinc= max(maxinc,inc);
            }
            else if(nums[i]>nums[i+1])
            {
                dec++;
                inc=1;
                maxdec= max(maxdec,dec);
            }
            else
            {
                inc=1;
                dec=1;
            }
        }
        return max(maxdec,maxinc);
    }
};
class Solution {
public:
    //METHOD-2
    //Prefix Approach
    int longestSubarray(vector<int>& nums) 
    {
        int curr=0,prev=-1,ans=0;
        int n= nums.size();
        for(auto i:nums)
        {
            if(i==1)
            {
                curr++;
            }
            else
            {
                if(prev==-1)
                {
                    ans= max(ans,curr);
                }
                else
                {
                    ans= max(ans,prev+curr);
                }
                prev= curr;
                curr=0;
            }
        }
        //update at last..
        ans= max(ans,prev+curr);
        return ans==n? ans-1:ans;
    }
};
/*
    //METHOD-1
    //Sliding Window
    // Same as Maximum Consecutive ones iii for K=1.
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
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) 
    {
        long long ans=0;
        int n= nums.size();
        int mink_idx=-1;
        int maxk_idx=-1;
        int culprit= -1;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxk || nums[i]<mink)
            {
                culprit=i;
            }
            if(nums[i]== mink)
            {
                mink_idx= i;
            }
            if(nums[i]== maxk)
            {
                maxk_idx= i;
            }
            long long temp= min(mink_idx, maxk_idx)- culprit;
            ans+= (temp<0)? 0:temp;
        }
        return ans;
    }
};
class Solution {
public:
    //OPTIMIZED APPROACH..
    //KADANE ALGO..
    int maxSubArray(vector<int>& nums) 
    {
        int ans=INT_MIN;
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
            ans= max(ans,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return ans;
    }
};
class Solution {
public:
    //KADANE ALGO..
    //OPTIMIZED..
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int positive_sum=0;
        int negative_sum=0;
        int ans= INT_MIN;
        for(auto i:nums)
        {
            positive_sum+= i;
            negative_sum+= i;
            ans= max(ans,max(abs(positive_sum),abs(negative_sum)));
            if(positive_sum<0)
            {
                positive_sum=0;
            }
            if(negative_sum>0)
            {
                negative_sum=0;
            }
        }
        return ans;
    }
};
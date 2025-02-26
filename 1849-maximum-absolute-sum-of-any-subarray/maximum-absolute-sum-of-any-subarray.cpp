class Solution {
public:
    //OPTIMIZED APPROACH..
    //KADANE ALGO..
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int ans= INT_MIN;
        int positive=0;
        int negative=0;

        for(auto i:nums)
        {
            positive+= i;
            negative+= i;
            ans= max(ans,max(abs(positive),abs(negative)));
            if(positive<0)
            {
                positive=0;
            }
            if(negative>0)
            {
                negative=0;
            }
        }
        return ans;
    }
};  
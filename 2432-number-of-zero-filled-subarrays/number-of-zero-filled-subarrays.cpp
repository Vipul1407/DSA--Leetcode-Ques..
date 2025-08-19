class Solution {
public:
    //METHOD-1
    //NO. OF SUBARRAYS= n*(n+1)/2
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long ans=0;
        int prefix=0;
        for(auto i:nums)
        {
            if(i==0)
            {
                prefix++;
            }
            else
            {
                ans+= 1LL*prefix*(prefix+1)/2;
                prefix=0;
            }
        }
        ans+= 1LL*prefix*(prefix+1)/2;
        return ans;
    }
};
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) 
    {
        int n= nums.size();
        //max xor that we can get is by flipping the bits
        int xorvalue=0;
    
        vector<int>ans(n);
        int mask= (1<<mb)-1;
        //to get max result of xor when we xor the bits with its flip bits
        //now to get flip we will xor the bits with mask
        for(int i=0;i<n;i++)
        {
            xorvalue^=nums[i];
            ans[n-i-1]= xorvalue^mask;
        }
        return ans;
    }
};
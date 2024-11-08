class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) 
    {
        int n= nums.size();
        //max xor that we can get is by flipping the bits
        int xorvalue=0;
        for(auto i:nums)
        {
            xorvalue^=i;
        }
        vector<int>ans;
        int mask= (1<<mb)-1;
        //to get max result of xor when we xor the bits with its flip bits
        //now to get flip we will xor the bits with mask
        int idx=n-1;
        while(idx>=0)
        {
            ans.push_back(xorvalue^mask);
            xorvalue^=nums[idx];//to remove that element from its xor
            idx--;
        }
        return ans;
    }
};
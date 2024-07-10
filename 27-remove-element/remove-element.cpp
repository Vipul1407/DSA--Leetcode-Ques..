class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n=nums.size();
        int j=0;
        for(auto i:nums)
        {
            if(i!=val)
            {
                nums[j++]=i;
            }
        }
        return j;
    }
};
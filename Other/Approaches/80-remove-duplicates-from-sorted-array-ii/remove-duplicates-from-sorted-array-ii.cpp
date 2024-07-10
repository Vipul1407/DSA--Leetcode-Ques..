class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n= nums.size();
        int j=0;
        for(auto ele:nums)
        {
            if(j==0 || j==1 || nums[j-2]!=ele)
            {
                nums[j]= ele;
                j++;
            }
        }    
        return j;
    }
};
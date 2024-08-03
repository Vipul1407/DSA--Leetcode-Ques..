class Solution {
public:
    int minSwaps(vector<int>& nums)      
    {
        int n= nums.size();
        int total=0;
        for(auto i:nums)
        {
            if(i==1)
            {
                total++;
            }
        }    
        int ones=0;
        int maxones=0;
        int i=0;
        int j=0;
        while(j<2*n)
        {
            if(nums[j%n]==1)
            {
                ones++;
            }
            if(j-i+1>total)
            {
                if(nums[i%n]==1)
                {
                    ones--;
                }
                i++;
                maxones= max(ones, maxones);
            }
            j++;
        }
        return total-maxones;
    }
};
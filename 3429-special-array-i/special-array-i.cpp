class Solution {
public:
    //METHOD-2
    bool isArraySpecial(vector<int>& nums) 
    {
        int n= nums.size();
        for(int i=1;i<n;i++)
        {
            if((nums[i]+nums[i-1])%2==0)
            {
                return false;
            }
        }
        return true;
    }
};
/*
    //METHOD-1
    bool isArraySpecial(vector<int>& nums) 
    {
        int start=9;
        for(auto i:nums)
        {
            if(start==9)
            {
                start= i%2;
            }
            else
            {
                if(i%2==start)
                {
                    return false;
                }
                start=i%2;
            }
        }
        return true;
    }
*/
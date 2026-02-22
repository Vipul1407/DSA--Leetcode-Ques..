class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int one=0;
            for(auto n:nums)
            {
                if((n&(1<<i)))
                {
                    one++;
                }
            }
            if(one%3==1)
            {
                ans|= (1<<i);
            }
        }
        return ans;
    }
};
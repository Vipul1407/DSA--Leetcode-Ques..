class Solution {
public:
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
};
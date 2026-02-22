class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        //find xor..
        int _xor= 0;
        for(auto i:nums)
        {
            _xor^=i;
        }
        //xor=0 -> both have same bits
        //xor=1 -> both have diff bits

        //find mask=> only last set bit turned on..
        int n= _xor;
        int pos=0;
        while((n&1)==0)
        {
            n>>=1;
            pos++;
        }
        int mask= 1<<pos;

        //make diff buckets and xor them separately..
        int x=0,y=0;
        for(auto i:nums)
        {
            if(mask & i)
            {
                x^=i;
            }
            else
            {
                y^=i;
            }
        }
        return {x,y};
    }
};
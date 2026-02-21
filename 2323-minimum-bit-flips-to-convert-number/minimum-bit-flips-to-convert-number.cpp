class Solution {
public:
    // int setbits(int n)
    // {
    //     int cnt=0;
    //     while(n>0)
    //     {
    //         if(n&1)
    //         {
    //             cnt++;
    //         }
    //         n>>=1;
    //     }
    //     return cnt;
    // }
    int setbits(int n)
    {
        int cnt=0;
        for(int i=0;i<32;i++)
        {
            if(n & (1<<i))
            {
                cnt++;
            }
        }
        return cnt;
    }
    int minBitFlips(int start, int goal) 
    {
        int n= start^goal;
        return setbits(n);
    }
};
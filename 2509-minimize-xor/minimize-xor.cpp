class Solution {
public:
    //METHOD-2
    //Building Ans from 0
    int minimizeXor(int num1, int num2) 
    {
        int ans= 0;
        int cntneeded=0;//no. of set bits in num2

        //count set bits....in num2
        while(num2)
        {
            if(1 & num2)
            {
                cntneeded++;
            }
            num2>>=1;
        }
        //Ans must contains set bits from MSB and hence our xor will give min ans..
        for(int bit=31; bit>=0 && cntneeded>0 ;bit--)
        {
            if(num1 & (1<<bit))
            {
                ans|= (1<<bit);
                cntneeded--;
            }
        } 
        int bit=0;//initial bit position
        //if we need more set bit in ans then try to make LSB bits set.. 
        while(cntneeded>0)
        {
            if(!(num1 & (1<<bit)))
            {
                ans|= (1<<bit);
                cntneeded--;
            }
            bit++;
        }
        return ans;
    }
};
/*
// METHOD-1
// BEATS 100%
// Building Ans taking =num1
int minimizeXor(int num1, int num2)
{
    int ans = num1;    // we need xor min, hence take ans same as num1
    int bit = 0;       // initial bit position
    int cntneeded = 0; // no. of set bits in num2

    // count set bits....in num2
    while (num2)
    {
        if (1 & num2)
        {
            cntneeded++;
        }
        num2 >>= 1;
    }
    // count set bits....in num1
    int currcnt = 0; // no. of set bits in num1
    while (num1)
    {
        if (1 & num1)
        {
            currcnt++;
        }
        num1 >>= 1;
    }
    // we have to increase set bits...
    if (currcnt < cntneeded)
    {
        while (currcnt < cntneeded)
        {
            // if curr position p set bit ni h
            if (!(ans & (1 << bit)))
            {
                // set bit krde..
                ans |= (1 << bit);
                currcnt++;
            }
            bit++;
        }
    }
    // we have to decrease set bits...
    else if (currcnt > cntneeded)
    {
        while (currcnt > cntneeded)
        {
            // if curr position p set bit h
            if (ans & (1 << bit))
            {
                // unset krde..
                ans &= ~(1 << bit);
                currcnt--;
            }
            bit++;
        }
    }
    return ans;
}
*/
class Solution {
public:
    //METHOD-2
    int setbits(int n)
    {
        int cnt=0;
        while(n>0)
        {
            if(n&1)
            {
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
    bool isPowerOfTwo(int n) 
    {
        if(n<=0)
        {
            return false;
        }
        return setbits(n)==1 ? true:false;
    }
};
/*
    //METHOD-1
    bool isPowerOfTwo(int n) 
    {
        if(n<=0)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }
        return (n & n-1)==0;
        //it will give wrong ans becoz of ()
        // n & (n-1) == 0
    }
*/
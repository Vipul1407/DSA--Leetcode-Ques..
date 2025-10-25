class Solution {
public:
    //METHOD-2
    bool isPowerOfTwo(int n) 
    {
        if(n<=0)
        {
            return false;
        }
        while(n>1)
        {
            if(n%2!=0)
            {
                return false;
            }
            n/=2;
        }
        return true;
    }
};
/*
    //METHOD-1
    bool isPowerOfTwo(int n) 
    {
        if(n<=0)
        {
            return 0;
        }
        return (n & n-1) == 0;
    }
*/
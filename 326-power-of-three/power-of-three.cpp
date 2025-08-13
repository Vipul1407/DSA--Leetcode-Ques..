class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n<=0)
        {
            return false;
        }
        //1 is a power of 3..
        while(n>1)
        {
            if(n%3!=0)
            {
                return false;
            }
            n/=3;
        }    
        return true;//exact 1..
    }
};
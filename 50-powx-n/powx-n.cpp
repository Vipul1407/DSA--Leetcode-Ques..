class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n<0)
        {
            n= abs(n);
            x= 1/x;
        }
        double ans=1;
        while(n>0)
        {
            //if n is odd
            if(n%2==1)
            {
                ans*=x;
                n-=1;
            }
            //if n is even
            else
            {
                x*=x;
                n/=2;
            }
        }
        return ans;
    }
};
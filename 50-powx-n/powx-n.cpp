class Solution {
public:
    double myPow(double x, int n) 
    {
        double ans=1;
        int m=n;
        n= abs(n);
        while(n>0)
        {
            //poweer is odd
            if(n%2==1)
            {
                ans= ans*x;
                n=n-1;
            }
            //power is even
            else
            {
                x=x*x;
                n=n/2;  
            }
        }
        return m<0? 1/ans: ans; 
    }
};
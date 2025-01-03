class Solution {
public:
    double myPow(double x, int n) 
    {
        long long nn= abs(n);
        double ans=1;
        while(nn>0)
        {
            if(nn%2==1)
            {
                ans=ans*x;
                nn=nn-1;
            }
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }
        return (n<0)? 1/ans:ans;
    }
};